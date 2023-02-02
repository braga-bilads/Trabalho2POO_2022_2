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
    string nome;
    string genero;
    Date *dataDeNascimento;

    void setIdade(const Date & dataAtual);
public:
    Pessoa(string nome,string genero,Date &dataDeNascimento,const Date& dataAtual);
    string getNome();
    string getGenero();
    ~Pessoa();
};

#endif