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
    Date dataDeNascimento;   

public:
    /**
     * @brief Construct a new Pessoa 
     * 
     * @param nome 
     * @param genero 
     * @param dataDeNascimento 
     * @param dataAtual 
     */
    Pessoa(string nome, string genero, Date dataDeNascimento, Date dataAtual);

    /**
     * @brief Get Nome
     * 
     * @return string 
     */
    string getNome() const;

    /**
     * @brief Get  Data De Nascimento 
     * 
     * @return Date 
     */
    Date getDataDeNascimento();

    /**
     * @brief Get Genero 
     * 
     * @return string 
     */
    string getGenero() const;

    /**
     * @brief Get Idade 
     * 
     * @return int 
     */
    int getIdade() const;

};
/**
 * @brief Calcula idade da Pessoa pela data de nascimento
 * 
 * @param dataDeNascimento 
 * @param dataAtual 
 * @return int 
 */
int calculaIdade(Date dataDeNascimento, Date dataAtual);

#endif