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
    Dinossauro(const Dinossauro& dino);
    Dinossauro(std::fstream &arq);

    void SalvarDinossauro(std::fstream &arq);

    friend std::ostream& operator<<(std::ostream& out, const Dinossauro& dino);

    int Populacao() const;
    int Velocidade() const;
    float Tamanho() const;
    char UnidadeMedida() const;
    std::string Nome() const;
    std::string Especie() const;
    std::string Habitat() const;
    std::string Tipo() const;
    std::string Dieta() const;
    std::string Alimento() const;
};

#endif // DINOSSAURO_H
