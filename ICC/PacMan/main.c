#include <stdio.h>
#include <stdlib.h>
#include <conio.h>       // _kbhit, _getch
#include <windows.h>
#include <time.h>

#define SPEED 50
#define linhas 16
#define colunas 32

#define xInicial 1
#define yInicial 1

#define qtdInimigos 4

//Estrutura do jogador
typedef struct
{
    //Coordenadas
    int x;
    int y;
    //Caracter que será desenhado
    char c;
    //Tempo de invencibilidade
    int inven;
} Jogador;

//Estrutura do inimigo
typedef struct
{
    //Coordenadas
    int x;
    int y;
    //Caracter que será desenhado
    char c;
    //Tempo morto
    int timeOut;
} Inimigo;

//Variavel que controla o estado do jogo
int jogando = 1;
//Arquivo-texto do mapa
FILE *arquivo;

char **mapa;
Jogador jogador;
Inimigo *inimigos;

int fase = 0;
int pontuacao = 0;

void cls(HANDLE hConsole)
{
    COORD coordScreen = { 0, 0 };    // home for the cursor
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer
                                    (TCHAR)' ',      // Character to write to the buffer
                                    dwConSize,       // Number of cells to write
                                    coordScreen,     // Coordinates of first cell
                                    &cCharsWritten)) // Receive number of characters written
    {
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute
                                    coordScreen,      // Coordinates of first cell
                                    &cCharsWritten))  // Receive number of characters written
    {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}

//Método para criar o mapa e as posições iniciais
void loadMapa()
{
    //Aumenta a fase em 1 e define que o jogador está jogando
    fase++;
    jogando = 1;

    //Posiciona o jogador e reinicia seus dados
    jogador.x = xInicial;
    jogador.y = yInicial;
    jogador.c = 'C';
    jogador.inven = 0;

    //Abre o arquivo-texto do mapa
    arquivo = fopen("mapa.txt", "r");

    //Se tiver ocorrido um erro, fecha o programa
    if(arquivo == NULL)
        exit(1);

    //Aloca memória para as linhas do mapa
    mapa = calloc(linhas, sizeof(*mapa));

    //Loop para cada linha
    for(int i = 0; i < linhas; i++)
    {
        //Aloca memória para as colunas de cada linha do mapa
        mapa[i] = calloc(colunas, sizeof(**mapa));

        //Pega os dados da linha
        fgets(mapa[i], colunas + 1, arquivo);
        //Descarta o \n no fim da linha
        fgetc(arquivo);

        //Para controlar a densidade de frutas e poderes no mapa
        int frutaNaLinha = 0, poderNaLinha = 0;

        //Loop para cada coluna da linha
        for(int j = 0; j < colunas; j++)
        {
            //Se a casa for um espaço vazio
            if(mapa[i][j] == ' ')
            {
                //Define que será uma moeda
                mapa[i][j] = '.';

                //Aleatoriza e verifica se pode ser criada uma fruta no local
                if (rand() % (linhas + colunas) == 1 && !frutaNaLinha)
                {
                    //Caso possa e tenha sido escolhido, define que será uma fruta
                    mapa[i][j] = 'F';
                    //Define que não terão mais frutas nesta linha
                    frutaNaLinha = 1;
                }
                //Aleatoriza e verifica se pode ser criado um poder no local
                else if (rand() % (linhas + colunas) == 0 && !poderNaLinha)
                {
                    //Caso possa e tenha sido escolhido, define que será um poder
                    mapa[i][j] = 'O';
                    //Define que não terão mais poderes nesta linha
                    poderNaLinha = 1;
                }
            }
        }
    }

    //Fecha o arquivo do mapa
    fclose(arquivo);

    //Aloca memória para o ponteiro dos inimigos
    inimigos = calloc(qtdInimigos, sizeof(*inimigos));

    //Loop para dar valores iniciais aos inimigos
    for(int i = 0; i < qtdInimigos; i++)
    {
        //Aleatoriza a posição x do inimigo atual, impedindo que seja uma das paredes laterais
        inimigos[i].x = (rand() % (colunas-2)) + 1;
        //Aleatoriza a posição y do inimigo atual, impedindo que seja uma das paredes superior ou inferior
        //Tambem garante que será criado à uma distância mínima de 3 linhas do jogador
        inimigos[i].y = (rand() % (linhas-5)) + 4;
        //Reinicia seus dados
        inimigos[i].c = 'W';
        inimigos[i].timeOut = 0;
    }
    //Loop para garantir que os inimigos estejam em uma posição válida
    for(int i = 0; i < qtdInimigos; i++)
    {
        //Verifica se ele está em uma posição inválida
        if(validarPosicaoInimigo(inimigos[i]))
        {
            //Caso esteja, aleatoriza novas posições
            inimigos[i].x = (rand() % (colunas-2)) + 1;
            inimigos[i].y = (rand() % (linhas-5)) + 4;
            //Diminui i em 1, forçando à verificar novamente o mesmo inimigo
            i--;
        }
    }
}

