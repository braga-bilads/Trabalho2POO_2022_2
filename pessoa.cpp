#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

// 01/02/2023
// 10/10/2002
//

static int calculaIdade(Date &dataDeNascimento, Date &dataAtual)
{
    int ano = dataAtual.getAno() - dataDeNascimento.getAno();
    
    if (dataAtual.getMes() < dataDeNascimento.getMes()) 
        ano--;    
    else if (dataAtual.getMes() == dataDeNascimento.getMes())
    {
        if (dataAtual.getDia() < dataDeNascimento.getDia())
            ano--;
    }
    int bissexto = ano/4;
    ano *= 365;
    ano += bissexto;
    return ano;    
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