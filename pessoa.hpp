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

    int setIdade(Date dataDeNascimento);
    
public:
    Pessoa(string nome, string genero, Date dataDeNascimento);
    ~Pessoa();
    
};
