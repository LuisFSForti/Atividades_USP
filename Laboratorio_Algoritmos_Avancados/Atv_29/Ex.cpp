#include <iostream>
#include <algorithm>

struct Vertice
{
    int x, y;
};

struct Linha
{
    Vertice vertices[2];
};

//(b-a)x(c-a), produto vetorial
//Colineares == 0
//Rotação horária < 0
//Rotação anti-horária > 0
long long Orientacao(const Vertice& a,
                     const Vertice& b,
                     const Vertice& c)
{
    return (long long)(b.x - a.x) * (c.y - a.y)
         - (long long)(b.y - a.y) * (c.x - a.x);
}

//Valida se o vértice p está dentro da área do quadrado com diagonal a-b
//Assim, o algoritmo só funcionará se confirmar colinearidade entre os 3 pontos previamente
bool NoSegmento(const Vertice& a,
                const Vertice& b,
                const Vertice& p)
{
    return std::min(a.x, b.x) <= p.x &&
           p.x <= std::max(a.x, b.x) &&
           std::min(a.y, b.y) <= p.y &&
           p.y <= std::max(a.y, b.y);
}

bool VerificarInterseccao(const Linha& l1, const Linha& l2)
{
    const Vertice& a = l1.vertices[0];
    const Vertice& b = l1.vertices[1];
    const Vertice& c = l2.vertices[0];
    const Vertice& d = l2.vertices[1];

    //Pega as orientações entre os 4 vértices, considerando as retas a-b e c-d
    long long o1 = Orientacao(a, b, c);
    long long o2 = Orientacao(a, b, d);
    long long o3 = Orientacao(c, d, a);
    long long o4 = Orientacao(c, d, b);

    //Se as orientações em pares (a-b e a-c, a-b e a-d) forem diferentes, significa que o desenho formou um X
    //Assim, garante-se que há um ponto de intersecção
    if ((o1 > 0) != (o2 > 0) && (o3 > 0) != (o4 > 0))
        return true;

    //Quando forem colineares, verifica se o terceiro vértice pertence à primeira reta
    if (o1 == 0 && NoSegmento(a, b, c)) return true;
    if (o2 == 0 && NoSegmento(a, b, d)) return true;
    if (o3 == 0 && NoSegmento(c, d, a)) return true;
    if (o4 == 0 && NoSegmento(c, d, b)) return true;

    return false;
}

int main()
{
    Linha lin1, lin2;

    Vertice vertAtual;
    for (int i = 0; i < 2; i++)
    {
        std::cin >> vertAtual.x >> vertAtual.y;
        lin1.vertices[i] = vertAtual;
    }
    for (int i = 0; i < 2; i++)
    {
        std::cin >> vertAtual.x >> vertAtual.y;
        lin2.vertices[i] = vertAtual;
    }

    if (VerificarInterseccao(lin1, lin2))
        std::cout << "SIM" << std::endl;
    else
        std::cout << "NAO" << std::endl;

    return 0;
}