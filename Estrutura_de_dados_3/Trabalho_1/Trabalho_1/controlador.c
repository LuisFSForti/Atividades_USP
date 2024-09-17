#include "controlador.h"

Cabecalho cab;

void LerCabecalho(FILE *arq)
{
    fseek(arq, 0, SEEK_SET);
    fread(&cab.status, sizeof(char), 1, arq);
    fread(&cab.topo, sizeof(int), 1, arq);
    fread(&cab.proxRRN, sizeof(int), 1, arq);
    fread(&cab.nroRegRem, sizeof(int), 1, arq);
    fread(&cab.nroPagDisco, sizeof(int), 1, arq);
    fread(&cab.qttCompacta, sizeof(int), 1, arq);
}

void EscreverCabecalho(FILE *arq, char naoEstaNoComeco)
{
    if(naoEstaNoComeco)
        fseek(arq, 0, SEEK_SET);

    fwrite(&cab.status, sizeof(char), 1, arq);
    fwrite(&cab.topo, sizeof(int), 1, arq);
    fwrite(&cab.proxRRN, sizeof(int), 1, arq);
    fwrite(&cab.nroRegRem, sizeof(int), 1, arq);
    fwrite(&cab.nroPagDisco, sizeof(int), 1, arq);
    fwrite(&cab.qttCompacta, sizeof(int), 1, arq);
}

FILE* CriarArquivo(char* endereco)
{
    FILE* arq = fopen(endereco, "wb");

    cab.status = '0';
    cab.topo = -1;
    cab.proxRRN = 0;
    cab.nroRegRem = 0;
    cab.nroPagDisco = 1;
    cab.qttCompacta = 0;

    EscreverCabecalho(arq, 0);
    for(int i = 0; i < 1579; i++)
        fwrite("$", sizeof(char), 1, arq);

    return arq;
}

FILE* AbrirArquivo(char* endereco)
{
    FILE* arq = fopen(endereco, "rb+");

    LerCabecalho(arq);

    fseek(arq, 1600, SEEK_SET);

    return arq;
}

void FecharArquivo(FILE* arq, char* endereco)
{
    cab.status = '1';
    fclose(arq);

    arq = fopen(endereco, "rb+");
    EscreverCabecalho(arq, 1);
    fclose(arq);
}

void SalvarRegistro(Dinossauro dino, FILE* arq)
{
    fwrite("0", sizeof(char), 1, arq);

    int temporario = -1;
    fwrite(&temporario, sizeof(int), 1, arq);

    fwrite(&dino.populacao, sizeof(int), 1, arq);
    fwrite(&dino.tamanho, sizeof(int), 1, arq);
    fwrite(&dino.unidadeMedida, sizeof(char), 1, arq);
    fwrite(&dino.velocidade, sizeof(int), 1, arq);

    int bytesOcupados = sizeof(char) * 2 + sizeof(int) * 4;

    bytesOcupados += SalvarStringRegistro(dino.nome, arq);
    bytesOcupados += SalvarStringRegistro(dino.especie, arq);
    bytesOcupados += SalvarStringRegistro(dino.habitat, arq);
    bytesOcupados += SalvarStringRegistro(dino.tipo, arq);
    bytesOcupados += SalvarStringRegistro(dino.dieta, arq);
    bytesOcupados += SalvarStringRegistro(dino.alimento, arq);

    for(int i = bytesOcupados; i < 160; i++)
        fwrite("$", sizeof(char), 1, arq);
}

int SalvarStringRegistro(char* str, FILE* arq)
{
    char* aux = calloc(160, sizeof(char));
    strcpy(aux, str);

    aux[strcspn(aux, "\r")] = 0;
    aux[strcspn(aux, "\n")] = 0;
    int tam = strlen(aux);

    aux[tam] = '#';
    fwrite(aux, sizeof(char), tam+1, arq);

    free(aux);

    return tam+1;
}

void SepararDadoString(char* entrada, char* saida, int nroDado, char sep)
{
    int tam = strlen(entrada);
    int pos = 0, qtdSep = 0, aux = 0;
    for(int i = 0; i < tam && qtdSep < nroDado; i++)
    {
        if(entrada[i] == sep)
            qtdSep++;
        pos++;
    }

    while(1)
    {
        if(entrada[pos] == sep || entrada[pos] == '\r' ||
           entrada[pos] == '\n' || entrada[pos] == '\0')
            break;

        saida[aux] = entrada[pos];
        pos++;
        aux++;
    }
    saida[aux] = '\0';
}

