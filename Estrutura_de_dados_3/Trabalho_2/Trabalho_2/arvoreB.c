//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 2 de ED3

#include "arvoreB.h"

//Dado utilizado para controlar o cabeçalho dos arquivos dos dinossauros
//Em controlador.c existe o mesmo dado, mas ele foi declarado como extern
//Então o compilador usa ambos os objetos pra mesma instância
//TLDR: este cab é o mesmo do controlador.c
Cabecalho cab;

//Dado utilizado para controlar o cabeçalho dos arquivos dos indíces
CabecalhoArvore cabA;

//Lê o cabeçalho (apenas chamado pelo AbrirArquivo)
void LerCabecalhoArvore(FILE *arq)
{
    //Volta para o começo do arquivo
    fseek(arq, 0, SEEK_SET);

    //Lê os dados do cabeçalho
    fread(&cabA.status, sizeof(char), 1, arq);
    fread(&cabA.noRaiz, sizeof(int), 1, arq);
    fread(&cabA.RRNproxNo, sizeof(int), 1, arq);
}

//Escreve o cabeçalho salvo em cabA
void EscreverCabecalhoArvore(FILE *arq, char jaExiste)
{
    //if jaExiste == 1 (true)
    if(jaExiste == 1)
        //Volta para o começo do arquivo
        fseek(arq, 0, SEEK_SET);

    //Escreve os dados do cabeçalho
    fwrite(&cabA.status, sizeof(char), 1, arq);
    fwrite(&cabA.noRaiz, sizeof(int), 1, arq);
    fwrite(&cabA.RRNproxNo, sizeof(int), 1, arq);
}

