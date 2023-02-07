#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include "pessoa.hpp"
#include "partido.hpp"

using namespace std;
class Partido;

class Candidato : public Pessoa
{
private:
    int tipoDeputado;
    int numeroVotavel;
    bool eleito;
    int numeroDeVotos;
    int numeroFederacao;
    bool legenda;
    bool deferido;
    Partido* partido;

public:
    Candidato(string nome, string genero, Date& dataDeNascimento, int tipoDeputado, int numeroVotavel,
              bool eleito, int numeroFederacao, bool legenda, Partido& partido,
              Date& dataAtual, bool deferido);
    
    int getTipoDeputado() const;
    int getNumeroVotavel() const;
    bool isEleito() const;
    int getNumeroDeVotos() const;
    int getNumeroFederacao() const; 
    bool isLegenda() const;
    bool isDeferido() const;
    void incrementaNumeroVotos(int qtdVotos);
    bool isEleito_e_Deferido() const;
    Partido getPartido() const;
    bool operator<(const Candidato &c);
    
    
};
ostream& operator<<(ostream& os, const Candidato& c);


#endif