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

long long CalcualrMMC(int a, int b, long long mdc)
{
    //a * b = MDC(a, b) * MMC(a, b)
    //Então: a*b/MDC(a, b) = MMC(a, b)
    return ((long long)a * (long long)b)/mdc;
}

int main()
{
    int qtdCasos, a, b;

    std::cin >> qtdCasos;

    for (int i = 0; i < qtdCasos; ++i)
    {
        std::cin >> a >> b;

        long long mdc = CalcularMDC(a, b);
        std::cout << mdc << " " << CalcualrMMC(a, b, mdc) << std::endl;
    }

    return 0;
}