//Cria um arquivo com cabeçalho no endereço passado
FILE* CriarArquivoArvore(char* endereco)
{
    //Cria um arquivo no modo de escrita binária, assim criando o arquivo
    FILE* arq = fopen(endereco, "wb+");

    //Se deu erro
    if(arq == NULL)
    {
        //Alerta e sai
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Garante que o arquivo estará escrito como inconsistente
    cabA.status = '0';

    //Escreve o cabeçalho salvo em cabA
    EscreverCabecalhoArvore(arq, 0);
    //Preenche o restante da página com o caracter de lixo
    for(int i = 0; i < tamPagA - (1 + 4 + 4); i++)
        fwrite("$", sizeof(char), 1, arq);

    return arq;
}

//Cria um arquivo no endereço passado e lê o cabeçalho
FILE* AbrirArquivoArvore(char* endereco)
{
    //Abre o arquivo no modo de leitura e escrita binária
    FILE* arq = fopen(endereco, "rb+");

    //Se deu erro
    if(arq == NULL)
    {
        //Alerta e sai
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Lê o cabeçalho
    LerCabecalhoArvore(arq);

    //Se o arquivo está inconsistente
    if(cabA.status == '0')
    {
        //Fecha o arquivo, alerta e sai
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Atualiza que o arquivo está inconsistente
    cabA.status = '0';
    fseek(arq, 0, SEEK_SET);
    fwrite(&cabA.status, sizeof(char), 1, arq);

    //Avança para o fim da página do cabeçalho
    fseek(arq, tamPagA, SEEK_SET);

    return arq;
}

//Fecha o arquivo no endereço passado e atualiza o cabeçalho
void FecharArquivoArvore(FILE* arq)
{
    //Define que o arquivo será fechado com êxito
    cabA.status = '1';

    //Atualiza o cabeçalho
    EscreverCabecalhoArvore(arq, 1);

    //Fecha o arquivo
    fclose(arq);
}

void CriarRaiz(FILE* arq, Dado input)
{
    //Variáveis auxiliares para a criação da raíz
    char raizFolha = '1';
    int raizQtd = 1, raizRRN = 0;
    long auxL = -1;

    //Pula pra depois do cabeçalho
    fseek(arq, tamPagA, SEEK_SET);
    //Escreve as informações básicas da raíz
    fwrite(&raizFolha, sizeof(char), 1, arq);
    fwrite(&raizQtd, sizeof(int), 1, arq);
    fwrite(&raizRRN, sizeof(int), 1, arq);

    //Define o primeiro ponteiro como nulo
    fwrite(&input.pontD, sizeof(int), 1, arq);

    //Primeiro dado
    fwrite(&input.chave, sizeof(long), 1, arq);
    fwrite(&input.pos, sizeof(long), 1, arq);
    fwrite(&input.pontD, sizeof(int), 1, arq);

    //Neutraliza os demais dados do registro
    for(int i = 1; i < qtdValReg; i++)
    {
        fwrite(&auxL, sizeof(long), 1, arq);
        fwrite(&auxL, sizeof(long), 1, arq);
        fwrite(&input.pontD, sizeof(int), 1, arq);
    }


    //Atualiza os dados do cabeçalho
    cabA.noRaiz = 0;
    cabA.RRNproxNo = 1;
}

Dado EncontrarPosicaoInsercao(FILE* arq, Dado input, int RRNatual, char folha, int qtdVal, int proxRRN, int* ret)
{
    //Onde será inserido
    int posVal;
    ret = &posVal;

    long chaveAtual;
    Dado dado;
    dado.chave = -1;
    dado.pos = -1;
    dado.pontD = -1;

    //Para cada dado no registro
    for(posVal = 0; posVal < qtdVal; posVal++)
    {
        //Lê a chave do dado atual
        fread(&chaveAtual, sizeof(long), 1, arq);

        //Se a chave for igual a chave à ser inserida
        //Um erro, pois não podem ter chaves repetidas
        if(chaveAtual == input.chave)
        {
            //Alerta o erro e retorna o dado nulo
            printf("Falha no processamento do arquivo.");
            return dado;
        }

        //Se a chave à ser isnerida for menor que a chave atual
        if(input.chave < chaveAtual)
        {
            //Se não for uma folha
            //Então ele pode receber um dado do seu filho, no caso de promoção
            if(folha == '0')
            {
                //Pega o ponteiro à esquerda do dado
                fseek(arq, -(sizeof(long) + sizeof(int)), SEEK_CUR);
                fread(&proxRRN, sizeof(int), 1, arq);
                //Chama a função com o próximo RRN, salvando qualquer dado retornado
                dado = InserirDado(arq, input, proxRRN);
                //Encerra o loop de procura
                break;
            }
            //Se for uma folha
            else
            {
                //Salva que deve inserir o dado
                dado.chave = -2;
                //Encerra o loop de procura
                break;
            }
        }
        //Se for maior que a chave atual
        else
        {
            //Se não tiver visto todos os dados do registro
            if(posVal != qtdVal-1)
                //Avança para o próximo
                fseek(arq, sizeof(long) + sizeof(int), SEEK_CUR);
            //Se já olhou todos os dados
            else
            {
                //Se não for uma folha
                //Então ele pode receber um dado do seu filho, no caso de promoção
                if(folha == '0')
                {
                    //Pega o ponteiro à direita
                    fseek(arq, sizeof(long), SEEK_CUR);
                    fread(&proxRRN, sizeof(int), 1, arq);
                    //Chama a função com o próximo RRN, salvando qualquer dado retornado
                    dado = InserirDado(arq, input, proxRRN);
                }
                //Se for uma folha
                else
                {
                    //Salva que deve inserir o dado
                    dado.chave = -2;
                }
            }
        }
    }
}

//Para inserir um dado na árvore
Dado InserirDado(FILE* arq, Dado input, int RRNatual)
{
    //Dado auxiliar da função
    Dado dado;
    //Neutraliza os valores
    dado.chave = -1;
    dado.pos = -1;
    dado.pontD = -1;

    //Se não tiver uma raiz
    if(cabA.noRaiz == -1)
    {
        //Cria a raíz inicial
        CriarRaiz(arq, input);
        //Encerra a função
        return dado;
    }

    //Se o rrn não é válido, um erro
    if(RRNatual == -1)
    {
        //Avisa o erro
        printf("Falha no processamento do arquivo.");
        //Retorna o dado nulo
        return dado;
    }

    //Variáveis auxiliares
    char folha;
    int qtdVal;
    long chaveAtual;
    int proxRRN = -1;

    //Valores nulos auxiliares
    int auxI = 1, auxIN = -1;
    long auxL = 1, auxLN = -1;

    //Avança pro começo do registro atual
    fseek(arq, (RRNatual + 1) * tamPagA, SEEK_SET);

    //Lê os dados
    fread(&folha, sizeof(char), 1, arq);
    fread(&qtdVal, sizeof(int), 1, arq);
    //Pula o rrn do registro e o primeiro ponteiro
    fseek(arq, sizeof(int) * 2, SEEK_CUR);

    //Onde o dado deve ser inserido no registro
    int posVal;

    //Qual dado deve ser inserido
    //Se a chave for -1, nada deve ser inserido
    //Se a chave for -2, deve inserir o input
    //Se a chave for diferente, deve inserir o dado retornado
    dado = EncontrarPosicaoInsercao(arq, input, RRNatual, folha, qtdVal, proxRRN, &posVal);

    //Se não foi passado um dado do braço acima ou não achou onde inserir
    if(dado.chave == -1)
        //Sai
        return dado;

    //Se for uma folha
    if(folha == '1')
        //Então o dado a inserir é o input
        dado = input;

    //Se há espaço no registro
    if(qtdVal < qtdValReg)
    {
        //Dado auxiliar para mover os dados
        Dado dadoAux;

        //Do último dado do registro até a posição onde deve isnerir
        for(int i = qtdVal; i > posVal; i--)
        {
            //Coloca no começo do dado
            //(RRNAtual + 1) * tamPagA = início do registro
            //sizeof(char) = caractere de folha
            //sizeof(int) * 3 = quantidade de dados, rrn do registro e o primeiro ponteiro
            //(i - 1) * (sizeof(int) + sizeof(long)*2) = espaço total dos dados anteriores
            fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int)*3 +
                        (i-1) * (sizeof(int) + sizeof(long)*2), SEEK_SET);

            //Lê a chave, a posição e o ponteiro da direita dele
            fread(&dadoAux.chave, sizeof(long), 1, arq);
            fread(&dadoAux.pos, sizeof(long), 1, arq);
            fread(&dadoAux.pontD, sizeof(int), 1, arq);

            //Escreve as mesmas informações, movendo o dado uma posição para a direita
            fwrite(&dadoAux.chave, sizeof(long), 1, arq);
            fwrite(&dadoAux.pos, sizeof(long), 1, arq);
            fwrite(&dadoAux.pontD, sizeof(int), 1, arq);
        }

        //Coloca no começo do dado
        //(RRNAtual + 1) * tamPagA = início do registro
        //sizeof(char) = caractere de folha
        //sizeof(int) * 3 = quantidade de dados, rrn do registro e o primeiro ponteiro
        //posVal * (sizeof(int) + sizeof(long)*2) = espaço total dos dados anteriores
        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int)*3 +
                    posVal * (sizeof(int) + sizeof(long)*2), SEEK_SET);

        //Escreve as informações do dado à ser inserido
        fwrite(&dado.chave, sizeof(long), 1, arq);
        fwrite(&dado.pos, sizeof(long), 1, arq);
        fwrite(&dado.pontD, sizeof(int), 1, arq);

        //Aumenta a quantidade de valores do registro
        qtdVal++;
        //Avança para a posição correta e escreve a quantidade de dados no registro
        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char), SEEK_SET);
        fwrite(&qtdVal, sizeof(int), 1, arq);

        //Neutraliza o dado, pois o processo de inserção acabou
        dado.chave = -1;
        dado.pos = -1;
        //Retorna o dado neutralizado
        return dado;
    }
    //Se não tiver espaço para a inserção
    else
    {
        //Para organizar a inserção dos dados
        Dado ordem[5];
        //Atualiza a quantidade de valores, pois definirá o registro atual e o novo
        qtdVal = 2;

        //Coloca no começo do primeiro dado
        //(RRNAtual + 1) * tamPagA = início do registro
        //sizeof(char) = caractere de folha
        //sizeof(int) * 3 = quantidade de dados, rrn do registro e o primeiro ponteiro
        fseek(arq, (RRNatual+1) * tamPagA + sizeof(char) + sizeof(int)*3, SEEK_SET);

        //Define a ordem dos dados
        //Como vai ter um dado à mais que o limite, i <= qtdValReg
        for(int i = 0; i <= qtdValReg; i++)
        {
            //Se for a posição de inserção
            if(i == posVal)
            {
                //Salva o dado na posição correta sem mexer no arquivo
                ordem[i] = dado;
            }
            else
            {
                //Salva o dado atual do registro na posição correta
                //Como o dado de inserção não interferiu com o arquivo,
                //então o cursor não pula nenhum dado
                fread(&ordem[i].chave, sizeof(long), 1, arq);
                fread(&ordem[i].pos, sizeof(long), 1, arq);
                fread(&ordem[i].pontD, sizeof(int), 1, arq);
            }
        }

        //Avança para o novo registro
        fseek(arq, (cabA.RRNproxNo+1) * tamPagA, SEEK_SET);

        //Dados básicos do registro
        fwrite(&folha, sizeof(char), 1, arq);
        fwrite(&qtdVal, sizeof(int), 1, arq);
        fwrite(&cabA.RRNproxNo, sizeof(int), 1, arq);

        //Primeiro ponteiro da esquerda do novo registro é o da direita do dado do meio
        fwrite(&ordem[2].pontD, sizeof(int), 1, arq);

        //Para inserir os dados
        for(int i = 3; i < qtdValReg + 3; i++)
        {
            //Para inserir os dois dados finais do antigo registro
            if(i < 5)
            {
                //Escreve os dados respectivos
                fwrite(&ordem[i].chave, sizeof(long), 1, arq);
                fwrite(&ordem[i].pos, sizeof(long), 1, arq);
                fwrite(&ordem[i].pontD, sizeof(int), 1, arq);
            }
            else
            {
                //Escreve valores neutros para os dados seguintes
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxIN, sizeof(int), 1, arq);
            }
        }

        //Volta pro começo do registro atual, pulando o caractere de folha
        fseek(arq, (RRNatual+1) * tamPagA + sizeof(char), SEEK_SET);
        //Atualiza a quantidade de registros
        fwrite(&qtdVal, sizeof(int), 1, arq);
        //Pula o campo do rrn do registro e o primeiro ponteiro
        fseek(arq, sizeof(int) * 2, SEEK_CUR);

        //Reescreve o registro, atualizando-o
        for(int i = 0; i < qtdValReg; i++)
        {
            //Escreve os dois primeiro registros
            if(i < 2)
            {
                fwrite(&ordem[i].chave, sizeof(long), 1, arq);
                fwrite(&ordem[i].pos, sizeof(long), 1, arq);
                fwrite(&ordem[i].pontD, sizeof(int), 1, arq);
            }
            //Neutraliza os demais
            else
            {
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxIN, sizeof(int), 1, arq);
            }
        }

        //Se não for a raiz
        if(RRNatual != cabA.noRaiz)
        {
            //Atualiza para quem o ponteiro do meio deve apontar, que é o novo registro
            ordem[2].pontD = cabA.RRNproxNo;
            //Atualiza qual é o novo último registro
            cabA.RRNproxNo++;
            //Retorna o dado que deve ser inserido no registro anterior
            return ordem[2];
        }
        //Se for a raíz
        else
        {
            //Atualiza para quem o ponteiro do meio deve apontar, que é o novo registro
            ordem[2].pontD = cabA.RRNproxNo;
            //Atualiza qual é o novo último registro
            cabA.RRNproxNo++;

            //Escreve os dados básicos do registro da nova raíz
            fseek(arq, (cabA.RRNproxNo + 1) * tamPagA, SEEK_SET);
            folha = '0';
            fwrite(&folha, sizeof(char), 1, arq);
            fwrite(&auxI, sizeof(int), 1, arq);
            fwrite(&cabA.RRNproxNo, sizeof(int), 1, arq);

            //Salva que o primeiro ponteiro aponta para a antiga raíz
            fwrite(&cabA.noRaiz, sizeof(int), 1, arq);

            //Escreve as informações do dado do meio da antiga raíz
            fwrite(&ordem[2].chave, sizeof(long), 1, arq);
            fwrite(&ordem[2].pos, sizeof(long), 1, arq);
            fwrite(&ordem[2].pontD, sizeof(int), 1, arq);

            //Escreve mais 3 dados neutros
            for(int i = 1; i < qtdValReg; i++)
            {
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxLN, sizeof(long), 1, arq);
                fwrite(&auxIN, sizeof(int), 1, arq);
            }

            //Atualiza a nova raíz e o novo próximo rrn
            cabA.noRaiz = cabA.RRNproxNo;
            cabA.RRNproxNo++;

            //Retorna dado, independente de como esteja, pois este é o primeiro chamado da recursão
            //afinal de contas, este é o chamado da raíz
            return dado;
        }
    }
}

