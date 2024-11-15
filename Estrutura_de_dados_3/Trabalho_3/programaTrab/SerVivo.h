#ifndef SerVivo_H
#define SerVivo_H

#include <stdio.h>
#include <iostream>
#include <fstream>

//Classe para armazenar os dados gerais dos seres
class SerVivo
{
private:
    int _populacao, _velocidade;
    float _tamanho;
    char _unidadeMedida;
    std::string _nome, _especie, _habitat, _tipo, _dieta, _alimento;

public:
    //Construtor vazio, gera valores nulos
    SerVivo();
    //Construtor com nome, serve para os seres vivos que ainda nao tem dados, apenas o nomes
    SerVivo(std::string nome);
    //Construtor de copia
    SerVivo(const SerVivo& serVivo);
    //Construtor usando um arquivo binario
    //Deve estar no comeco do registro para funcionar
    SerVivo(std::fstream &arq);

    //Para imprimir os dados
    friend std::ostream& operator<<(std::ostream& out, const SerVivo& serVivo);

    //Para pegar as informacoes nas outras classes
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

#endif // SerVivo_H
