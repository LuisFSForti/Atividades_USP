//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 2 de ED3

#include "arvoreB.h"

//Dado utilizado para controlar o cabeçalho dos arquivos
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

void InserirRegistro(FILE* arq, long nome, long pos, int RRNatual)
{
    char folha;
    int qtdVal;
    long chaveAtual;
    int proxRRN = -1;
    int ultimoRRN = cabA.RRNproxNo;

    fseek(arq, (RRNatual + 1) * tamPagA, SEEK_SET);

    fread(&folha, sizeof(char), 1, arq);
    fread(&qtdVal, sizeof(int), 1, arq);
    fseek(arq, sizeof(int), SEEK_CUR);
    fseek(arq, sizeof(int), SEEK_CUR);

    int posVal;
    for(posVal = 0; i < qtdVal; i++)
    {
        fread(&chaveAtual, sizeof(long), 1, SEEK_CUR);

        if(chaveAtual == nome)
        {
            printf("Falha no processamento do arquivo.");
            return;
        }

        if(chaveAtual < nome)
        {
            if(!folha)
            {
                fseek(arq, -(sizeof(long) + sizeof(int)), SEEK_CUR);
                fread(&proxRRN, sizeof(int), 1, arq);
                InserirRegistro(arq, nome, pos, proxRRN);
                break;
            }
            else
                break;
        }
        else
        {
            fseek(arq, sizeof(long) + sizeof(int), SEEK_CUR);
        }
    }

    if(proxRRN == -1)
    {
        printf("Falha no processamento do arquivo.");
        return;
    }

    if(folha)
    {
        int P;
        long C, Pr;
        for(int i = qtdVal; i > posVal; i--)
        {
            //Posição do registro +
            //folha + nroChavesNo + RRNdoNo +
            //qtdVal * (Px + Cx + Prx)
            fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int) * 2 + i * (sizeof(int) + sizeof(long)*2), SEEK_SET);
            fread(&P, sizeof(int), 1, arq);
            fread(&C, sizeof(long), 1, arq);
            fread(&Pr, sizeof(long), 1, arq);

            fwrite(&P, sizeof(int), 1, arq);
            fwrite(&C, sizeof(long), 1, arq);
            fwrite(&Pr, sizeof(long), 1, arq);
        }

        //Posição do registro +
        //folha + nroChavesNo + RRNdoNo +
        //qtdVal * (Px + Cx + Prx)
        fseek(arq, (RRNatual + 1) * tamPagA + sizeof(char) + sizeof(int) * 2 + posVal * (sizeof(int) + sizeof(long)*2), SEEK_SET);

        int temp = -1;
        fwrite(&temp, sizeof(int), 1, arq);
        fwrite(&nome, sizeof(long), 1, arq);
        fwrite(&pos, sizeof(long), 1, arq);
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
