#include "candidato.hpp"
#include "pessoa.hpp"
Candidato::Candidato(string nome, string genero, Date dataDeNascimento, int tipoDeputado, int numeroVotavel,
                     bool eleito, int numeroFederacao, bool legenda, Partido *partido,
                     Date dataAtual, bool deferido) : Pessoa(nome, genero, dataDeNascimento, dataAtual), tipoDeputado(tipoDeputado),
                                                       numeroVotavel(numeroVotavel), eleito(eleito), numeroFederacao(numeroFederacao), 
                                                       legenda(legenda), deferido(deferido), partido(partido) {    }

int Candidato::getTipoDeputado() const
{
    return tipoDeputado;
}
int Candidato::getNumeroVotavel() const
{
    return numeroVotavel;
}
bool Candidato::isEleito() const
{
    return eleito;
}
int Candidato::getNumeroDeVotos() const
{
    return numeroDeVotos;
}
int Candidato::getNumeroFederacao() const
{
    return numeroFederacao;
}
bool Candidato::isLegenda() const
{
    return legenda;
}
bool Candidato::isDeferido() const
{
    return deferido;
}
void Candidato::incrementaNumeroVotos(int qtdVotos)
{
    numeroDeVotos += qtdVotos;
}
bool Candidato::isEleito_e_Deferido() const
{
    // cout << eleito << deferido << endl;
    return eleito && deferido;
}

Partido Candidato::getPartido() const{
    return *this->partido;
}


ostream& operator<<(ostream& os, const Candidato& c) {
    //set locale to ptbr
    if (c.getNumeroFederacao() == -1) {
        os << c.getNome() << " (" << c.getPartido().getSigla() << ", " << c.getNumeroDeVotos() << " votos)";        
    }
    else {
        os << "*" << c.getNome() << " (" << c.getPartido().getSigla() << ", " << c.getNumeroDeVotos() << " votos)";
    }

    return os;
}

bool Candidato::operator<(const Candidato &c) {
    int valor = c.getNumeroDeVotos() - this->numeroDeVotos;
    if (valor == 0) {
        return c.getIdade() - this->getIdade();
    }
    return valor < 0;
}
