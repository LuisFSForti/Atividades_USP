#include <stdio.h>
#include <stdlib.h>

#include "funcoesFornecidas.h"
#include "controlador.h"

int main()
{
    int comando;
    char* endereco = calloc(100, sizeof(*endereco));
    scanf("%d ", &comando);
    readline(endereco);

    switch(comando)
    {
        case 1:
            {
                int qtd;
                scanf("%d", &qtd);

                //Para confirmar que o SPECIES_ID seja unico
                int nros[qtd];
                //int* nros = calloc(qtd, sizeof(*nros));
                int inseridos = 0;
                int continuar;

                FILE* arquivo;

                if (endereco == NULL || !(arquivo = fopen(endereco, "wb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco);

                    return 0;
                }

                for(int i = 0; i < qtd; i++)
                {
                    SPECIE especie = CriarDoConsole();
                    continuar = 1;

                    for(int j = 0; j < inseridos; j++)
                    {
                        //Se o SPECIES_ID ja foi usado
                        if (nros[j] == especie.SPECIES_ID)
                        {
                            //printf("%d\n", especie.SPECIES_ID);
                            continuar = 0;
                            break;
                        }
                    }

                    if(continuar)
                    {
                        inseridos++;
                        nros[inseridos] = especie.SPECIES_ID;

                        GravarDados(especie, arquivo);
                    }
                    LiberarEspecie(especie);
                }

                fclose(arquivo);

                binarioNaTela(endereco);

                break;
            }
        case 2:
            {
                FILE* arquivo;

                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco);

                    return 0;
                }

                SPECIE especie;

                while(1)
                {
                    especie = CriarDoArquivo(arquivo);
                    if(especie.SPECIES_ID == -1)
                        break;

                    ImprimirDados(especie);
                    LiberarEspecie(especie);
                }

                fclose(arquivo);

                LiberarEspecie(especie);

                break;
            }
        case 3:
            {
                int RRN;
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4;
                scanf("%d", &RRN);

                FILE* arquivo;

                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco);

                    return 0;
                }

                fseek(arquivo, RRN * tamEspecie, SEEK_SET);

                SPECIE especie;

                especie = CriarDoArquivo(arquivo);
                if(especie.SPECIES_ID == -1)
                {
                    printf("Espécie não encontrada\n");
                    return 0;
                }

                ImprimirDados(especie);
                fclose(arquivo);

                LiberarEspecie(especie);

                break;
            }
        case 4:
            {
                int id;
                scanf("%d", &id);

                int RRN = 0;
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4;

                FILE* arquivo;
                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco);

                    return 0;
                }


                SPECIE especie = CriaEspecie();

                //Procura onde esta o id da especie
                while(fread(&especie.SPECIES_ID, sizeof(int), 1, arquivo))
                {
                    if(especie.SPECIES_ID != id)
                    {
                        RRN++;
                        fseek(arquivo, RRN * tamEspecie, SEEK_SET);
                    }
                    else
                        break;
                }
                //Se nao encontrou
                if(feof(arquivo))
                {
                    fclose(arquivo);
                    printf("Espécie não encontrada\n");
                    binarioNaTela(endereco);
                    LiberarEspecie(especie);
                    return 0;
                }

                //Se encontrou, coloca o cursor de leitura no inicio do registro
                fseek(arquivo, RRN * tamEspecie, SEEK_SET);

                LiberarEspecie(especie);
                especie = CriarDoArquivo(arquivo);
                fclose(arquivo);

                int qtd;
                char* aux = calloc(13, sizeof(char));
                scanf("%d", &qtd);

                for(int i = 0; i < qtd; i++)
                {
                    readline(aux);
                    if(strcmp(aux, "STATUS") == 0)
                    {
                        if(strcmp(especie.STATUS, "NULO") != 0)
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux); //Joga no lixo
                        }
                        else
                        {
                            readline(especie.STATUS);
                        }
                    }
                    else if(strcmp(aux, "HUMAN IMPACT") == 0)
                    {
                        if(especie.HUMAN_IMPACT != 0)
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux);
                        }
                        else
                        {
                            scanf("%d", &especie.HUMAN_IMPACT);
                        }
                    }
                    else if(strcmp(aux, "POPULATION") == 0)
                    {
                        if(especie.POPULATION != 0)
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux);
                        }
                        else
                        {
                            scanf("%d", &especie.POPULATION);
                        }
                    }
                }

                if (endereco == NULL || !(arquivo = fopen(endereco, "rb+")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco);
                    free(aux);
                    LiberarEspecie(especie);

                    return 0;
                }

                fseek(arquivo, RRN * tamEspecie, SEEK_SET);
                GravarDados(especie, arquivo);

                fclose(arquivo);

                binarioNaTela(endereco);

                free(aux);
                LiberarEspecie(especie);

                break;
            }
        default:
            break;
    }

    free(endereco);

    return 0;
}
