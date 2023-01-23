#include <string>

class Partido //implementa um comparador
{
private:
    // HashMap<Integer,Candidato> candidatos;
    int numero_votavel;
    string sigla;
    int quantidadeDeVotosNominais;
    int quantidadeDeVotosLegenda;
    int quantidadeTotalDeVotos;
    int quantidadeDeEleitos;
    int quantidadeDeVagas;
    Candidato candMaisvotado;
    Candidato candMenosvotado;
public:
    Partido(int numeroVotavel, string sigla);
    int getNumeroVotavel();
    string getSigla();
    int getQuantidadeDeVotosNominais();
    int getQuantidadeDeVotosLegenda();
    int getQuantidadeTotalDeVotos();
    int getQuantidadeDeEleitos();
    int getQuantidadeDeVagas();
    Candidato getCandMaisVotado();
    Candidato getCandMenosVotado();

    void addCandidato(Candidato c);
    void incrementaVotosNominais(int qtd);
    void incrementaVotosLegenda(int qtd);
    void incrementaQuantidadeDeVagas(); //soma um
    void setCandidatoMenoseMaisVotado(); // ordena os candidatos e seta o mais e menos votado
    

};