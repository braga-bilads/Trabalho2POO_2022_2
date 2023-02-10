#include "partido.hpp"
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

Partido::Partido(int numero_votavel, string sigla)
{
    this->numero_votavel = numero_votavel;
    this->sigla = sigla;
    this->quantidadeDeVagas= 0;
    this->quantidadeDeEleitos=0;
    this->quantidadeDeVotosLegenda =0;
    this->quantidadeDeVotosNominais = 0;
}

string Partido::getSigla() const
{
    return this->sigla;
}

int Partido::getQuantidadeDeVotosNominais() const
{
    return this->quantidadeDeVotosNominais;
}
int Partido::getNumeroVotavel() const
{
    return this->numero_votavel;
}
int Partido::getQuantidadeDeVotosLegenda() const
{
    return this->quantidadeDeVotosLegenda;
}
int Partido::getQuantidadeTotalDeVotos() const
{
    return this->quantidadeDeVotosLegenda + this->quantidadeDeVotosNominais;
}
int Partido::getQuantidadeDeEleitos() const
{
    return this->quantidadeDeEleitos;
}
int Partido::getQuantidadeDeVagas() const
{
    return this->quantidadeDeVagas;
}
Candidato *Partido::getCandMaisVotado() const
{
    return candMaisvotado;
}
Candidato *Partido::getCandMenosVotado() const
{
    return candMenosvotado;
}

void Partido::addCandidato(Candidato &c)
{
    candidatos.push_back(&c);
}
void Partido::incrementaVotosNominais(int qtd)
{
    quantidadeDeVotosNominais += qtd;
}
void Partido::incrementaVotosLegenda(int qtd)
{
    quantidadeDeVotosLegenda += qtd;
}
void Partido::incrementaQuantidadeDeVagas()
{
    quantidadeDeVagas++;
}
void Partido::setCandidatoMenoseMaisVotado()
{

    vector<Candidato*> candidatosList(candidatos.begin(),candidatos.end());

    if (candidatosList.size() == 0)
    {
        candMaisvotado = NULL;
        candMenosvotado = NULL;
    }
    sort(candidatosList.begin(), candidatosList.end());   
    
    int i = 1;
    
    while (!candidatosList[candidatosList.size() - i]->isDeferido())
        i++;

    candMenosvotado = candidatosList[candidatosList.size() - i];
    i = 0;
    while (!candidatosList[i]->isDeferido())
        i++;

    candMaisvotado = candidatosList[i];
}

void Partido::incrementaEleitos()
{
    quantidadeDeEleitos++;
}

ostream &operator<<(ostream &os, const Partido &p)
{

    string saida = p.getSigla() + " - " + to_string(p.getNumeroVotavel()) + ", " + to_string(p.getQuantidadeTotalDeVotos());

    if (p.getQuantidadeTotalDeVotos() > 1)
    {
        saida = saida + " votos (" + to_string(p.getQuantidadeDeVotosNominais());
    }
    else
    {
        saida = saida + " voto (" + to_string(p.getQuantidadeDeVotosNominais());
    }
    if (p.getQuantidadeDeVotosNominais() > 1)
    {
        saida = saida + " nominais (" + to_string(p.getQuantidadeDeVotosLegenda()) + " de legenda), ";
    }
    else
    {
        saida = saida + " nominal (" + to_string(p.getQuantidadeDeVotosLegenda()) + " de legenda), ";
    }
    if (p.getQuantidadeDeEleitos() > 1)
    {
        saida = saida + to_string(p.getQuantidadeDeEleitos()) + " candidatos eleitos ";
    }
    else
    {
        saida = saida + to_string(p.getQuantidadeDeEleitos()) + " candidatos eleitos ";
    }
    return os << saida;
}

bool Partido::operator<(const Partido &p)
{
    int valor = this->getQuantidadeTotalDeVotos() - p.getQuantidadeTotalDeVotos();
    if (valor == 0)
    {
        return (p.getNumeroVotavel() - this->numero_votavel) < 0;
    }
    return valor < 0;
}
