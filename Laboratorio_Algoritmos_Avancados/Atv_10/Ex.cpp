#include <iostream>
#include <vector>

int main()
{
    int nroLivros, orcamento;

    std::cin >> nroLivros;
    std::cin >> orcamento;

    std::vector<int> valoresLivros(nroLivros), paginasLivros(nroLivros);

    for (int i = 0; i < nroLivros; ++i)
        std::cin >> valoresLivros[i];

    for (int i = 0; i < nroLivros; ++i)
        std::cin >> paginasLivros[i];

    //Para a programação dinâmica, serão salvas todas as recompensas
    //para todos os orçamentos <= ao requisitado
    //Orcamento+1 para salvar a recompensa para orçamento 0
    std::vector<int> recompensasValores(orcamento+1, 0);

    //Para cada livro
    for (int i = 0; i < nroLivros; ++i)
    {
        //Para todo orçamento possível maior ou igual ao preço do livro
        for (int j = orcamento; j >= valoresLivros[i]; --j)
        {
            //Compara qual recompensa é maior:
            //O valor atual, determinado em outra iteração
            //A recompensa com o restante do dinheiro + a recompensa do livro atual
            //Como o cálculo é feito da direita para a esquerda, 
            //a soma não considera livros calculados anteriormente em i
            //Assim, completa a restrição de que cada livro só pode ser comprado 1 única vez
            recompensasValores[j] = std::max(recompensasValores[j], recompensasValores[j-valoresLivros[i]] + paginasLivros[i]);
        }
    }

    std::cout << recompensasValores[orcamento] << std::endl;

    return 0;
}