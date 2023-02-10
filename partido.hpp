#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include "candidato.hpp"
#include <map>
#include <list>
using namespace std;
class Candidato;

class Partido // implementa um comparador
{
private:
    list<Candidato *> candidatos;
    int numero_votavel;
    string sigla;
    int quantidadeDeVotosNominais;
    int quantidadeDeVotosLegenda;
    int quantidadeDeEleitos;
    int quantidadeDeVagas;
    Candidato *candMaisvotado;
    Candidato *candMenosvotado;

public:
    Partido(int numeroVotavel, string sigla);
    int getNumeroVotavel() const;
    string getSigla() const;
    int getQuantidadeDeVotosNominais() const;
    int getQuantidadeDeVotosLegenda() const;
    int getQuantidadeTotalDeVotos() const;
    int getQuantidadeDeEleitos() const;
    int getQuantidadeDeVagas() const;
    Candidato *getCandMaisVotado() const;
    Candidato *getCandMenosVotado() const;

    void addCandidato(Candidato &c);
    void incrementaVotosNominais(int qtd);
    void incrementaVotosLegenda(int qtd);
    void incrementaQuantidadeDeVagas();  // soma um
    void setCandidatoMenoseMaisVotado(); // ordena os candidatos e seta o mais e menos votado
    void incrementaEleitos();
    void printCandidatos();

};
bool comparaPartidoTotalVotos(Partido *p1, Partido*p2);
bool comparaPartidoCandMaisVotado(Partido *p1, Partido*p2);
ostream &operator<<(ostream &os, const Partido &p);

#endif