char* SepararDado(char* entrada, int nroDado, char sep)
{
    char* aux = calloc(200, sizeof(char));

    SepararDadoString(entrada, aux, nroDado, sep);

    return aux;
}

//Cria a tabela usando o endereço de entrada e saída
void CreateTable(char* enderecoE, char* enderecoS)
{
    FILE* entrada = fopen(enderecoE, "rb");

    if(entrada == NULL)
    {
        fclose(entrada);
        printf("Falha no processamento do arquivo.");
        return;
    }

    FILE* saida = CriarArquivo(enderecoS);

    if(saida == NULL)
    {
        fclose(saida);
        printf("Falha no processamento do arquivo.");
        return;
    }

    char* linha = calloc(200, sizeof(char));
    char* aux;
    Dinossauro dino = CriaDinossauro();

    fgets(linha, 200, entrada);

    while(fgets(linha, 200, entrada))
    {
        SepararDadoString(linha, dino.nome, 0, ',');
        SepararDadoString(linha, dino.dieta, 1, ',');
        SepararDadoString(linha, dino.habitat, 2, ',');

        aux = SepararDado(linha, 3, ',');
        if(strcmp(aux, "") != 0)
            dino.populacao = atoi(aux);
        free(aux);

        SepararDadoString(linha, dino.tipo, 4, ',');

        aux = SepararDado(linha, 5, ',');
        if(strcmp(aux, "") != 0)
            dino.velocidade = atoi(aux);
        free(aux);

        aux = SepararDado(linha, 6, ',');
        if(strcmp(aux, "") != 0)
            dino.unidadeMedida = aux[0];
        free(aux);

        aux = SepararDado(linha, 7, ',');
        if(strcmp(aux, "") != 0)
            dino.tamanho = atof(aux);
        free(aux);

        SepararDadoString(linha, dino.especie, 8, ',');
        SepararDadoString(linha, dino.alimento, 9, ',');

        SalvarRegistro(dino, saida);
        cab.proxRRN++;

        LiberaDinossauro(dino);
        free(linha);

        dino = CriaDinossauro();
        linha = calloc(200, sizeof(char));
    }
    cab.nroPagDisco += cab.proxRRN / 10;
    if(cab.proxRRN % 10 != 0)
        cab.nroPagDisco++;

    fclose(entrada);
    FecharArquivo(saida, enderecoS);

    binarioNaTela(enderecoS);
}

void SelectTable(char* enderecoE)
{
    FILE* entrada = AbrirArquivo(enderecoE);

    if(entrada == NULL)
    {
        fclose(entrada);
        printf("Falha no processamento do arquivo.");
        return;
    }
    if(cab.proxRRN == 0)
    {
        FecharArquivo(entrada, enderecoE);
        printf("Registro inexistente.");
        return;
    }

    char* linha = calloc(160, sizeof(char));
    Dinossauro dino = CriaDinossauro();

    while(fread(&dino.removido, sizeof(char), 1, entrada))
    {
        if(dino.removido == '1')
        {
            fseek(entrada, 159, SEEK_CUR);
            continue;
        }

        fread(&dino.encadeamento, sizeof(int), 1, entrada);
        fread(&dino.populacao, sizeof(int), 1, entrada);
        fread(&dino.tamanho, sizeof(int), 1, entrada);
        fread(&dino.unidadeMedida, sizeof(char), 1, entrada);
        fread(&dino.velocidade, sizeof(int), 1, entrada);

        fgets(linha, 161 - sizeof(int) * 4 - sizeof(char)*2, entrada);

        SepararDadoString(linha, dino.nome, 0, '#');
        SepararDadoString(linha, dino.especie, 1, '#');
        SepararDadoString(linha, dino.habitat, 2, '#');
        SepararDadoString(linha, dino.tipo, 3, '#');
        SepararDadoString(linha, dino.dieta, 4, '#');
        SepararDadoString(linha, dino.alimento, 5, '#');

        ImprimeDinossauro(dino);

        LiberaDinossauro(dino);
        free(linha);

        dino = CriaDinossauro();
        linha = calloc(200, sizeof(char));
    }

    printf("Numero de paginas de disco: %d\n\n", cab.nroPagDisco);

    FecharArquivo(entrada, enderecoE);
}

