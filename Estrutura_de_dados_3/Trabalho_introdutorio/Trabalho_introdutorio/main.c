/*#######

Luis Filipe Silva Forti - 14592348
Lucien Rodrigues Franzen - 14554835

Trabalho Introdutório de ED3



main.c - módulo principal que contra comandos e operações de criação de espécies
e de recuperação e gravação de dados em binário

controlador.c - módulo das funções criadas para lidar com os dados binários e entradas

funcoesFornecidas - módulo com funções pré-fornecidas para o trabalho

########*/
#include <stdio.h>
#include <stdlib.h>

#include "funcoesFornecidas.h" //Funções dadas no RunCodes para uso no trabalho
#include "controlador.h" //Funções criadas para lidar com os registros binários

//Módulo principal do programa
int main()
{
    int comando;
    char* endereco = calloc(100, sizeof(*endereco)); // Aloca memória para caminho do arquivo
    scanf("%d ", &comando); //Indica qual dos comandos será realizado
    scanf("%s", endereco); //Sem & por já ser um ponteiro

    switch(comando) //Troca entre os comandos necessários
    {
        case 1: //Inserção
            {
                int qtd; // Numero de espécies a serem adicionadas
                scanf("%d", &qtd);

                //Para confirmar que o SPECIES_ID seja unico temos esse array
                int nros[qtd];

                int inseridos = 0; //Contador dos que já foram inseridos
                int continuar; // Flag de se vai inserir

                FILE* arquivo;

                // Erro se o endereço não for definifido e
                // abre o arquivo no modo binário e diz erro se não conseguir
                if (endereco == NULL || !(arquivo = fopen(endereco, "wb")))
                {
                    printf("Falha no processamento do arquivo"); // Mensagem de erro

                    free(endereco); //Libera endereço

                    return 0; //Termina programa
                }

                for(int i = 0; i < qtd; i++) //Para cada especie a ser inserida fazer esse protocolo
                {
                    SPECIE especie = CriarDoConsole(); //Pega os dados da especie
                    continuar = 1; //Diz que ainda pode continuar inserção

                    for(int j = 0; j < inseridos; j++) //Para cada um já inseridos verifica
                    {
                        //Se o SPECIES_ID ja foi usado
                        if (nros[j] == especie.SPECIES_ID)
                        {
                            continuar = 0; //Flag não inserrir se não for único
                            break;
                        }
                    }

                    if(continuar) //Vê se houve alguma flag de parada
                    {
                        inseridos++; //Aumenta inseridos
                        nros[inseridos] = especie.SPECIES_ID; //Adiciona ID como ultimo no array de existentes

                        GravarDados(especie, arquivo); //Grava a especie no arquivo
                    }
                    LiberarEspecie(especie); //Esquece os dados para liberar memoria
                }

                fclose(arquivo);

                binarioNaTela(endereco); //Mostra o binário resultante

                break;
            }
        case 2: //Vê todas as espécies
            {
                FILE* arquivo;

                // Erro se o endereço não for definifido e
                // abre o arquivo no modo binário e diz erro se não conseguir

                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo"); // Mensagem de erro

                    free(endereco); //Libera endereço

                    return 0; //Termina programa
                }

                SPECIE especie;

                while(1) //Acontece até a condição de -1 (fim das especies a ler) ocorra
                {
                    especie = CriarDoArquivo(arquivo); //Vê uma das espécies do arquivo, move ponteiro para próxima
                    if(especie.SPECIES_ID == -1) //-1 significa o fim das espécies registradas
                        break;

                    ImprimirDados(especie); //Imprime os dados da espécie
                    LiberarEspecie(especie); //Libera memória
                }

                fclose(arquivo);

                LiberarEspecie(especie); //Libera memória

                break;
            }
        case 3: //Mostra uma especie específica a partir da posição dela no arquivo
            {
                int RRN; //Especie especifica a ser vista, de acordo com a posição do registro dela no arquivo
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4; //Tamanho do registro de especie em bytes
                scanf("%d", &RRN);

                FILE* arquivo;


                // Erro se o endereço não for definifido e
                // abre o arquivo no modo binário e diz erro se não conseguir
                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco); //Libera memória

                    return 0;
                }

                fseek(arquivo, RRN * tamEspecie, SEEK_SET); //Procura no arquivo pela especie a partir
                //do RRN especificado
                //Se deve multiplicar RRN pelo tamanho do registro de espécie para chegar na próxima sessão de bytes.

                SPECIE especie;

                especie = CriarDoArquivo(arquivo); //Lê a espécie do arquivo para ver se há algo dentro
                //O ponteiro já está no lugar do RRN correto.
                if(especie.SPECIES_ID == -1) //Se não ouver nada naquele RRN o id é -1 e não existe
                {
                    printf("Espécie não encontrada\n");
                    return 0;
                }

                ImprimirDados(especie); // Imprime os dados da especie encontrada
                fclose(arquivo);

                LiberarEspecie(especie); //Libera memoria

                break;
            }
        case 4: //Inserção de informação em espécie
            {
                int id;
                scanf("%d", &id); //Recebe um ID para busca

                int RRN = 0; //Numero da especie sendo procurada, começa na primeira
                int tamEspecie = 4 + 41 + 61 + 4 + 9 + 2*4 + 4; //Tamanho do registro de especie em bytes
                // que é a soma de todos os campos

                FILE* arquivo;
                // Erro se o endereço não for definido e
                // abre o arquivo no modo binário e diz erro se não conseguir
                if (endereco == NULL || !(arquivo = fopen(endereco, "rb")))
                {
                    printf("Falha no processamento do arquivo");

                    free(endereco); //Libera memória

                    return 0;
                }


                SPECIE especie = CriaEspecie(); //Cria para servir de buscadora os dados


                //Abaixo o código lê os primeirs 4 bytesa partir de onde o ponteiro está no arquivo,
                //A função do while abaixo é procurar o id de espécie certo para retirá-la.
                while(fread(&especie.SPECIES_ID, sizeof(int), 1, arquivo)) //enquanto estiver lendo e
                //tiver sucesso em ver os dados da especie olhada do arquivo
                {
                    if(especie.SPECIES_ID != id) //Se a especie não for a procurada
                    {
                        RRN++; //Aumenta qual o numero da especie sendo procurada no arquivo
                        fseek(arquivo, RRN * tamEspecie, SEEK_SET); //Avança para o próximo registro
                        //Se deve multiplicar RRN pelo tamanho do registro de espécie para chegar na próxima sessão de bytes.
                    }
                    else
                        break; //Sai do loop se for achada a especie
                }
                //Se não encontrou
                if(feof(arquivo))
                {
                    fclose(arquivo); //Fechar o arquivo
                    printf("Espécie não encontrada\n");
                    binarioNaTela(endereco); //Mostra o binário calculado
                    LiberarEspecie(especie); //Libera memória da espécie
                    return 0;
                }

                //Se encontrou, coloca o cursor de leitura no inicio do registro
                fseek(arquivo, RRN * tamEspecie, SEEK_SET);

                LiberarEspecie(especie); //Libera memória da espécie
                especie = CriarDoArquivo(arquivo);//Recupera dados da especie no arquivo de acordo
                //com onde está o ponteiro
                fclose(arquivo);

                int qtd; //Numero de campos para mudar
                char* aux = calloc(13, sizeof(char)); //memoria auxiliar
                scanf("%d", &qtd);

                for(int i = 0; i < qtd; i++) //Para cada campo a ser mudado
                {
                    readline(aux); //Ler o nome do campo a ser inserido e coloca em um auxiliar
                    if(strcmp(aux, "STATUS") == 0) //Vê se é o status que foi pedido
                    {
                        if(strcmp(especie.STATUS, "NULO") != 0) //Se o status não for identificado como nulo
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux); //Joga no lixo pegando outro input
                        }
                        else
                        {
                            readline(especie.STATUS); //Lê dado a ser inserido pelo input e coloca no campo
                        }
                    }
                    else if(strcmp(aux, "HUMAN IMPACT") == 0) //Verifica se é esse campo o buscado
                    {
                        if(especie.HUMAN_IMPACT != 0) //Vê se já foi inserida, visto que o default é 0
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux); //Joga no lixo pegando outro input
                        }
                        else
                        {
                            scanf("%d", &especie.HUMAN_IMPACT); //Lê dado a ser inserido pelo input e coloca no campo
                        }
                    }
                    else if(strcmp(aux, "POPULATION") == 0) //Verifica se é esse campo o buscado
                    {
                        if(especie.POPULATION != 0) //Vê se informação já foi inserida, visto que o default é 0
                        //Se fosse 0, significaria que não houve inserção ainda
                        {
                            printf("Informação já inserida no arquivo\n");
                            readline(aux); //Joga no lixo pegando outro input
                        }
                        else
                        {
                            scanf("%d", &especie.POPULATION); //Lê dado a ser inserido pelo input e coloca no campo
                        }
                    }
                }

                free(aux);

                // Erro se o endereço não for definido e abre o arquivo no modo binário de leitura
                //com atualização e diz erro se não conseguir
                if (endereco == NULL || !(arquivo = fopen(endereco, "rb+")))
                {
                    printf("Falha no processamento do arquivo");

                    //Libera memória
                    free(endereco);
                    LiberarEspecie(especie);

                    return 0;
                }

                fseek(arquivo, RRN * tamEspecie, SEEK_SET); //Coloca o ponteiro de volta no início da especie
                //que esta sendo alterada.
                //Multiplicamos o RRN pelo tamanho do resgistro de novo para ficar no início do n-gésimo registro
                GravarDados(especie, arquivo); //Grava a especie no arquivo a partir de onde o ponteiro está nele.

                fclose(arquivo); //Fecha arquivo

                binarioNaTela(endereco); //Mostra o endereço do arquivo para o usuário

                LiberarEspecie(especie); //Libera memória

                break;
            }
        default: //Caso nenhum desses número for selecionado, termine o switch
            break;
    }

    free(endereco); //Libere a memória em que está o endereço de arquivo.

    return 0;
}
