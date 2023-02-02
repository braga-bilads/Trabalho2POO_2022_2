#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

static int calculaIdade(Date &dataDeNascimento, Date &dataAtual) {

}

Pessoa::Pessoa(string nome, string genero, Date &dataDeNascimento, Date &dataAtual)
{    
    this->nome = nome;
    this->genero = genero;
    this->idade = calculaIdade(dataDeNascimento, dataAtual);
}

Pessoa::~Pessoa()
{
}

string Pessoa::getNome() const {
    return this->nome;
}
string Pessoa::getGenero() const {
    return this->genero;
}