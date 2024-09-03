#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "funcoesFornecidas.h"
#include "controlador.h"

int main()
{
    //setlocale(LC_ALL,"italian");

    int comando;
    char* endereco = malloc(100 * sizeof(*endereco));
    scanf("%d ", &comando);
    readline(endereco);

    //printf("%d %s", comando, endereco);

    switch(comando)
    {
        case 1:
            {
                int qtd;
                scanf("%d", &qtd);

                //Para confirmar que o SPECIES_ID seja unico
                int nros[qtd];
                int inseridos = 0;
                int continuar;

                FILE* arquivo = fopen(endereco, "wb");

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
                }

                fclose(arquivo);

                binarioNaTela(endereco);

                break;
            }
        case 2:
            {
                FILE* arquivo = fopen(endereco, "rb");

                SPECIE especie;

                while(1)
                {
                    especie = CriarDoArquivo(arquivo);
                    if(especie.SPECIES_ID == -1)
                        break;

                    ImprimirDados(especie);
                }

                fclose(arquivo);
                break;
            }
        case 3:
            {
                int RRN;
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4;
                scanf("%d", &RRN);

                FILE* arquivo = fopen(endereco, "rb");

                fseek(arquivo, RRN * tamEspecie, SEEK_SET);

                SPECIE especie;

                especie = CriarDoArquivo(arquivo);
                if(especie.SPECIES_ID == -1)
                    break;

                ImprimirDados(especie);
                fclose(arquivo);
                break;
            }
        case 4:
            {
                int id;
                scanf("%d", &id);

                int RRN = 0;
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4;

                FILE* arquivo = fopen(endereco, "rb");

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
                    printf("Espécie não encontrada");
                    binarioNaTela(endereco);
                    break;
                }

                //Se encontrou, coloca o cursor de leitura no inicio do registro
                fseek(arquivo, RRN * tamEspecie, SEEK_SET);

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
                            printf("Informação já inserida no arquivo");
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
                            printf("Informação já inserida no arquivo");
                        }
                        else
                        {
                            scanf("%d", &especie.POPULATION);
                        }
                    }
                }

                fopen(endereco, "rb+");

                fseek(arquivo, RRN * tamEspecie, SEEK_SET);
                GravarDados(especie, arquivo);

                fclose(arquivo);

                binarioNaTela(endereco);

                break;
            }
        default:
            break;
    }


    return 0;
}