//Método para garantir que o inimigo passado está em um local válido
int validarPosicaoInimigo(Inimigo atual)
{
    //Verifica se está sobrepondo uma parede
    if(mapa[atual.y][atual.x] == '-' || mapa[atual.y][atual.x] == '|' || mapa[atual.y][atual.x] == '+' || mapa[atual.y][atual.x] == '#')
        //Retorna que está em uma posição inválida
        return 1;

    //Verifica se está no portal da esquerda
    if(mapa[atual.y][atual.x] == '<')
        //Retorna que está sob tal portal
        return 2;

    //Verifica se está no portal da direita
    if(mapa[atual.y][atual.x] == '>')
        //Retorna que está sob tal portal
        return 3;

    //Para verificar se o inimigo está sobrepondo outro
    int cont = 0;

    //Verifica se atual está sobreposto à outro inimigo
    for(int i = 0; i < qtdInimigos; i++)
        if(atual.x == inimigos[i].x && atual.y == inimigos[i].y)
            cont++;

    //Verifica se é maior que 1, pois ele conta à si mesmo
    if(cont > 1)
        //Retorna que está em uma posição inválida
        return 1;

    //Retorna que está em uma posição válida / não especial
    return 0;
}

//Método para mover os inimigos
void moverInimigos(int velocidade)
{
    //Variável auxiliar
    int movimento;
    //Variáveis para controle
    int mudancaX = 0, mudancaY = 0;

    //Para todos os inimigos
    for(int i = 0; i < qtdInimigos; i++)
    {
        //Se o inimigo não estiver morto
        if(inimigos[i].timeOut <= 0)
        {
            //Aleatoriza uma direção de movimento
            movimento = rand() % 4;

            switch(movimento)
            {
            //Caso para a esquerda
            case 0:
                //Diminui a posição x em 1
                inimigos[i].x--;
                //Salva a mudança
                mudancaX = -1;
                break;
            //Caso para a direita
            case 1:
                //Aumenta a posição x em 1
                inimigos[i].x++;
                //Salva a mudança
                mudancaX = 1;
                break;
            //Caso para cima
            case 2:
                //Diminui a posição y em 1
                inimigos[i].y--;
                //Salva a mudança
                mudancaY = -1;
                break;
            //Caso para baixo
            case 3:
                //Aumenta a posição y em 1
                inimigos[i].y++;
                //Salva a mudança
                mudancaY = 1;
                break;
            default:
                break;
            }
            //Verifica para onde ele se movimentou / se foi válido
            movimento = validarPosicaoInimigo(inimigos[i]);
            switch(movimento)
            {
            //Se for inválido
            case 1:
                //Cancela o movimento
                inimigos[i].x -= mudancaX;
                inimigos[i].y -= mudancaY;

                //Reinicia as variáveis controle
                mudancaX = 0;
                mudancaY = 0;

                //Diminui i em 1, forçando à refazer o mesmo inimigo
                i--;

                break;
            //Caso tenha tocado o portal da esquerda
            case 2:
                //Teleporta para a saída do portal da direita
                inimigos[i].x = colunas-2;
                break;
            //Caso tenha tocado o portal da direita
            case 3:
                //Teleporta para a saída do portal da esquerda
                inimigos[i].x = 1;
                break;
            default:
                break;
            }
        }
        //Caso esteja morto
        else
        {
            //Diminui seu tempo morto
            inimigos[i].timeOut -= velocidade;

            //Se tiver terminado seu tempo morto
            if(inimigos[i].timeOut <= 0)
            {
                //Loop para garantir que ele estará em uma posição válida
                while(1)
                {
                    //Aleatoriza uma posição fora das paredes externas
                    inimigos[i].x = (rand() % (colunas-2)) + 1;
                    inimigos[i].y = (rand() % (linhas-2)) + 1;

                    //Verifica se é uma posição válida e se não é a mesma que a do jogador
                    if(validarPosicaoInimigo(inimigos[i]) == 0 && inimigos[i].x != jogador.x && inimigos[i].y != jogador.y)
                        //Encerra o loop caso seja válida
                        break;
                }
            }
        }
    }
}

