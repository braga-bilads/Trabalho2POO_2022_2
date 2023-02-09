#include "partido.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

static bool compare(Candidato *a, Candidato *b)
{
    int valor = b->getNumeroDeVotos() - a->getNumeroDeVotos();
    if (valor == 0)
    {
        // compara idade
    }
    return valor < 0;
}

Partido::Partido(int numero_votavel, string sigla)
{
    this->numero_votavel = numero_votavel;
    this->sigla = sigla;
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
    return this->quantidadeTotalDeVotos;
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
    candidatos.insert({c.getNumeroVotavel(), &c});
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
    vector<Candidato *> candidatos_vec(candidatos.size());
    map<int, Candidato *>::iterator it;
    for (it = candidatos.begin(); it != candidatos.end(); ++it)
    {
        candidatos_vec.push_back(it->second);
    }
    sort(candidatos_vec.begin(), candidatos_vec.end(), [](Candidato *const a, Candidato *const b) -> bool
         { return compare(a, b); });
    int i = 1;
    while (!candidatos_vec[candidatos_vec.size() - i]->isDeferido())
        i++;

    candMenosvotado = candidatos_vec[candidatos_vec.size() - i];
    i = 0;
    while (!candidatos_vec[i]->isDeferido())
        i++;

    candMaisvotado = candidatos_vec[i];
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

bool Partido::operator<(const Partido &p) {
    int valor = this->quantidadeTotalDeVotos - p.getQuantidadeTotalDeVotos();
    if (valor == 0) {        
        return (p.getNumeroVotavel() - this->numero_votavel) < 0;
    }
    return valor < 0;
}

