#include <string>
#include "pessoa.hpp"
#include "partido.hpp"

using namespace std;
class Candidato : public Pessoa
{
private:
    int tipoDeputado;
    int numeroVotavel;
    bool eleito;
    int numeroDeVotos;
    int numeroFederacao;
    bool legenda;
    bool deferido;
    Date dataAtual;

public:
    Candidato(string nome, int genero, Date dataDeNascimento, int tipoDeputado, int numeroVotavel,
              bool eleito, int numeroFederacao, bool legenda, Partido partido,
              Date dataAtual, bool deferido);
    
    int getTipoDeputado();
    int getNumeroVotavel();
    bool isEleito();
    int getNumeroDeVotos();
    int getNumeroFederacao();
    bool isLegenda();
    bool isDeferido();
    void incrementaNumeroVotos(int qtdVotos);
    bool isEleito_e_Deferido();


};