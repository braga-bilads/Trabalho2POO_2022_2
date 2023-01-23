#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

Pessoa::Pessoa(string nome, string genero, Date dataDeNascimento)
{
    this->nome = nome;
    this->dataDeNascimento = dataDeNascimento;
    this->genero = genero;
    //this->idade = setIdade(dataDeNascimento);
}
int Pessoa::setIdade(Date dataDeNascimento) {
    //calcula idade
}

Pessoa::~Pessoa()
{
    
}