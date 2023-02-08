#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <chrono>
#include "date.hpp"

using namespace std;

class Pessoa
{
private:
    int idade;
    string nome;
    string genero;
    Date *dataDeNascimento;   

public:
    Pessoa(string nome, string genero, Date &dataDeNascimento, Date &dataAtual);
    string getNome() const;
    Date* getDataDeNascimento();
    string getGenero() const;
    ~Pessoa();
};

#endif