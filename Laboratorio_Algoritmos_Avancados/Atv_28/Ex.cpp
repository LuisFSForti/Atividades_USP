#include <iostream>
#include <algorithm>

enum PosicoesVertices
{
    menorXmenorY,
    menorXmaiorY,
    maiorXmenorY,
    maiorXmaiorY
};

struct Vertice
{
    int x, y;
};

struct Retangulo
{
    Vertice vertices[4];
};

void OrdenarPorX(Retangulo& r)
{
    //Ordena por X e, em caso de empate, por Y, ambos de forma crescente
    std::sort(r.vertices, r.vertices + 4,
        [](const Vertice& a, const Vertice& b)
        {
            if (a.x != b.x)
                return a.x < b.x;
            return a.y < b.y;
        });
}

bool VerificarColisao(const Retangulo& ret1, const Retangulo& ret2)
{
    return
        //Se sobrepõem em X
        ret1.vertices[menorXmenorY].x <= ret2.vertices[maiorXmaiorY].x &&
        ret1.vertices[maiorXmaiorY].x >= ret2.vertices[menorXmenorY].x &&
        //Se sobrepõem em Y
        ret1.vertices[menorXmenorY].y <= ret2.vertices[maiorXmaiorY].y &&
        ret1.vertices[maiorXmaiorY].y >= ret2.vertices[menorXmenorY].y;
}

int main()
{
    Retangulo ret1, ret2;

    Vertice vertAtual;
    for (int i = 0; i < 4; i++)
    {
        std::cin >> vertAtual.x >> vertAtual.y;
        ret1.vertices[i] = vertAtual;
    }
    for (int i = 0; i < 4; i++)
    {
        std::cin >> vertAtual.x >> vertAtual.y;
        ret2.vertices[i] = vertAtual;
    }

    //Ordena os vértices dos retângulos por X e por Y
    OrdenarPorX(ret1);
    OrdenarPorX(ret2);

    if (VerificarColisao(ret1, ret2))
        std::cout << "SIM" << std::endl;
    else
        std::cout << "NAO" << std::endl;

    return 0;
}