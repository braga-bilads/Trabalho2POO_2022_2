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
    int getTotalVotosLegenda();
    int getTotalVotosNominais();
    int getQtdVagas();
    void incrementaQtdVagas();
    Date& getDataDaEleicao();
    string getPathConsulta();
    string getPathVotos();
    void addCandidato(Candidato &c);
    map<int,Partido*>& getPartidos();
    
};

#endif