#include <iostream>

long long CalcularMDC(int a, int b)
{
    //Para o algoritmo funcionar, 'a' deve ser o maior
    if (a > b)
        std::swap(a, b);

    //Enquanto não achou um divisor
    while (b != 0)
    {
        //Calcula o resto de a/b e troca os valores de 'a' e 'b'
        //O algoritmo segue a lógica de Euclides:
        //O MDC de dois números não muda quando substituímos o maior pelo resto da divisão entre eles.
        //Onde o valor de 'a' é descartado para a inclusão de a%b (o valor de 'b' é passado pra 'a')
        int aux = a % b;
        a = b;
        b = aux;
    }

    return a;
}

long long InversoModular(long long a, long long m)
{
    long long m0 = m;
    long long x0 = 0;
    long long x1 = 1;

    //Se o MDC(a, m) for diferente de 1, quebra a condição de existência do inverso modular
    if (CalcularMDC(a, m) != 1)
        return -1;

    //Este código usa o algoritmo de Euclides estendido
    //Ex: (120, 23)
    //120/23 = 5 resta 5, 'a' vira 23 e 'm' vira 5
    //então, 5 = 1*120 - 5 * 23
    //23/5 = 4 resta 3, 'a' vira 5 e 'm' vira 3
    //então, 3 = 1*23 - 4*5, mas sabemos que 5 = 1*120 - 5 * 23
    //então, 3 = 1 * 23 - 4*(1*120 - 5 * 23) = -4*120 + 21*23

    //E assim repete. O processo pode ser definido como:
    //a/m = q resta r, então:
    //r = a - q * m
    //a = x1 * a0 + y1 * m0
    //m = x0 * a0 + y0 * m0
    //Com 'a0' e 'm0' os valores originais, 'xi' e 'yi' os valores calculados na iteração
    //Substituindo:
    //r = x1 * a0 + y1 * m0 - q * (x0 * a0 + y0 * m0)
    //r = a0 * (x1 - qx0) + m0 * (y1 - qy0)

    //Logo, os coeficientes do resto são:
    //novoX = x1 - q * x0
    //novoY = y1 - q * y0

    //Como o algoritmo de Euclides troca:
    //(a, m) -> (m, r), os coeficientes também precisam acompanhar essa troca:
    //novo 'a' recebe o antigo 'm'
    //novo 'm' recebe o resto
    
    //Então:
    //x1 recebe o antigo x0
    //x0 recebe o coeficiente calculado para o resto
    //O mesmo vale para y1 e y0.

    //Quando o MDC chega em 1, teremos:
    //1 = x * a0 + y * m0
    //Aplicando módulo m0:
    //x * a0 ≡ 1 (mod m0)
    //Portanto, x é o inverso modular de a0.
    
    //Com MDC == 1, o resto se torna 0
    //Assim, m == 0 se torna a condição de parada  do algoritmo

    while (m != 0)
    {
        long long q = a / m;

        long long r = m;
        m = a % m;
        a = r;

        r = x0;
        x0 = x1 - q * x0;
        x1 = r;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main()
{
    int qtdCasos, a, m;

    std::cin >> qtdCasos;

    for (int i = 0; i < qtdCasos; ++i)
    {
        std::cin >> a >> m;

        std::cout << InversoModular(a, m) << std::endl;
    }

    return 0;
}