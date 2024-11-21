//Luís Filipe Silva Forti - 14592348
//Lucien Rodrigues Franzen - 14554835

//Trabalho 3 de ED3

#ifndef ARESTA_H
#define ARESTA_H

#include <stdio.h>
#include <iostream>

#include "SerVivo.h"

//Para salvar as informacoes das arestas
class Aresta
{
private:
    //Nome da presa e quantidade de predadores
    std::string _valor;
    int _peso;
public:
    //Construtor com nome e quantidade
    Aresta(std::string valor, int peso);
    //Construtor com os dados do predador
    Aresta(SerVivo serVivo);

    //Para imprimir os dados da aresta
    friend std::ostream& operator<<(std::ostream& out, const Aresta& arest);

    //Para pegar as informações nas outras classes
    std::string Valor() const;
    int Peso() const;
};

#endif // ARESTA_H
