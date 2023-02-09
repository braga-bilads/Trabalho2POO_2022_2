#include <iostream>
#include "sistemaeleitoral.hpp"

SistemaEleitoral::SistemaEleitoral(string &numeroCargo, string &pathConsulta, string &pathVotos, Date dataDaEleicao) {
    int cargo = 0;
    if (numeroCargo.compare("--estadual") == 0) {
        cargo = 7;
    }
    else if (numeroCargo.compare("--federal") == 0) {
        cargo = 6;
    }
    else {
        cout << "Uso para cargos: --estadual ou --federal" << endl;
        exit(EXIT_FAILURE);               
    }
    this->numeroCargo = cargo;
    this->dataDaEleicao = dataDaEleicao;
    this->pathConsulta = &pathConsulta;
    this->pathVotos = &pathVotos;
    this->qtdVagas = 0;    

}

int SistemaEleitoral::getNumeroCargo()
{
    return numeroCargo;
}

void SistemaEleitoral::incTotalVotosLegenda(int qtd)
{
    this->totalVotosLegenda +=qtd;
}
void SistemaEleitoral::incTotalVotosNominais(int qtd) {
    this->totalVotosNominais +=qtd;
}
int SistemaEleitoral::getTotalVotosLegenda() const {
    return this->totalVotosLegenda;
}
int SistemaEleitoral::getTotalVotosNominais() const {
    return this->totalVotosNominais;
}
int SistemaEleitoral::getQtdVagas() const {
    return this->qtdVagas;
}
void SistemaEleitoral::incrementaQtdVagas() {
    this->qtdVagas++;
}
Date SistemaEleitoral::getDataDaEleicao() const {
    return this->dataDaEleicao;
}
string SistemaEleitoral::getPathConsulta() const {
    return *this->pathConsulta;
}
string SistemaEleitoral::getPathVotos() const {
    return *this->pathVotos;
}
void SistemaEleitoral::addCandidato(Candidato &c) {    
    // cout<<c.getNumeroVotavel()  << " " << c.getNome() << " " << c.getGenero()<< endl;
    candidatos.insert({(c).getNumeroVotavel(), &c});
}

map<int,Partido*> SistemaEleitoral::getPartidos() const{
    return partidos;
}

map<int,Candidato*> SistemaEleitoral::getCandidatos() const {
    return candidatos;
}

void SistemaEleitoral::printPartidos(SistemaEleitoral &sisEleitoral)
{
    map<int, Partido *>::iterator itr;
    for (itr = sisEleitoral.getPartidos().begin(); itr != sisEleitoral.getPartidos().end(); itr++)
    {
        Partido p = *(itr->second);
        cout << itr->first << " " << p.getSigla() << endl;
    }
}

int SistemaEleitoral::partidosCount(int numPartido){
    return this->partidos.count(numPartido);
}

bool SistemaEleitoral::partidoExiste(int numero){
    auto it = partidos.find(numero);
      return !(it==partidos.end());
}

void SistemaEleitoral::addPartido(pair<int,Partido*> par){
    partidos.insert(par);
}

Partido* SistemaEleitoral::getPartido(int numPartido){
    return partidos[numPartido];
}

Candidato* SistemaEleitoral::getCandidato(int num){
    return candidatos[num];
}

int SistemaEleitoral::candidatosCount(int numero){
    return candidatos.count(numero);
}

bool SistemaEleitoral::candidatoExiste(int numero){
    auto it = candidatos.find(numero);
    return !(it==candidatos.end());
}