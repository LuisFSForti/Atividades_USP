//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 2 de ED3

#include "arvoreB.h"

//Dado utilizado para controlar o cabeçalho dos arquivos dos dinossauros
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

//Escreve o cabeçalho salvo em cabA (apenas chamado pelo CriarArquivo e o FecharArquivo)
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
    //Cria um arquivo no modo de escrita binária
    FILE* arq = fopen(endereco, "wb");

    //Se deu erro
    if(arq == NULL)
    {
        //Alerta e sai
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Garante que o arquivo estará escrito como inconsistente
    cabA.status = 0;

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
    if(cabA.status == 0)
    {
        //Fecha o arquivo, alerta e sai
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Atualiza que o arquivo está inconsistente
    cabA.status = 0;
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

Dado InserirRegistro(FILE* arq, Dado input, int RRNatual)
{
    Dado dado;
    dado.chave = -1;
    dado.pos = -1;

    if(cabA.noRaiz == -1)
    {
        printf("Falha no processamento do arquivo.");
        return dado;
    }

    if(RRNatual == -1)
    {
        return dado;
    }

    char folha;
    int qtdVal;
    long chaveAtual;
    int proxRRN = -1;
    int ultimoRRN = cabA.RRNproxNo;

    //Algumas variáveis para auxiliar
    int auxI = 1, auxIN = -1;
    long auxL = 1, auxLN = -1;

    fseek(arq, (RRNatual + 1) * tamPagA, SEEK_SET);

    fread(&folha, sizeof(char), 1, arq);
    fread(&qtdVal, sizeof(int), 1, arq);
    fseek(arq, sizeof(int) * 2, SEEK_CUR);

    int posVal;
    for(posVal = 0; posVal < qtdVal; posVal++)
    {
        fread(&chaveAtual, sizeof(long), 1, arq);

        if(chaveAtual == input.chave)
        {
            printf("Falha no processamento do arquivo.");
            return dado;
        }

        printf("%li %li %d - ", input.chave, chaveAtual, RRNatual);
        if(input.chave < chaveAtual)
        {
            if(folha == '0')
            {
                fseek(arq, -(sizeof(long) + sizeof(int)), SEEK_CUR);
                fread(&proxRRN, sizeof(int), 1, arq);
                printf("A %d %d\n", qtdVal, proxRRN);
                dado = InserirRegistro(arq, input, proxRRN);
                break;
            }
            else
            {
                dado.chave = 0;
                break;
            }
        }
        else
        {
            if(posVal != qtdVal-1)
                fseek(arq, sizeof(long) + sizeof(int), SEEK_CUR);
            else
            {
                if(folha == '0')
                {
                    fseek(arq, sizeof(long), SEEK_CUR);
                    fread(&proxRRN, sizeof(int), 1, arq);
                    printf("B %d %d\n", qtdVal, proxRRN);
                    dado = InserirRegistro(arq, input, proxRRN);
                    break;
                }
                else
                {
                    dado.chave = 0;
                    break;
                }
            }
        }
    }

    //Se não foi passado um dado do braço acima e não é uma folha
    if(dado.chave == -1)
        //Sai
        return dado;

    printf("\n\n%li %li %li\n\n", chaveAtual, input.chave, input.pos);

    //Se há espaço
    if(qtdVal < 4)
    {
        if(folha == '1')
            dado = input;

        int P;
        long C, Pr;

        printf("\n\n\n%li %d %d", dado.pos, RRNatual, posVal);

        //Para mover o ponteiro mais à direita
        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int)*2 +
        (qtdVal) * (sizeof(int) + sizeof(long)*2), SEEK_SET);
        fread(&P, sizeof(int), 1, arq);
        fseek(arq, sizeof(long)*2, SEEK_CUR);
        fwrite(&P, sizeof(int), 1, arq);

        for(int i = qtdVal; i > posVal; i--)
        {
            //Coloca no começo do dado
            fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int)*2 + (i-1) * (sizeof(int) + sizeof(long)*2), SEEK_SET);

            fread(&P, sizeof(int), 1, arq);
            fread(&C, sizeof(long), 1, arq);
            fread(&Pr, sizeof(long), 1, arq);

            fwrite(&P, sizeof(int), 1, arq);
            fwrite(&C, sizeof(long), 1, arq);
            fwrite(&Pr, sizeof(long), 1, arq);
        }

        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int)*2 + (posVal) * (sizeof(int) + sizeof(long)*2), SEEK_SET);

        fwrite(&auxIN, sizeof(int), 1, arq);
        fwrite(&dado.chave, sizeof(long), 1, arq);
        fwrite(&dado.pos, sizeof(long), 1, arq);

        qtdVal++;
        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char), SEEK_SET);
        fwrite(&qtdVal, sizeof(int), 1, arq);

        dado.chave = -1;
        dado.pos = -1;
        return dado;
    }
}

