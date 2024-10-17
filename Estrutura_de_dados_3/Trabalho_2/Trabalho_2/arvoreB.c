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

    if(cabA.status == 0)
    {
        //Fecha o arquivo, alerta e sai
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

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
