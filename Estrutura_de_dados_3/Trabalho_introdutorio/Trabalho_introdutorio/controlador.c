/*#######

Luis Filipe Silva Forti - 14592348
Lucien Rodrigues Franzen - 14554835

Trabalho Introdutório de ED3



main.c - módulo principal que contra comandos e operações de criação de espécies
e de recuperação e gravação de dados em binário

controlador.c - módulo das funções criadas para lidar com os dados binários e entrada

funcoesFornecidas - módulo com funções pré-fornecidas para o trabalho

########*/

#include "./controlador.h" //header desse módulo
#include "./funcoesFornecidas.h" //header das funções pré-fornecidas

//Cria uma espécie com valores padrão, os quais permitem indicar
//e identificar que aqueles valores ainda não foram inseridos
SPECIE CriaEspecie()
{
    //Todas as definições de campo aqui são feitas de forma a identificar
    //como espécie sem dados inseridos.
    SPECIE especie;

    especie.SPECIES_ID = 0; //Cria ID neutro para indicar ser struct "vazio" (sem dados)

    especie.NAME = malloc(41 * sizeof(char*)); //Aloca memória para a string de nome
    //
    for(int i = 0; i < 41; i++) //Para cada um dos 41 bytes no campo "nome"
        especie.NAME[i] = '$'; //Coloca caractere de espaco em branco

    especie.SCIENTIFIC_NAME = malloc(61 * sizeof(*especie.SCIENTIFIC_NAME)); //Aloca memória
    //para a string de nome científico

    for(int i = 0; i < 61; i++) //Para cada um dos 61 bytes do campo come científico
        especie.SCIENTIFIC_NAME[i] = '$'; //Coloca caractere de espaco em branco

    especie.POPULATION = 0; //Define população como nula

    especie.STATUS = malloc(9 * sizeof(*especie.STATUS));//Aloca memória para a string do campo status
    for(int i = 0; i < 9; i++) //Para cada um dos 9 bytes do status
        especie.STATUS[i] = '$'; //Coloca caractere de espaco em branco

    memccpy(especie.LOCATION, (int[]){0, 0}, sizeof(float), 2); //Define localidade de valor float neutro

    especie.HUMAN_IMPACT = 0; //Define valor nulo para impacto humano

    return especie; //retorna a struct padrão criada
}

//Função que cria uma struct espécie com valores indicados a partir do console
SPECIE CriarDoConsole()
{
    SPECIE especie = CriaEspecie(); //Cria uma espécie padrão sem valores inseridos

    //As próximas linhas recebem os valores de cada campo.
    //scanf é usado com números, e readline com strings, pois ela é uma versão otimizada que
    //coloca '\0' no final da string, permite finais de linha antes de começar o dado e
    //em geral não registra o último final de linha como parte da string.
    scanf("%d", &especie.SPECIES_ID);
    readline(especie.NAME);
    readline(especie.SCIENTIFIC_NAME);
    scanf("%d", &especie.POPULATION);
    readline(especie.STATUS);
    scanf("%f", &especie.LOCATION[0]);
    scanf("%f", &especie.LOCATION[1]);
    scanf("%d", &especie.HUMAN_IMPACT);

    return especie; //Retorna a struct espécie com todos os dados inseridos
}


