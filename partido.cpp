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
        return;
    }
    sort(candidatosList.begin(), candidatosList.end(), compCand);   
    
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
    string votos = "";
    string nominais = "";
    string eleitos = "";

    if (p.getQuantidadeTotalDeVotos() > 1)
    {
        votos = " votos (";
        // saida = saida + " votos (" + to_string(p.getQuantidadeDeVotosNominais());
    }
    else
    {
        votos = " voto (";
        // saida = saida + " voto (" + to_string(p.getQuantidadeDeVotosNominais());
    }
    if (p.getQuantidadeDeVotosNominais() > 1)
    {
        nominais = " nominais e ";
        // saida = saida + " nominais (" + to_string(p.getQuantidadeDeVotosLegenda()) + " de legenda), ";
    }
    else
    {
        nominais = " nominal e ";
        // saida = saida + " nominal (" + to_string(p.getQuantidadeDeVotosLegenda()) + " de legenda), ";
    }
    if (p.getQuantidadeDeEleitos() > 1)
    {
        eleitos = " candidatos eleitos ";
        // saida = saida + to_string(p.getQuantidadeDeEleitos()) + " candidatos eleitos ";
    }
    else
    {
        eleitos = " candidato eleito";
        // saida = saida + to_string(p.getQuantidadeDeEleitos()) + " candidatos eleitos ";
    }
    return os << p.getSigla() << " - " << to_string(p.getNumeroVotavel()) << ", " << p.getQuantidadeTotalDeVotos() << 
        votos << p.getQuantidadeDeVotosNominais() << nominais << p.getQuantidadeDeVotosLegenda() << " de legenda), " <<
        p.getQuantidadeDeEleitos() << eleitos;
}

bool comparaPartidoTotalVotos(Partido *p1, Partido*p2)
{
    int valor = p1->getQuantidadeTotalDeVotos() - p2->getQuantidadeTotalDeVotos();
    if (valor == 0)
    {
        return (p1->getNumeroVotavel() - p2->getNumeroVotavel()) < 0;
    }
    return valor > 0;
}

bool comparaPartidoCandMaisVotado(Partido *p1, Partido*p2)
{
 //caso p1 não tenha cand mais votado
    if(p1->getCandMaisVotado() == NULL){
        if(p2->getCandMaisVotado() == NULL){
                return 0; //os dois não tem
            }
            else return (p2->getCandMaisVotado()->getNumeroDeVotos()) < 0;
        }

    if(p2->getCandMaisVotado() == NULL){
        if(p1->getCandMaisVotado() == NULL){
            return 0; // os dois não tem candidato mais votado
        }
        else return (p1->getCandMaisVotado()->getNumeroDeVotos()) < 0;
    }
    int valor = p1->getCandMaisVotado()->getNumeroDeVotos() - p2->getCandMaisVotado()->getNumeroDeVotos();
    if(valor == 0){
            //se for igual compara pelo numero do partido
            return p2->getNumeroVotavel() - p1->getNumeroVotavel() < 0;
        }
    return (valor>0);
}