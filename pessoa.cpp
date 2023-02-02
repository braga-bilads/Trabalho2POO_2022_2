#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

Pessoa::Pessoa(string nome,string genero,Date &dataDeNascimento,const Date& dataAtual)
{    
    this->nome = nome;
    this->genero = genero;
    this->dataDeNascimento = &dataDeNascimento;
    setIdade(dataAtual);
}

void Pessoa::setIdade(const Date &dataAtual)
{
}

Pessoa::~Pessoa()
{
}

string Pessoa::getNome()
{
    return this->nome;
}
string Pessoa::getGenero() {
    return this->genero;
}