//Função que cria uma struct espécie com valores indicados a partir do arquívo de
//registros, começando em onde o ponteiro do arquivo está.
//Ela resgata os dados de um registro do arquivo e os transforma para essa struct.
SPECIE CriarDoArquivo(FILE* arq)
{
    SPECIE especie = CriaEspecie(); //Cria uma struct de espécie padrão, com dados não inseridos

    //Abaixo o código lê os primeirs 4 bytesa partir de onde o ponteiro está no arquivo,
    //já que sizeof(int) diz para ler de 4 em 4 bytes no caso.
    //Assim verificando se foi capaz de ler o arquivo corretamente se não ler ID corretamente
    if(!fread(&especie.SPECIES_ID, sizeof(int), 1, arq))
    {
        especie.SPECIES_ID = -1; //Define que o registro teve falha na leitura
        return especie;//Retorna a struct marcada com id de falha
    }


    //Abaixo o código lê cada campo em sua ordem, respeitando a ordem que foi colocada no
    //arquivo de registro. Assim, não se confundem bytes de informações.
    //Ele insere cada campo no endereço correspondente da struct.

    //sizeof(float) e sizeof(int) são modos de contar de 4 em 4 bytes, então continua
    //coincidindo a quantidade de bytes com o tamanho do campo com os números abaixo.
    fread(especie.NAME, sizeof(char), 41, arq);
    fread(especie.SCIENTIFIC_NAME, sizeof(char), 61, arq);
    fread(&especie.POPULATION, sizeof(int), 1, arq);
    fread(especie.STATUS, sizeof(char), 9, arq);
    fread(&especie.LOCATION[0], sizeof(float), 1, arq);
    fread(&especie.LOCATION[1], sizeof(float), 1, arq);
    fread(&especie.HUMAN_IMPACT, sizeof(int), 1, arq);

    return especie; //Retorna a struct resgatada do arquivo com sucesso
}

//Libera a memória dos campos da struct com ponteiros, permitindo que o programa
//não tenha que se preocupar guardando essas informações quando não forem mais úteis
void LiberarEspecie(SPECIE especie)
{
    //A seguir se liberam os três campos: nome, nome cientifico e status.
    free(especie.NAME);
    free(especie.SCIENTIFIC_NAME);
    free(especie.STATUS);
}

//Mostra os dados de uma struct espécie na formatação certa pedida problema
void ImprimirDados(SPECIE especie)
{
    //Abaixo estão os prints dos 3 primeiros campos, com seus valores tirados da struct recebida.
    printf("ID: %d\n", especie.SPECIES_ID);
    printf("Nome: %s\n", especie.NAME);
    printf("Nome Científico: %s\n", especie.SCIENTIFIC_NAME);

    //Como população é um número e tem caso especial em 0, separamos em um if.
    if(especie.POPULATION == 0) //Caso seja 0, há o comando de imprimir o texto NULO
        printf("População: NULO\n");
    else
        printf("População: %d\n", especie.POPULATION); //De outro modo, imprimir o número do campo

    //Próximos prints de valores da struct
    printf("Status: %s\n", especie.STATUS);
    printf("Localização: (%.2f, %.2f)\n", especie.LOCATION[0], especie.LOCATION[1]);

    //Como impacto humano é um número e tem caso especial em 0, separamos em um if.
    if(especie.HUMAN_IMPACT == 0) //Caso seja 0, há o comando de imprimir o texto NULO
        printf("Impacto Humano: NULO\n\n");
    else
        printf("Impacto Humano: %d\n\n", especie.HUMAN_IMPACT); //De outro modo, imprimir o número do campo
}


//Grava os dados de uma struct espécie no arquivo de registros, os transformando para
//a forma binária requesitada.
void GravarDados(SPECIE especie, FILE* arq) //Recebe uma struct espécie e o arquivo para registro
{
    //Abaixo o código lê cada campo da struct e o insere no registro em sua ordem especificada
    //Assim, não se confundem bytes de informações.

    //sizeof(float) e sizeof(int) são modos de contar de 4 em 4 bytes, então continua
    //coincidindo a quantidade de bytes com o tamanho do campo com os números abaixo.
    fwrite(&especie.SPECIES_ID, sizeof(int), 1, arq);
    fwrite(especie.NAME, sizeof(char), 41, arq);
    fwrite(especie.SCIENTIFIC_NAME, sizeof(char), 61, arq);
    fwrite(&especie.POPULATION, sizeof(int), 1, arq);
    fwrite(especie.STATUS, sizeof(char), 9, arq);
    fwrite(&especie.LOCATION[0], sizeof(float), 1, arq);
    fwrite(&especie.LOCATION[1], sizeof(float), 1, arq);
    fwrite(&especie.HUMAN_IMPACT, sizeof(int), 1, arq);
}