//Para encontrar
long EncontrarDado(FILE* arq, long chave)
{
    //Começa a pesquisa pela raíz
    int rrnAtual = cabA.noRaiz;
    //Dados auxiliares
    int nroNos = 0;
    long chaveAtual = 0;
    long res = -1;

    //Loop infinito
    while(1)
    {
        //Se rrnAtual for -1, então não encontrou o registro,
        if(rrnAtual == -1)
            //Retorna uma posição inválida (-1)
            return res;

        //Avança para o começo do registro atual, pulando o caractere de folha
        fseek(arq, (rrnAtual + 1) * tamPagA + sizeof(char), SEEK_SET);
        //Lê a quantidade da dados no registro
        fread(&nroNos, sizeof(int), 1, arq);

        //Pula o RRN do registro e o primeiro ponteiro
        fseek(arq, sizeof(int)*2, SEEK_CUR);

        //Para cada dado do registro
        for(int i = 0; i < nroNos; i++)
        {
            //Lê a chave do dado
            fread(&chaveAtual, sizeof(long), 1, arq);

            //Se for igual à chave atual
            if(chave == chaveAtual)
            {
                //Pega a informação pos do dado
                fread(&res, sizeof(long), 1, arq);
                //Retorna a posição
                return res;
            }
            //Se for menor à chave atual
            if(chave < chaveAtual)
            {
                //Pega o ponteiro à esquerda do dado
                fseek(arq, -(sizeof(long) + sizeof(int)), SEEK_CUR);
                fread(&rrnAtual, sizeof(int), 1, arq);

                //Encerra o loop do registro atual
                break;
            }
            //Se for maior à chave atual
            else
            {
                //Se for o último dado do registro
                if(i == nroNos-1)
                {
                    //Pega o ponteiro à diretia
                    fseek(arq, sizeof(long), SEEK_CUR);
                    fread(&rrnAtual, sizeof(int), 1, arq);

                    //Encerra o loop do registro atual
                    break;
                }

                //Avança pro próximo dado do registro atual
                fseek(arq, sizeof(long) + sizeof(int), SEEK_CUR);
            }
        }
    }
}

