//Luis Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 2 de ED3

#include "arvoreB.h"

//Dado utilizado para controlar o cabe�alho dos arquivos
CabecalhoArvore cabA;

//L� o cabe�alho (apenas chamado pelo AbrirArquivo)
void LerCabecalhoArvore(FILE *arq)
{
    //Volta para o come�o do arquivo
    fseek(arq, 0, SEEK_SET);

    //L� os dados do cabe�alho
    fread(&cabA.status, sizeof(char), 1, arq);
    fread(&cabA.noRaiz, sizeof(int), 1, arq);
    fread(&cabA.RRNproxNo, sizeof(int), 1, arq);
}

//Escreve o cabe�alho salvo em cabA (apenas chamado pelo CriarArquivo e o FecharArquivo)
void EscreverCabecalhoArvore(FILE *arq, char jaExiste)
{
    //if jaExiste == 1 (true)
    if(jaExiste == 1)
        //Volta para o come�o do arquivo
        fseek(arq, 0, SEEK_SET);

    //Escreve os dados do cabe�alho
    fwrite(&cabA.status, sizeof(char), 1, arq);
    fwrite(&cabA.noRaiz, sizeof(int), 1, arq);
    fwrite(&cabA.RRNproxNo, sizeof(int), 1, arq);
}

//Cria um arquivo com cabe�alho no endere�o passado
FILE* CriarArquivoArvore(char* endereco)
{
    //Cria um arquivo no modo de escrita bin�ria
    FILE* arq = fopen(endereco, "wb");

    //Se deu erro
    if(arq == NULL)
    {
        //Alerta e sai
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Escreve o cabe�alho salvo em cabA
    EscreverCabecalhoArvore(arq, 0);
    //Preenche o restante da p�gina com o caracter de lixo
    for(int i = 0; i < tamPagA - (1 + 4 + 4); i++)
        fwrite("$", sizeof(char), 1, arq);

    return arq;
}

//Cria um arquivo no endere�o passado e l� o cabe�alho
FILE* AbrirArquivoArvore(char* endereco)
{
    //Abre o arquivo no modo de leitura e escrita bin�ria
    FILE* arq = fopen(endereco, "rb+");

    //Se deu erro
    if(arq == NULL)
    {
        //Alerta e sai
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //L� o cabe�alho
    LerCabecalhoArvore(arq);

    if(cabA.status == 0)
    {
        //Fecha o arquivo, alerta e sai
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Avan�a para o fim da p�gina do cabe�alho
    fseek(arq, tamPagA, SEEK_SET);

    return arq;
}

//Fecha o arquivo no endere�o passado e atualiza o cabe�alho
void FecharArquivoArvore(FILE* arq)
{
    //Define que o arquivo ser� fechado com �xito
    cabA.status = '1';

    //Atualiza o cabe�alho
    EscreverCabecalhoArvore(arq, 1);

    //Fecha o arquivo
    fclose(arq);
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

        //Pula o primeiro ponteiro
        fseek(arq, sizeof(int), SEEK_CUR);

        for(int i = 0; i < nroNos; i++)
        {
            fread(&chaveAtual, sizeof(long), 1, arq);
            printf("%d %lu\n", rrnAtual, chaveAtual);
            if(chave == chaveAtual)
            {
                fread(&res, sizeof(long), 1, arq);
                return res;
            }
            if(chave < chaveAtual)
            {
                fseek(arq, -12, SEEK_CUR);
                fread(&rrnAtual, sizeof(long), 1, arq);
                break;
            }
            else
            {
                fseek(arq, 12, SEEK_CUR);
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

    if(pos == -1)
    {
        printf("Registro inexistente.");
    }

    printf("%lu", pos);

    FecharArquivoArvore(arqArvore);
}
