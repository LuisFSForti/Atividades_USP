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

    //Garante que o arquivo estar� escrito como inconsistente
    cabA.status = 0;

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

    //Se o arquivo est� inconsistente
    if(cabA.status == 0)
    {
        //Fecha o arquivo, alerta e sai
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return NULL;
    }

    //Atualiza que o arquivo est� inconsistente
    cabA.status = 0;
    fseek(arq, 0, SEEK_SET);
    fwrite(&cabA.status, sizeof(char), 1, arq);

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
            //Posi��o do registro +
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

        //Posi��o do registro +
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