//Método para fazer a movimentação do jogador
void inputTeclado()
{
    if (_kbhit())
    {
        //Vê qual tecla está sendo tocada
        char tecla = _getch();
        switch(tecla)
        {
            //Caso seja o w ou a seta para cima
            case 'w':
            case 72:
                //Verifica se o jogador pode se mover para cima
                if(mapa[jogador.y - 1][jogador.x] != '-' && mapa[jogador.y - 1][jogador.x] != '|' && mapa[jogador.y - 1][jogador.x] != '+')
                    //Diminui seu y em 1
                    jogador.y--;
                break;

            //Caso seja o s ou a seta para baixo
            case 's':
            case 80:
                //Verifica se o jogador pode se mover para baixo
                if(mapa[jogador.y + 1][jogador.x] != '-' && mapa[jogador.y + 1][jogador.x] != '|' && mapa[jogador.y + 1][jogador.x] != '+')
                    //Aumenta seu y em 1
                    jogador.y++;
                break;

            //Caso seja o a ou a seta para esquerda
            case 'a':
            case 75:
                //Verifica se ele irá se mover para o portal da esquerda
                if(mapa[jogador.y][jogador.x - 1] == '<')
                    //Teleporta para a saída do portal da direita
                    jogador.x = colunas-2;
                //Verifica se o jogador pode se mover para esquerda
                else if(mapa[jogador.y][jogador.x - 1] != '-' && mapa[jogador.y][jogador.x - 1] != '|' && mapa[jogador.y][jogador.x - 1] != '+')
                    //Diminui seu x em 1
                    jogador.x--;
                break;

            //Caso seja o d ou a seta para direita
            case 'd':
            case 77:
                //Verifica se ele irá se mover para o portal da direita
                if(mapa[jogador.y][jogador.x + 1] == '>')
                    //Teleporta para a saída do portal da esquerda
                    jogador.x = 1;
                //Verifica se o jogador pode se mover para direita
                else if(mapa[jogador.y][jogador.x + 1] != '-' && mapa[jogador.y][jogador.x + 1] != '|' && mapa[jogador.y][jogador.x + 1] != '+')
                    //Aumenta seu x em 1
                    jogador.x++;
                break;

            default:
                break;
        }
    }
    //Se o jogador estiver invencível
    if(jogador.inven > 0)
        //Diminui a duração
        jogador.inven--;
}

//Método para verificar a posição do jogador
void verificarPosicao()
{
    for(int i = 0; i < qtdInimigos; i++)
    {
        //Verifica se está tocando um inimigo
        if(inimigos[i].x == jogador.x && inimigos[i].y == jogador.y)
        {
            //Se o jogador não estiver invencível
            if(jogador.inven <= 0)
            {
                //Define que o jogador morreu
                jogando = 0;
                jogador.c = 'D';
                return;
            }
            //Caso o jogador esteja invencível
            else
            {
                //Define o tempo que o inimigo estará morto
                inimigos[i].timeOut = 10 * 1000 / SPEED;
                //Posiciona o inimigo fora do mapa
                inimigos[i].x = colunas * 2;
                inimigos[i].y = linhas * 2;
            }
        }
    }
    //Se o jogador estiver tocando uma moeda
    if(mapa[jogador.y][jogador.x] == '.')
    {
        //Aumenta a sua pontuação
        pontuacao += fase * 5;
        //Tira a moeda do mapa
        mapa[jogador.y][jogador.x] = ' ';
    }
    //Se o jogador estiver tocando uma fruta
    else if(mapa[jogador.y][jogador.x] == 'F')
    {
        //Aumenta a sua pontuação
        pontuacao += fase * 10;
        //Tira a fruta do mapa
        mapa[jogador.y][jogador.x] = ' ';
    }
    //Se o jogador estiver tocando um poder
    else if(mapa[jogador.y][jogador.x] == 'O')
    {
        //Define seu tempo de invencibilidade
        jogador.inven = 10 * 1000 / SPEED;
        //Tira o poder do mapa
        mapa[jogador.y][jogador.x] = ' ';
    }
}

