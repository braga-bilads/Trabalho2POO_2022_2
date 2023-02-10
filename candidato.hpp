#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include "pessoa.hpp"
#include "partido.hpp"

using namespace std;
class Partido;

class Candidato : public Pessoa
{
private:
    int tipoDeputado;
    int numeroVotavel;
    bool eleito;
    int numeroDeVotos = 0;
    int numeroFederacao;
    bool legenda;
    bool deferido;
    Partido* partido;

public:
    /**
     * @brief Construct a new Candidato
     * 
     * @param nome 
     * @param genero 
     * @param dataDeNascimento 
     * @param tipoDeputado 
     * @param numeroVotavel 
     * @param eleito 
     * @param numeroFederacao 
     * @param legenda 
     * @param partido 
     * @param dataAtual 
     * @param deferido 
     */
    Candidato(string nome, string genero, Date dataDeNascimento, int tipoDeputado, int numeroVotavel,
              bool eleito, int numeroFederacao, bool legenda, Partido* partido,
              Date dataAtual, bool deferido);
    
    /**
     * @brief Retorna o  Tipo do Deputado 
     * 
     * @return int 
     */
    int getTipoDeputado() const;

    /**
     * @brief Retorna Numero Votavel
     * 
     * @return int 
     */
    int getNumeroVotavel() const;

    /**
     * @brief Retorna se esta ou não eleito
     * 
     * @return true 
     * @return false 
     */
    bool isEleito() const;

    /**
     * @brief Get Numero De Votos
     * 
     * @return int 
     */
    int getNumeroDeVotos() const;

    /**
     * @brief Get Numero Federacao 
     * 
     * @return int 
     */
    int getNumeroFederacao() const; 

    /**
     * @brief Retorna se é ou não de legenda
     * 
     * @return true 
     * @return false 
     */
    bool isLegenda() const;

    /**
     * @brief Retorna se esta ou não deferido
     * 
     * @return true 
     * @return false 
     */
    bool isDeferido() const;
    
    /**
     * @brief Incrementa numero de votos 
     * 
     * @param qtdVotos 
     */
    void incrementaNumeroVotos(int qtdVotos);

    /**
     * @brief Retorna se esta eleito && deferido
     * 
     * @return true 
     * @return false 
     */
    bool isEleito_e_Deferido() const;

    /**
     * @brief Retorna seu Partido 
     * 
     * @return Partido 
     */
    Partido getPartido() const;

    /**
     * @brief Compara Candidatos
     * 
     * @param c 
     * @return true 
     * @return false 
     */
    bool operator<(const Candidato *c);
    
};


/**
 * @brief Define como imprimir um objeto Candidato*
 * 
 * @param os 
 * @param c 
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const Candidato& c);


/**
 * @brief Função que compara dois candidatos* com base no número de votos. Em caso de empate,
 * compara-se a idade
 * @param c1 
 * @param c2 
 * @return true 
 * @return false 
 */
bool compCand(Candidato *c1, Candidato *c2);


#endif