#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

Pessoa::Pessoa(string nome, string genero, Date &dataDeNascimento)
{    
    this->nome = nome;
    this->genero = genero;
    // this->idade = setIdade(dataDeNascimento);
}
int Pessoa::setIdade(Date dataDeNascimento)
{
    return 1;
}

Pessoa::~Pessoa()
{
}

string Pessoa::getNome() {
    return this->nome;
}
string Pessoa::getGenero() {
    return this->genero;
}