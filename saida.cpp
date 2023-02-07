#include "saida.hpp"
#include <ostream>
#include <map>
#include <list>

static list<Candidato *> getValues(map<int, Candidato *> candidatos)
{
    map<int, Candidato *>::iterator itr;
    list<Candidato *> l;
    for (itr = candidatos.begin(); itr != candidatos.end(); itr++)
    {
        l.push_back(itr->second);
    }

    return l;
}

void geraSaida(SistemaEleitoral sisEleitoral)
{
    int qntdEleitos = sisEleitoral.getQtdVagas();
    cout << "Numero de vagas: " << qntdEleitos << endl
         << endl;
    if (sisEleitoral.getNumeroCargo() == 7)
    {
        cout << "Deputados estaduais eleitos:" << endl;
    }
    else if (sisEleitoral.getNumeroCargo() == 6)
    {
        cout << "Deputados federais eleitos:" << endl;
    }
    else
    {
        cout << "Cargo invalido" << endl;
        exit(1);
    }

    map<int, Candidato *> candidatos(sisEleitoral.getCandidatos());

    list<Candidato *> candidatosSorted(getValues(candidatos));
    candidatosSorted.sort();
    int i = 1;
    for (Candidato *c : candidatosSorted)
    {
        if (!c->isEleito())
            continue;
        cout << i << " - " << *c << endl;
        i++;
    }
    int menorNumeroVotos = 0;
    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    map<int, Candidato *> seriamEleitos_Majoritaria;
    map<int, Candidato *> beneficiadosMajoritaria;

    i = 1;
    for (Candidato *c : candidatosSorted)
    {
        if (i <= qntdEleitos)
        {
            if (!c->isDeferido())
                continue;
            cout << i << " - " << *c << endl;
            if (!c->isEleito())
                seriamEleitos_Majoritaria.insert({i, c});

            menorNumeroVotos = c->getNumeroDeVotos();
            i++;
        }
    }
    i = 1;
    for (Candidato *c : candidatosSorted)
    {
        if (c->isEleito_e_Deferido() && c->getNumeroDeVotos() < menorNumeroVotos)
        {
            beneficiadosMajoritaria.insert({i, c});
        }
        if (c->isDeferido())
            i++;
    }

    cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    for (map<int, Candidato *>::iterator itr = seriamEleitos_Majoritaria.begin();
         itr != seriamEleitos_Majoritaria.end();
         itr++)
    {

        cout << itr->first << " - " << *(itr->second) << endl;        
    }

    cout << "\nEleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    for (map<int, Candidato *>::iterator itr = beneficiadosMajoritaria.begin();
         itr != beneficiadosMajoritaria.end();
         itr++)
    {
        cout << itr->first << " - " << *(itr->second) << endl; 
    }
    cout << "\nVotação dos partidos e número de candidatos eleitos:" << endl;


    // map<int, Partido*> partidos(sisEleitoral.getPartidos());
    // list<Partido*> partidosSorted();




}