int TipoRemocao(char* comando)
{
    if(strcmp(comando, "populacao") == 0)
    {
        return 0;
    }
    if(strcmp(comando, "unidade") == 0)
    {
        return 1;
    }
    if(strcmp(comando, "velocidade") == 0)
    {
        return 2;
    }
    if(strcmp(comando, "tamanho") == 0)
    {
        return 3;
    }
    if(strcmp(comando, "nome") == 0)
    {
        return 4;
    }
    if(strcmp(comando, "especie") == 0)
    {
        return 5;
    }
    if(strcmp(comando, "habitat") == 0)
    {
        return 6;
    }
    if(strcmp(comando, "tipo") == 0)
    {
        return 7;
    }
    if(strcmp(comando, "dieta") == 0)
    {
        return 8;
    }
    if(strcmp(comando, "alimento") == 0)
    {
        return 9;
    }
    return -1;
}

int EncontrarRRN(FILE* arq, int RRNinicial, int idBusca, char* valS)
{
    int valI = 0;
    float valF = 0;

    if(idBusca < 3)
    {
        valI = atoi(valS);
    }
    else if(idBusca == 3)
    {
        valF = atof(valS);
    }

    int RRN = RRNinicial;
    Dinossauro dino = CriaDinossauro();

    while(RRN < cab.proxRRN)
    {
        fseek(arq, 1600 + RRN * 160, SEEK_SET);

        char temp;
        fread(&temp, sizeof(char), 1, arq);
        if(temp == '1')
        {
            RRN++;
            continue;
        }
        fseek(arq, 1600 + RRN * 160, SEEK_SET);

        switch(idBusca)
        {
        case 0:
            fseek(arq, 5, SEEK_CUR);
            fread(&dino.populacao, sizeof(int), 1, arq);

            if(dino.populacao == valI)
                return RRN;
            break;
        case 1:
            fseek(arq, 13, SEEK_CUR);
            fread(&dino.unidadeMedida, sizeof(char), 1, arq);

            if(dino.unidadeMedida == valI)
                return RRN;
            break;
        case 2:
            fseek(arq, 14, SEEK_CUR);
            fread(&dino.velocidade, sizeof(int), 1, arq);

            if(dino.velocidade == valI)
                return RRN;
            break;
        case 3:
            fseek(arq, 9, SEEK_CUR);
            fread(&dino.tamanho, sizeof(float), 1, arq);

            if(dino.tamanho == valF)
                return RRN;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            fseek(arq, 18, SEEK_CUR);

            char* aux = calloc(160, sizeof(char));
            fgets(aux, 161 - sizeof(int) * 4 - sizeof(char)*2, arq);
            SepararDadoString(aux, dino.nome, idBusca-4, '#');
            if(strcmp(dino.nome, valS) == 0)
            {
                return RRN;
            }
        }
        RRN++;
    }
    return -1;
}

void RemoverRegistros(char* enderecoE, int qtd)
{
    FILE* arq = AbrirArquivo(enderecoE);

    if(arq == NULL)
    {
        fclose(arq);
        printf("Falha no processamento do arquivo.");
        return;
    }

    char* comando = calloc(11, sizeof(char));
    char* valS = calloc(160, sizeof(char));
    int id = 0;

    for(int i = 0; i < qtd; i++)
    {
        scanf("%s ", comando);
        id = TipoRemocao(comando);

        if(id > 3)
        {
            scan_quote_string(valS);
            scanf("%*c");
        }
        else
        {
            scanf("%s%*c", valS);
        }

        if(id == -1)
        {
            printf("Nome do campo invalido!");
            continue;
        }

        int RRN = 0;

        RRN = EncontrarRRN(arq, RRN, id, valS);
        while(RRN != -1)
        {
            fseek(arq, 1600 + RRN * 160, SEEK_SET);
            char temp = '1';
            fwrite(&temp, sizeof(char), 1, arq);
            fwrite(&cab.topo, sizeof(int), 1, arq);

            for(int i = 0; i < 155; i++)
                fwrite("$", sizeof(char), 1, arq);

            cab.nroRegRem++;
            cab.topo = RRN;

            RRN = EncontrarRRN(arq, RRN, id, valS);
        }

        free(comando);
        free(valS);

        comando = calloc(11, sizeof(char));
        valS = calloc(160, sizeof(char));
        id = 0;
        RRN = 0;
    }

    FecharArquivo(arq, enderecoE);
    binarioNaTela(enderecoE);
}