long EncontrarRegistro(FILE* arq, long chave)
{
    int rrnAtual = cabA.noRaiz;
    int nroNos = 0;
    long chaveAtual = 0;
    long res = -1;

    while(1)
    {
        if(rrnAtual == -1)
            return res;

        fseek(arq, (rrnAtual + 1) * tamPagA + 1, SEEK_SET);
        fread(&nroNos, sizeof(int), 1, arq);

        //Pula o primeiro ponteiro e o RRN do registro
        fseek(arq, sizeof(int)*2, SEEK_CUR);

        int i;
        for(i = 0; i < nroNos; i++)
        {
            fread(&chaveAtual, sizeof(long), 1, arq);

            if(chave == chaveAtual)
            {
                fread(&res, sizeof(long), 1, arq);
                return res;
            }
            if(chave < chaveAtual)
            {
                fseek(arq, -(sizeof(long) + sizeof(int)), SEEK_CUR);
                fread(&rrnAtual, sizeof(int), 1, arq);
                break;
            }
            else
            {
                if(i == nroNos-1)
                {
                    fseek(arq, sizeof(long), SEEK_CUR);
                    fread(&rrnAtual, sizeof(int), 1, arq);
                    break;
                }

                fseek(arq, sizeof(long) + sizeof(int), SEEK_CUR);
            }
        }
    }
}

void SelectArvore(char* enderecoDados, char* enderecoArvore, char* nomeDino)
{
    FILE* arqArvore = AbrirArquivoArvore(enderecoArvore);

    //Se deu erro
    if(arqArvore == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    long pos = EncontrarRegistro(arqArvore, converteNome(nomeDino));

    FecharArquivoArvore(arqArvore);

    if(pos == -1)
    {
        printf("Registro inexistente.");
        return;
    }

    FILE* arqDino = AbrirArquivo(enderecoDados);

    //Se deu erro
    if(arqDino == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    fseek(arqDino, pos, SEEK_SET);
    Dinossauro dino = CriaDinossauroBin(arqDino);
    ImprimeDinossauro(dino);
    LiberaDinossauro(dino);

    FecharArquivo(arqDino);
}

void InserirDados(int qtd, char* enderecoDados, char* enderecoArvore)
{
    //Abre o arquivo lendo o cabeçalho
    FILE* arq = AbrirArquivo(enderecoDados);
    FILE* arqA = AbrirArquivoArvore(enderecoArvore);

    //Se deu erro
    if(arq == NULL || arqA == NULL)
    {
        //Sai pois o erro foi avisado em AbrirArquivo
        return;
    }

    //string auxiliar
    char* aux = calloc(200, sizeof(char));
    //Dinossauro para armazenar os dados
    Dinossauro dino = CriaDinossauro();

    //Dado
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
            dado.pos = 1600 + 160 * cab.topo;

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
            dado.pos = 1600 + 160 * cab.proxRRN;

            //Se começará uma nova página
            if(cab.proxRRN % 10 == 0)
                //Define que há uma nova página
                cab.nroPagDisco++;

            //Define que o último registro tem um RRN maior
            cab.proxRRN++;
        }

        //Salva o novo registro no local definido
        SalvarRegistro(dino, arq);

        dado.chave = converteNome(dino.nome);
        dado.pos = ftell(arq);
        printf("\n\n\n%s\n\n\n", dino.nome);
        InserirRegistro(arqA, dado, cabA.noRaiz);

        //Libera o espaço alocado e cria um novo dino nulo
        LiberaDinossauro(dino);
        dino = CriaDinossauro();
    }
    //Libera os espaços alocados
    free(aux);
    LiberaDinossauro(dino);

    //Fecha o arquivo, atualizando o cabeçário
    FecharArquivo(arq);
    FecharArquivoArvore(arqA);
    //Função de verificação do projeto
    binarioNaTela(enderecoArvore);
}
