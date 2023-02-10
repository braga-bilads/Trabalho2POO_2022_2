#ifndef PARTIDO_H
#define PARTIDO_H

#include <string>
#include "candidato.hpp"
#include <map>
#include <list>
using namespace std;
class Candidato;

/**
 * @brief Classe de Partido
 *
 */
class Partido
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
    /**
     * @brief Construct a new Partido
     *
     * @param numeroVotavel
     * @param sigla
     */
    Partido(int numeroVotavel, string sigla);

    /**
     * @brief Get  Numero Votavel
     *
     * @return int
     */
    int getNumeroVotavel() const;

    /**
     * @brief Get  Sigla
     *
     * @return string
     */
    string getSigla() const;

    /**
     * @brief Get Quantidade De Votos Nominais
     *
     * @return int
     */
    int getQuantidadeDeVotosNominais() const;

    /**
     * @brief Get Quantidade De Votos Legenda
     *
     * @return int
     */
    int getQuantidadeDeVotosLegenda() const;

    /**
     * @brief Get Quantidade Total De Votos
     *
     * @return int
     */
    int getQuantidadeTotalDeVotos() const;

    /**
     * @brief Get Quantidade De Eleitos
     *
     * @return int
     */
    int getQuantidadeDeEleitos() const;

    /**
     * @brief Get Quantidade De Vagas
     *
     * @return int
     */
    int getQuantidadeDeVagas() const;

    /**
     * @brief Get Candidato Mais Votado
     *
     * @return Candidato*
     */
    Candidato *getCandMaisVotado() const;

    /**
     * @brief Get Candidato Menos Votado
     *
     * @return Candidato*
     */
    Candidato *getCandMenosVotado() const;

    /**
     * @brief Adiciona um Candidato a lista de candidatos do Partido atual
     *
     * @param c
     */
    void addCandidato(Candidato &c);

    /**
     * @brief Incrementa Total de votos nominais do partido
     *
     * @param qtd
     */
    void incrementaVotosNominais(int qtd);

    /**
     * @brief Incrementa total de votos de Legenda do partido
     *
     * @param qtd
     */
    void incrementaVotosLegenda(int qtd);

    /**
     * @brief Incrementa total de Vagas
     *
     */
    void incrementaQuantidadeDeVagas();

    /**
     * @brief Ordena os candidatos por número de votos e seta os candidatos mais e menos votados
     *
     */
    void setCandidatoMenoseMaisVotado();

    /**
     * @brief Incrementa numero de eleitos
     *
     */
    void incrementaEleitos();

    /**
     * @brief Imprime todos os candidatos da lista de Candidatos
     *
     */
    void printCandidatos();
};

/**
 * @brief Compara partidos por total de votos
 *
 * @param p1
 * @param p2
 * @return true
 * @return false
 */
bool comparaPartidoTotalVotos(Partido *p1, Partido *p2);

/**
 * @brief Compara partidos por votos de Candidato mais votado
 *
 * @param p1
 * @param p2
 * @return true
 * @return false
 */
bool comparaPartidoCandMaisVotado(Partido *p1, Partido *p2);

/**
 * @brief Override do operador << para imprimir partido
 *
 * @param os
 * @param p
 * @return ostream&
 */
ostream &operator<<(ostream &os, const Partido &p);

#endif