#include "candidato.hpp"
#include "pessoa.hpp"
Candidato::Candidato(string nome, string genero, Date& dataDeNascimento, int tipoDeputado, int numeroVotavel,
                     bool eleito, int numeroFederacao, bool legenda, Partido& partido,
                     Date& dataAtual, bool deferido) : Pessoa(nome, genero, dataDeNascimento) 
{
    this->tipoDeputado = tipoDeputado;
    this->numeroVotavel = numeroVotavel;
    this->eleito = eleito;
    this->numeroFederacao = numeroFederacao;
    this->legenda = legenda;
    this->dataAtual = &dataAtual;
    this->deferido = deferido;
}

int Candidato::getTipoDeputado()
{
    return tipoDeputado;
}
int Candidato::getNumeroVotavel()
{
    return numeroVotavel;
}
bool Candidato::isEleito()
{
    return eleito;
}
int Candidato::getNumeroDeVotos()
{
    return numeroDeVotos;
}
int Candidato::getNumeroFederacao()
{
    return numeroFederacao;
}
bool Candidato::isLegenda()
{
    return legenda;
}
bool Candidato::isDeferido()
{
    return deferido;
}
void Candidato::incrementaNumeroVotos(int qtdVotos)
{
    numeroDeVotos += qtdVotos;
}
bool Candidato::isEleito_e_Deferido()
{
    return eleito && deferido;
}