//Método para desenhar o mapa e as entidades
void desenhar()
{
    //Limpa a tela
    cls( GetStdHandle( STD_OUTPUT_HANDLE ));

    //Para verificar se tem um fantasma na casa
    int temFantasma;

    //Loops para passar por todas as casas
    for (int i=0; i < linhas; i++)
    {
        for (int j=0; j < colunas; j++)
        {
            //Se for a casa do jogador
            if(jogador.x == j && jogador.y == i)
                printf("%c", jogador.c);
            else
            {
                //Reinicia a variável
                temFantasma = 0;
                //Para verificar todos os inimigos
                for(int k = 0; k < qtdInimigos; k++)
                {
                    //Verifica se é a casa do inimigo
                    if(inimigos[k].x == j && inimigos[k].y == i)
                    {
                        //Se for, desenha ele
                        printf("%c", inimigos[k].c);
                        //Salva que um fantasma foi desenhado e encerra o loop
                        temFantasma = 1;
                        break;
                    }
                }
                //Se um fantasma não foi desenhado
                if(!temFantasma)
                    //Desenha a casa salva no mapa
                    printf("%c", mapa[i][j]);
            }
        }
        //Ao terminar a linha do mapa, quebra a linha do console
        printf("\n");
    }
    //Dados sobre o jogo
    printf("Fase: %d\nPontuacao: %d\n", fase, pontuacao);
    printf("Legenda:\nC -> jogador\nW -> inimigo\n. -> moeda\nF -> fruta\nO -> poder\n+/-/| -> paredes");

    //Se o jogador estiver sob efeito do poder
    if(jogador.inven > 0)
        printf("\nINVENCIVEL!");
    //Se o jogador morreu
    if(jogando == 0)
        printf("\nD -> local de morte");
}

//Para verificar se coletou todas as moedas / frutas
void verificarFim()
{
    //Loops para passar por todas as casas
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            //Se encontrar uma moeda ou uma fruta
            if(mapa[i][j] == '.' || mapa[i][j] == 'F')
                //Termina a função
                return;
        }
    }
    //Se não tiver encontrado nada, define que o jogador venceu a fase
    jogando = 2;
}

int main()
{
    //Aleatorizar uma seed
    time_t t = time(NULL);
    srand(localtime(&t));

    //Velocidade dos inimigos
    int velocidade = 4;

    //Enquanto não tiver morrido
    while(jogando != 0)
    {
        //Carrega o mapa
        loadMapa();

        //Reinicia a contagem de tempo
        int frame = 0;

        //Enquanto não tiver morrido / ganhado
        while(jogando == 1)
        {
            //Aumenta o tempo
            frame++;
            //Espera
            Sleep(SPEED);
            //Verifica o input do teclado
            inputTeclado();

            //Se o inimigo puder se mover
            if(frame % velocidade == 0)
                moverInimigos(velocidade);

            //Verifica a posição do jogador
            verificarPosicao();
            //Desenha o mapa e as entidades
            desenhar();
            //Verifica se o jogador venceu a fase
            verificarFim();
        }
        //Se não tiver morrido, ou seja, se venceu
        if(jogando != 0)
        {
            //Avisa que venceu
            printf("\n\nParabens! Comecando a proxima fase!");
            //Espera 2 segundos
            Sleep(2000);

            //Verifica se a velocidade dos inimigos mudará
            if(fase % 3 == 0 && velocidade > 1)
                velocidade--;
        }
    }
    //Alerta que morreu
    printf("\n\nVoce morreu!\n");
    //Pontuação final
    printf("Pontuacao: %d\n", pontuacao);

    //Para o jogador não fechar o código por acidente ao morrer
    printf("\nDigite algo para encerrar\n");
    scanf("%*s");

    perror("AAA ");
    return 0;
}
