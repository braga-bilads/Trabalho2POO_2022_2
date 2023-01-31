#include "partido.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

static bool compare (Candidato *a, Candidato *b) {
    int valor = b->getNumeroDeVotos() - a->getNumeroDeVotos();
    if (valor == 0) {
        //compara idade
    }
    return valor < 0;
}


Partido::Partido(int numero_votavel, string& sigla) {
    this->numero_votavel = numero_votavel;
    this->sigla = &sigla;
}

string* Partido::getSigla() {
    return this->sigla;
}

int Partido::getQuantidadeDeVotosNominais() {
    return this->quantidadeDeVotosNominais;
}
int Partido::getNumeroVotavel() {
    return this->numero_votavel;
}
int Partido::getQuantidadeDeVotosLegenda() {
    return this->quantidadeDeVotosLegenda;
}
int Partido::getQuantidadeTotalDeVotos() {
    return this->quantidadeTotalDeVotos;
}
int Partido::getQuantidadeDeEleitos() {
    return this->quantidadeDeEleitos;
}
int Partido::getQuantidadeDeVagas() {
    return this->quantidadeDeVagas;
}
Candidato* Partido::getCandMaisVotado() {
    return candMaisvotado;
}
Candidato* Partido::getCandMenosVotado() {
    return candMenosvotado;
}

void Partido::addCandidato(Candidato& c) {
    candidatos.insert({ c.getNumeroVotavel(), &c });
}
void Partido::incrementaVotosNominais(int qtd) {
    quantidadeDeVotosNominais += qtd;
}
void Partido::incrementaVotosLegenda(int qtd) {
    quantidadeDeVotosLegenda += qtd;
}
void Partido::incrementaQuantidadeDeVagas() {
    quantidadeDeVagas++;
}
void Partido::setCandidatoMenoseMaisVotado() {
    vector<Candidato*> candidatos_vec(candidatos.size());
    map<int, Candidato*>::iterator it;
    for (it = candidatos.begin(); it!=candidatos.end(); ++it) {
        candidatos_vec.push_back(it->second);
    }
    sort(candidatos_vec.begin(), candidatos_vec.end(), [](Candidato* const a, Candidato* const b) -> bool {return compare(a, b);});
    int i = 1;
    while (!candidatos_vec[candidatos_vec.size() - i]->isDeferido())    i++;

    candMenosvotado = candidatos_vec[candidatos_vec.size() - i];
    i = 0;
    while (!candidatos_vec[i]->isDeferido())    i++;

    candMaisvotado = candidatos_vec[i];

        
}

void Partido::incrementaEleitos()
{
    quantidadeDeEleitos++;
}
