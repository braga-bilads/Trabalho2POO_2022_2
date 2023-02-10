#ifndef PROCESSAMENTOARQ_H
#define PROCESSAMENTOARQ_H
#include "candidato.hpp"
#include "partido.hpp"
#include "date.hpp"
#include "sistemaeleitoral.hpp"
#include <vector>

/**
 * @brief Lê o Arquivo de Candidatos
 *        Cria candidatos e partidos dinamicamente alocando memória.
 *      
 * @param eleicao 
 */
void readConsultaCand(SistemaEleitoral &eleicao);

/**
 * @brief Lê Arquivo de Votos
 *        Contabiliza votos de todos os partidos e candidatos.
 * 
 * @param eleicao 
 */
void readVotos(SistemaEleitoral &eleicao);


#endif