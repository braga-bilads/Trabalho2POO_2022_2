#include "saida.hpp"
#include <ostream>
#include <iomanip>
#include <map>
#include <list>

/**
 * @brief Itera sobre o mapa de candidatos e retorna uma lista com os candidatos
 *
 * @param candidatos
 * @return list<Candidato *>
 */
static list<Candidato *> getValuesCand(map<int, Candidato *> candidatos)
{
    map<int, Candidato *>::iterator itr;
    list<Candidato *> l;
    for (itr = candidatos.begin(); itr != candidatos.end(); itr++)
    {
        l.push_back(itr->second);
    }

    return l;
}

/**
 * @brief Itera sobre o mapa de partidos e retorna uma lista com os partidos
 *
 * @param partidos
 * @return list<Partido *>
 */
static list<Partido *> getValuesPartido(map<int, Partido *> partidos)
{
    map<int, Partido *>::iterator itr;
    list<Partido *> l;
    for (itr = partidos.begin(); itr != partidos.end(); itr++)
    {
        l.push_back(itr->second);
    }

    return l;
}

/**
 * @brief Retorna a porcentagem de a sobre b
 *
 * @param a
 * @param b
 * @return double
 */
static double porcentagem(double a, double b)
{
    return (a / b * 100);
}

/**
 * @brief Gera os relatórios conforme especificado
 * 
 * @param sisEleitoral 
 */
