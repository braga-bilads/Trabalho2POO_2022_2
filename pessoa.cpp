#include <iostream>
#include <string>
#include "pessoa.hpp"

using namespace std;

// 01/02/2023
// 10/10/2002
//

static int calculaIdade(Date dataDeNascimento, Date dataAtual)
{
    int ano = dataAtual.getAno() - dataDeNascimento.getAno();
    
    if (dataAtual.getMes() < dataDeNascimento.getMes()) 
        ano--;    
    else if (dataAtual.getMes() == dataDeNascimento.getMes())
    {
        if (dataAtual.getDia() < dataDeNascimento.getDia())
            ano--;
    }

    return ano;    
}

Pessoa::Pessoa(string nome, string genero, Date dataDeNascimento, Date dataAtual)
{
    this->dataDeNascimento = dataDeNascimento;
    this->nome = nome;
    this->genero = genero;
    this->idade = calculaIdade(dataDeNascimento, dataAtual);
}
string Pessoa::getNome() const
{
    return this->nome;
}
Date Pessoa::getDataDeNascimento()
{
    return this->dataDeNascimento;
}
string Pessoa::getGenero() const
{
    return this->genero;
}

int Pessoa::getIdade() const
{
    return this->idade;
}
