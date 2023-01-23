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
    date dataDeNascimento;
    
public:
    Pessoa(/* args */);
    ~Pessoa();
};