void geraSaida(SistemaEleitoral &sisEleitoral)
{
    cout.imbue(locale("pt_BR.UTF-8"));
    // relatório #1
    int qntdEleitos = sisEleitoral.getQtdVagas();

    cout << "Número de vagas: " << qntdEleitos << endl
         << endl;
    // verifica se será analisado deputados federais ou estaduais
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

    list<Candidato *> candidatosSorted(getValuesCand(candidatos));
    // ordena os candidatos com compCand
    try
    {
        candidatosSorted.sort(compCand);
    }
    catch (...)
    {
        cerr << "Erro ao ordenar candidatos\n";
        exit(1);
    }
    int i = 1;
    // relatório #2
    for (Candidato *c : candidatosSorted)
    {
        if (!c->isEleito())
            continue;
        cout << i << " - " << *c << endl;
        i++;
    }
    int menorNumeroVotos = 0;
    cout << "\nCandidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
    // inicializa dois mapas com os candidatos que seriam eleitos caso a eleição fosse majoritária
    //  e um dos candidatos que foram beneficiados por esse tipo de eleição
    map<int, Candidato *> seriamEleitos_Majoritaria;
    map<int, Candidato *> beneficiadosMajoritaria;

    i = 1;
    //
    // relatório #3
    for (Candidato *c : candidatosSorted)
    {
        if (i <= qntdEleitos)
        {
            if (!c->isDeferido())
                continue;
            cout << i << " - " << *c << endl;
            // adiciona no mapa de seriam eleitos candidatos que tiverem votos suficiente mas que não foram eleitos
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
            // preenche o mapa dos beneficiados
            beneficiadosMajoritaria.insert({i, c});
        }
        if (c->isDeferido())
            i++;
    }

    cout << "\nTeriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    // relatório #4
    for (map<int, Candidato *>::iterator itr = seriamEleitos_Majoritaria.begin();
         itr != seriamEleitos_Majoritaria.end();
         itr++)
    {

        cout << itr->first << " - " << *(itr->second) << endl;
    }

    cout << "\nEleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    // relatório #5
    for (map<int, Candidato *>::iterator itr = beneficiadosMajoritaria.begin();
         itr != beneficiadosMajoritaria.end();
         itr++)
    {
        cout << itr->first << " - " << *(itr->second) << endl;
    }
    cout << "\nVotação dos partidos e número de candidatos eleitos:" << endl;

    map<int, Partido *> partidos(sisEleitoral.getPartidos());
    list<Partido *> partidosSorted(getValuesPartido(partidos));
    try
    {
        // ordena os partidos com 'comparaPartidoTotalVotos
        partidosSorted.sort(comparaPartidoTotalVotos);
    }
    catch (...)
    {
        cerr << "Erro ao ordenar os partido\n";
        exit(1);
    }

    i = 1;
    // inicializa uma lista de partidos que receberam ao menos um voto
    list<Partido *> partidosComVotos;
    // relatório #6
    for (Partido *p : partidosSorted)
    {
        cout << i << " - " << *p << endl;
        i++;

        if (p->getQuantidadeTotalDeVotos() != 0)
        {
            p->setCandidatoMenoseMaisVotado();
            partidosComVotos.push_back(p);
        }
    }

    cout << "\nPrimeiro e último colocados de cada partido:\n";

    i = 1;
    // Ordena partidos com comparaPartidoCandMaisVotado
    partidosComVotos.sort(comparaPartidoCandMaisVotado);
    // relatório #7
    for (Partido *p : partidosComVotos)
    {
        Candidato *cMaisVotado = p->getCandMaisVotado();
        Candidato *cMenosVotado = p->getCandMenosVotado();
        if (cMaisVotado == NULL || cMenosVotado == NULL)
        {
            continue;
        }
        string votos = "";
        if (cMenosVotado->getNumeroDeVotos() > 1)
        {
            votos = " votos)";
        }
        else
        {
            votos = " voto)";
        }

        cout << to_string(i) + " - " + p->getSigla() + " - " << to_string(p->getNumeroVotavel()) << ", " << cMaisVotado->getNome() << " ("
             << to_string(cMaisVotado->getNumeroVotavel()) << ", " << cMaisVotado->getNumeroDeVotos() << " votos"
             << ") / "
             << cMenosVotado->getNome() << " (" << to_string(cMenosVotado->getNumeroVotavel()) << ", " << cMenosVotado->getNumeroDeVotos()
             << votos << endl;

        i++;
    }

    int masculino = 0, feminino = 0;
    int menorque30 = 0, entre30e40 = 0, entre40e50 = 0, entre50e60 = 0, maiorque60 = 0;
    // contabiliza a idade e o gênero dos deputados
    for (Candidato *c : getValuesCand(candidatos))
    {

        if (!c->isEleito_e_Deferido())
            continue;

        if (c->getIdade() < 30)
            menorque30++;
        else if (c->getIdade() >= 30 && c->getIdade() < 40)
            entre30e40++;
        else if (c->getIdade() >= 40 && c->getIdade() < 50)
            entre40e50++;
        else if (c->getIdade() >= 50 && c->getIdade() < 60)
            entre50e60++;
        else
            maiorque60++;

        if (c->getGenero() == "Feminino")
            masculino++;
        else if (c->getGenero() == "Masculino")
            feminino++;
    }
    // #relatório 8
    cout << "\nEleitos, por faixa etária (na data da eleição):\n";
    // imprime a faixa etária e a porcentagem de cada faixa etária com a quantidade
    // de eletios
    // o mesmo é feito para cada gênero
    cout << fixed << setprecision(2);
    cout << "      Idade < 30: " << menorque30 << " (" << porcentagem((double)menorque30, (double)qntdEleitos) << "%)" << endl;
    cout << "30 <= Idade < 40: " << entre30e40 << " (" << porcentagem((double)entre30e40, (double)qntdEleitos) << "%)" << endl;

    cout << "40 <= Idade < 50: " << entre40e50 << " (" << porcentagem((double)entre40e50, (double)qntdEleitos) << "%)" << endl;

    cout << "50 <= Idade < 60: " << entre50e60 << " (" << porcentagem((double)entre50e60, (double)qntdEleitos) << "%)" << endl;

    cout << "60 <= Idade     : " << maiorque60 << " (" << porcentagem((double)maiorque60, (double)qntdEleitos) << "%)" << endl;

    // relatório #9
    cout << "\nEleitos, por gênero:" << endl;
    cout << "Feminino: " << feminino << " (" << porcentagem((double)feminino, (double)qntdEleitos) << "%)" << endl;
    cout << "Masculino: " << masculino << " (" << porcentagem((double)masculino, (double)qntdEleitos) << "%)" << endl;

    int numVotosNominais = sisEleitoral.getTotalVotosNominais();
    int numVotosLegenda = sisEleitoral.getTotalVotosLegenda();
    int numVotosTotais = numVotosLegenda + numVotosNominais;
    // relatório #10
    cout << "\nTotal de votos válidos:    " << numVotosTotais << endl;
    cout << "Total de votos nominais:   " << numVotosNominais << " (" << porcentagem(numVotosNominais, numVotosTotais) << "%)" << endl;
    cout << "Total de votos de legenda: " << numVotosLegenda << " (" << porcentagem(numVotosLegenda, numVotosTotais) << "%)" << endl;
    cout.imbue(locale("C"));
}