//Cria a árvore com um arquivo de dados
void CreateArvore(char* enderecoDados, char* enderecoArvore)
{
    //Define os valores do cabeçalho
    cabA.noRaiz = -1;
    cabA.RRNproxNo = -1;
    cabA.status = '0';

    //Abre o arquivo de dados
    FILE* arqDados = AbrirArquivo(enderecoDados);

    //Se deu erro
    if(arqDados == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    FILE* arqArvore = CriarArquivoArvore(enderecoArvore);

    //Se deu erro
    if(arqArvore == NULL)
    {
        //Fecha o arquivo de dados, pois ele abriu corretamente
        FecharArquivo(arqDados);
        //Sai pois o erro foi avisado em CriarArquivoArvore
        return;
    }

    //Para manipulação dos dados
    Dinossauro dino;
    Dado dado;

    //Loop infinito
    while(1)
    {
        //Pega a posição do dado atual
        dado.pos = ftell(arqDados);

        //Lê o registro atual
        dino = CriaDinossauroBin(arqDados);

        //Se não conseguiu ler, então chegou no fim do arquivo
        if(dino.removido == 'E')
        {
            //Libera o espaço alocado
            LiberaDinossauro(dino);
            //Sai do loop
            break;
        }

        //Se o registro foi removido logicamente
        if(dino.removido == '1')
        {
            //Avança para o próximo registro
            fseek(arqDados, 159, SEEK_CUR);
            //Libera o dino
            LiberaDinossauro(dino);
            //Continua o loop
            continue;
        }

        //Pega a chave do nome do dinossauro atual
        dado.chave = converteNome(dino.nome);
        //Define que ele não terá ponteiro à direita, pois é uma nova inserção
        dado.pontD = -1;

        //Insere o registro na árvore, começando pela raíz
        InserirDado(arqArvore, dado, cabA.noRaiz);

        //Libera o dinossauro atual
        LiberaDinossauro(dino);
    }

    //Fecha os arquivos
    FecharArquivo(arqDados);
    FecharArquivoArvore(arqArvore);
    //Função de verificação do projeto
    binarioNaTela(enderecoArvore);
}

//Procura um dinossauro no arquivo de dados usando o arquivo de árvore
void SelectArvore(char* enderecoDados, char* enderecoArvore, char* nomeDino)
{
    //Abre o arquivo de árvore
    FILE* arqArvore = AbrirArquivoArvore(enderecoArvore);

    //Se deu erro
    if(arqArvore == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivoArvore
        return;
    }

    //Pega a posição do dado
    long pos = EncontrarDado(arqArvore, converteNome(nomeDino));

    //Fecha o arquivo de árovre
    FecharArquivoArvore(arqArvore);

    //Se for uma posição inválida
    if(pos == -1)
    {
        //Avisa e sai da função
        printf("Registro inexistente.");
        return;
    }

    //Abre o arquivo de dados
    FILE* arqDino = AbrirArquivo(enderecoDados);

    //Se deu erro
    if(arqDino == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    //Avança pra posição passada, o começo do registro
    fseek(arqDino, pos, SEEK_SET);
    //Cria um dinossauro com o arquivo
    Dinossauro dino = CriaDinossauroBin(arqDino);
    //Imprime o dinossauro
    ImprimeDinossauro(dino);
    //Libera o espaço alocado
    LiberaDinossauro(dino);

    //Fecha o arquivo do dinossauro
    FecharArquivo(arqDino);
}

//Para inserir dados nos arquivos
void InserirDados(int qtd, char* enderecoDados, char* enderecoArvore)
{
    //Abre o arquivo lendo o cabeçalho
    FILE* arq = AbrirArquivo(enderecoDados);

    //Se deu erro
    if(arq == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    //Abre o arquivo da árvore lendo o cabeçalho
    FILE* arqA = AbrirArquivoArvore(enderecoArvore);

    //Se deu erro
    if(arqA == NULL)
    {
        //Fecha o arquivo de dados
        FecharArquivo(arq);
        //Sai pois o erro foi avisado em AbrirArquivoArvore
        return;
    }

    //string auxiliar
    char* aux = calloc(200, sizeof(char));
    //Dinossauro para armazenar os dados
    Dinossauro dino = CriaDinossauro();

    //Dado auxiliar
    Dado dado;

    //Para cada registro à ser inserido
    for(int i = 0; i < qtd; i++)
    {
        //Para cada atributo do registro
        for(int j = 0; j < 10; j++)
        {
            //Lê o valor do atributo
            scan_quote_string(aux);
            //Se foi digitado NULO
            if(strcmp(aux, "") == 0)
                //Avança para o próximo atributo
                continue;

            //Para escolher qual atibuto definir
            switch(j)
            {
            case 0:
                strcpy(dino.nome, aux);
                break;
            case 1:
                strcpy(dino.dieta, aux);
                break;
            case 2:
                strcpy(dino.habitat, aux);
                break;
            case 3:
                dino.populacao = atoi(aux);
                break;
            case 4:
                strcpy(dino.tipo, aux);
                break;
            case 5:
                dino.velocidade = atoi(aux);
                break;
            case 6:
                dino.unidadeMedida = aux[0];
                break;
            case 7:
                dino.tamanho = atof(aux);
                break;
            case 8:
                strcpy(dino.especie, aux);
                break;
            case 9:
                strcpy(dino.alimento, aux);
                break;
            }
        }

        //Se um registro já foi removido logicamente
        if(cab.nroRegRem > 0)
        {
            //Pega o começo do atributo de encadeamento do último registro removido logicamente
            fseek(arq, 1600 + 160 * cab.topo + 1, SEEK_SET);

            //Pega o RRN do registro removido logicamente anterior
            fread(&cab.topo, sizeof(int), 1, arq);
            //Vai para o começo do registro
            fseek(arq, -5, SEEK_CUR);
            //Define que há um registro removido logicamente a menos
            cab.nroRegRem--;
        }
        else
        {
            //Pega o começo do registro a ser inserido no fim
            fseek(arq, 1600 + 160 * cab.proxRRN, SEEK_SET);

            //Se começará uma nova página
            if(cab.proxRRN % 10 == 0)
                //Define que há uma nova página
                cab.nroPagDisco++;

            //Define que o último registro tem um RRN maior
            cab.proxRRN++;
        }

        //Pega as informações do dado
        dado.chave = converteNome(dino.nome);
        dado.pos = ftell(arq);
        //Define que ele não terá um ponteiro à direita, pois é um dado novo
        dado.pontD = -1;

        //Salva o novo registro no local definido
        SalvarRegistro(dino, arq);

        //Salva o novo dado no local adequado
        InserirDado(arqA, dado, cabA.noRaiz);

        //Libera o espaço alocado e cria um novo dino nulo
        LiberaDinossauro(dino);
        dino = CriaDinossauro();
    }
    //Libera os espaços alocados
    free(aux);
    LiberaDinossauro(dino);

    //Fecha os arquivos, atualizando os cabeçalhos
    FecharArquivo(arq);
    FecharArquivoArvore(arqA);
    //Função de verificação do projeto
    binarioNaTela(enderecoArvore);
}
