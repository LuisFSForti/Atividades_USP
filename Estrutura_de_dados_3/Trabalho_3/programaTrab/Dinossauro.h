#ifndef DINOSSAURO_H
#define DINOSSAURO_H

#include <stdio.h>
#include <iostream>
#include <fstream>


class Dinossauro
{
private:
    int _populacao, _velocidade;
    float _tamanho;
    char _unidadeMedida;
    std::string _nome, _especie, _habitat, _tipo, _dieta, _alimento;

public:
    Dinossauro();
    Dinossauro(Dinossauro& dino);
    Dinossauro(std::fstream &arq);
    void SalvarDinossauro(std::fstream &arq);
    friend std::ostream& operator<<(std::ostream& out, Dinossauro& dino);

    int Populacao();
    int Velocidade();
    float Tamanho();
    char UnidadeMedida();
    std::string Nome();
    std::string Especie();
    std::string Habitat();
    std::string Tipo();
    std::string Dieta();
    std::string Alimento();
};

#endif // DINOSSAURO_H
