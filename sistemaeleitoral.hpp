#ifndef SISTEMAELEITORAL_H
#define SISTEMAELEITORAL_H

#include <iostream>
#include <string>
#include "candidato.hpp"
#include "partido.hpp"
#include "date.hpp"

using namespace std;

/**
 * @brief Classe SINGLETON para armazenar dados da Eleição
 * 
 */
class SistemaEleitoral
{
private:
    map<int, Partido *> partidos;
    map<int, Candidato *> candidatos;
    int numeroCargo;
    Date dataDaEleicao;
    int qtdVagas;
    string pathConsulta;
    string pathVotos;
    int totalVotosLegenda;
    int totalVotosNominais;

public:
    /**
    * @brief Construct a new Sistema Eleitoral object
    * 
    * @param numeroCargo 
    * @param pathConsulta 
    * @param pathVotos 
    * @param dataDaEleicao 
    */
    SistemaEleitoral(string &numeroCargo, string pathConsulta, string pathVotos, Date dataDaEleicao);

    /**
     * @brief Get Numero Cargo
     * 
     * @return int 
     */
    int getNumeroCargo() const;

    /**
     * @brief Incrementa o Total de Votos de Legenda
     * 
     * @param qtd 
     */
    void incTotalVotosLegenda(int qtd);

    /**
     * @brief Incrementa total de Votos Nominais
     * 
     * @param qtd 
     */
    void incTotalVotosNominais(int qtd);

    /**
     * @brief Get Total Votos Legenda
     * 
     * @return int 
     */
    int getTotalVotosLegenda() const;

    /**
     * @brief Get Total Votos Nominais
     * 
     * @return int 
     */
    int getTotalVotosNominais() const;

    /**
     * @brief Get Qtd Vagas
     * 
     * @return int 
     */
    int getQtdVagas() const;

    /**
     * @brief Incrementa o numero de Vagas (+1)
     * 
     */
    void incrementaQtdVagas();

    /**
     * @brief Get Data Da Eleicao
     * 
     * @return Date 
     */
    Date getDataDaEleicao() const;

    /**
     * @brief Get Path Consulta 
     * 
     * @return string 
     */
    string getPathConsulta() const;

    /**
     * @brief Get Path Votos
     * 
     * @return string 
     */
    string getPathVotos() const;

    /**
     * @brief Adiciona um Candidato ao mapa de candidatos
     * 
     * @param c 
     */
    void addCandidato(Candidato &c);

    /**
     * @brief Retorna cópia do mapo de Partidos 
     * 
     * @return map<int,Partido*> 
     */
    map<int,Partido*> getPartidos() const;

    /**
     * @brief Retorna cópia do mapo de Candidatos
     * 
     * @return map<int,Candidato*> 
     */
    map<int,Candidato*> getCandidatos() const;

    /**
     * @brief Printa todos os partidos no mapo de partidos
     * 
     * @param sisEleitoral 
     */
    void printPartidos(SistemaEleitoral &sisEleitoral);

    /**
     * @brief Conta quantas vezes o Partido aparece no mapa
     * 
     * @param numPartido 
     * @return int 
     */
    int partidosCount(int numPartido);

    /**
     * @brief Adiciona um partido ao mapa de Partidos
     * 
     * @param par - <int,Partido*>
     */
    void addPartido(pair<int,Partido*> par);

    /**
     * @brief Retorna um partido* pelo numero caso este exista no mapa
     * 
     * @param numPartido 
     * @return Partido* 
     */
    Partido* getPartido(int numPartido);

    /**
     * @brief Retorna um Candidato* pelo numero caso este exista no mapa
     * 
     * @param num 
     * @return Candidato* 
     */
    Candidato* getCandidato(int num);

    /**
     * @brief Conta quantas vezes o candidato aparece no mapa
     * 
     * @param numero 
     * @return int 
     */
    int candidatosCount(int numero);

    /**
     * @brief Verifica se o Candidato existe no mapa
     * 
     * @param numero 
     * @return true - existe 
     * @return false - não existe
     */
    bool candidatoExiste(int numero);

    /**
     * @brief Verifica se o Partido existe no mapa
     * 
     * @param numero 
     * @return true - existe
     * @return false - não existe
     */
    bool partidoExiste(int numero);
    
    /**
     * @brief Destroi o Sistema Eleitoral e os
     *        Partidos e Candidatos alocados dinamicamente
     * 
     */
    ~SistemaEleitoral(){
        for(auto it = this->partidos.begin(); it != partidos.end() ; it++){
            delete it->second;
        }
        for(auto it = this->candidatos.begin(); it != candidatos.end() ; it++){
            delete it->second;
        }
    }

};

#endif