#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

// 10/10/2002
// 01/02/2023
//

static int calculaIdade(Date &dataDeNascimento, Date &dataAtual)
{
    int age = dataAtual.getAno() - dataDeNascimento.getAno();
    if (dataAtual.getMes() > dataDeNascimento.getMes())    
        return age;    
    else if (dataAtual.getMes() < dataDeNascimento.getMes())    
        return --age;    
    else
    {
        if (dataAtual.getDia() >= dataDeNascimento.getDia())
            return age;
        else
            return --age;
    }
}

Pessoa::Pessoa(string nome, string genero, Date &dataDeNascimento, Date &dataAtual)
{
    this->nome = nome;
    this->genero = genero;
    this->idade = calculaIdade(dataDeNascimento, dataAtual);
}
string Pessoa::getNome() const
{
    return this->nome;
}
string Pessoa::getGenero() const
{
    return this->genero;
}
Pessoa::~Pessoa()
{
}