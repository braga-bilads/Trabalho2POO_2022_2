#ifndef SISTEMAELEITORAL_H
#define SISTEMAELEITORAL_H

#include <iostream>
#include <string>
#include "candidato.hpp"
#include "partido.hpp"
#include "date.hpp"

using namespace std;

class SistemaEleitoral
{
private:
    map<int, Partido *> partidos;
    map<int, Candidato *> candidatos;
    int numeroCargo;
    Date *dataDaEleicao;
    int qtdVagas;
    string *pathConsulta;
    string *pathVotos;
    int totalVotosLegenda;
    int totalVotosNominais;

public:
    SistemaEleitoral(string &numeroCargo, string &pathConsulta, string &pathVotos, Date &dataDaEleicao);

    int getNumeroCargo();
    void incTotalVotosLegenda(int qtd);
    void incTotalVotosNominais(int qtd);
    int getTotalVotosLegenda() const;
    int getTotalVotosNominais() const;
    int getQtdVagas() const;
    void incrementaQtdVagas();
    Date& getDataDaEleicao() const;
    string getPathConsulta() const;
    string getPathVotos() const;
    void addCandidato(Candidato &c);
    map<int,Partido*> getPartidos() const;
    map<int,Candidato*> getCandidatos() const;
    void printPartidos(SistemaEleitoral &sisEleitoral);
    int partidosCount(int numPartido);
    void addPartido(pair<int,Partido*> par);
    Partido* getPartido(int numPartido);
    Candidato* getCandidato(int num);
    int candidatosCount(int numero);
    
};

#endif