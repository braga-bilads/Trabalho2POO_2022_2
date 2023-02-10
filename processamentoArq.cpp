#include <iostream>
#include <string>
#include "processamentoArq.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <cctype>
#include <algorithm>

// Código para fazer trim nas strings retirado da internet
// https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
// trim from start (in place)

bool compare_pt_BR(const string &s1, const string &s2)
{
  locale loc = locale("pt_BR.UTF-8");
  const collate<char> &col = use_facet<collate<char>>(loc);
  return (col.compare(s1.data(), s1.data() + s1.size(),
                      s2.data(), s2.data() + s2.size()) < 0);
}
static inline void ltrim(string &s)
{
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch)
                               { return !isspace(ch); }));
}

// trim from end (in place)
static inline void rtrim(string &s)
{
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                    { return !isspace(ch); })
                .base(),
            s.end());
}

// trim from both ends (in place)
static inline void trim(string &s)
{
    rtrim(s);
    ltrim(s);
}
// trim from both ends (copying)
static inline string trim_copy(string s)
{
    trim(s);
    return s;
}

///////////////////////////////////////////////////////

string iso_8859_1_to_utf8(string &str)
{
    // adaptado de: https://stackoverflow.com/a/39884120 :-)
    string strOut;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80)
        {
            // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
            strOut.push_back(ch);
        }
        else
        {
            // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
            // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
            strOut.push_back(0b11000000 | (ch >> 6));
            // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
            strOut.push_back(0b10000000 | (ch & 0b00111111));
        }
    }
    return strOut;
}

void tiraAspas(string &str)
{
    str.erase(0, 1);
    str.erase(str.length() - 1);
}

vector<string> split(string &str)
{
    string chave;
    stringstream inputString(str);
    vector<string> linha_quebrada;

    while (getline(inputString, chave, ';'))
    {
        tiraAspas(chave);
        linha_quebrada.push_back(chave);
    }

    return linha_quebrada;
}
map<string, int> criaMapaCabealho(string &str)
{
    string chave;
    stringstream inputString(str);
    map<string, int> map;

    for (int i = 0; getline(inputString, chave, ';'); i++)
    {
        tiraAspas(chave);
        map.insert({chave, i});
    }

    return map;
}

static Partido *criaPartido(vector<string> &atributos, map<string, int> &coluna, SistemaEleitoral &sisEleitoral)
{
    int numPartido;
    string siglaPartido;

    numPartido = stoi(atributos[coluna["NR_PARTIDO"]]);

    if (!sisEleitoral.partidoExiste(numPartido))
    {
        // cria um novo partido
        siglaPartido = atributos[coluna["SG_PARTIDO"]];
        sisEleitoral.addPartido(make_pair(numPartido, new Partido(numPartido, siglaPartido)));
    }
    return sisEleitoral.getPartido(numPartido); // ja existe
}
int i = 1;

static void criaCandidato(vector<string> &atributos, map<string, int> &coluna, SistemaEleitoral &sisEleitoral, Partido *p)
{

    int nCargo = sisEleitoral.getNumeroCargo();

    int tipoDeputado; // 6 federal, 7 estadual
    int numeroVotavel;
    bool eleito;
    int numeroFederacao;
    bool legenda;
    bool deferido;
    string nome;
    string genero;

    // cout << stoi(situTurno) << endl;
    // cout << atributos[coluna["NM_TIPO_DESTINACAO_VOTOS"]] << endl;

    legenda = !compare_pt_BR(atributos[coluna["NM_TIPO_DESTINACAO_VOTOS"]], "Válido (legenda)");

      
    
    if (stoi(atributos[coluna["CD_SITUACAO_CANDIDATO_TOT"]]) != 2 &&
        stoi(atributos[coluna["CD_SITUACAO_CANDIDATO_TOT"]]) != 16) {
        deferido = false;        
    }
    else
        deferido = true;

    if (!legenda && !deferido)
        return; // não deferido nem legenda ignora
    
    tipoDeputado = stoi(atributos[coluna["CD_CARGO"]]);
    // cout << tipoDeputado << " e " << nCargo << endl;
    if (tipoDeputado != nCargo)
        return;
    
    numeroVotavel = stoi(atributos[coluna["NR_CANDIDATO"]]);
    nome = trim_copy(atributos[coluna["NM_URNA_CANDIDATO"]]);

    numeroFederacao = stoi(atributos[coluna["NR_FEDERACAO"]]);

    int gen = stoi(atributos[coluna["CD_GENERO"]]);
    if (gen == 2)
        genero = "Feminino";
    else if (gen == 4)
        genero = "Masculino";

    
    string situTurno = atributos[coluna["CD_SIT_TOT_TURNO"]];
    int x = stoi(situTurno);
    
    if (x == 3 || x == 2)
    {       
        
        sisEleitoral.incrementaQtdVagas();
        p->incrementaQuantidadeDeVagas();
        p->incrementaEleitos();
        eleito = true;
    }
    else
        eleito = false;
    sisEleitoral.addCandidato(*(new Candidato(nome, genero, Date(atributos[coluna["DT_NASCIMENTO"]]), tipoDeputado, numeroVotavel, eleito,
                                              numeroFederacao, legenda, p, sisEleitoral.getDataDaEleicao(), deferido)));
}

void readConsultaCand(SistemaEleitoral &sisEleitoral)
{
    ifstream consultaFile;
    // locale loc = locale("pt_BR.ISO8859-1");
    // consultaFile.imbue(loc);
    consultaFile.exceptions(ifstream::badbit); // para tratar exceções depois
    consultaFile.open(sisEleitoral.getPathConsulta());

    if (!consultaFile.is_open())
        exit(EXIT_FAILURE);
    string linha = "";
    // le o cabecalho
    getline(consultaFile, linha);
    map<string, int> coluna = criaMapaCabealho(linha);
    linha = "";
    // cada passagem no while é uma linha lida

    while (getline(consultaFile, linha))
    {
        string linha_utf8 = iso_8859_1_to_utf8(linha);
        vector<string> atributos = split(linha_utf8);
        Partido *partido = criaPartido(atributos, coluna, sisEleitoral);

        criaCandidato(atributos, coluna, sisEleitoral, partido);

        linha = "";
    }
    // sisEleitoral.printPartidos(sisEleitoral);
}
static void contaVotos(vector<string> &atributos, map<string, int> &coluna, SistemaEleitoral &sisEleitoral)
{


    if (stoi(atributos[coluna["CD_CARGO"]]) != sisEleitoral.getNumeroCargo()){
        return;
    }

    int numero = stoi(atributos[coluna["NR_VOTAVEL"]]);

    if (numero == 95 || numero == 96 || numero == 97 || numero == 98)
        return;

    int votos = stoi(atributos[coluna["QT_VOTOS"]]);

    if (!sisEleitoral.candidatoExiste(numero))
    {
        if ((sisEleitoral.partidoExiste(numero)))
        {
            Partido *p = sisEleitoral.getPartido(numero);
            p->incrementaVotosLegenda(votos);
            sisEleitoral.incTotalVotosLegenda(votos);
        }
        else
        {
            return;
        }
    }
    else
    {
        Candidato *c = (sisEleitoral.getCandidato(numero));
        c->incrementaNumeroVotos(votos);

        if (!c->isLegenda())
        {
            sisEleitoral.incTotalVotosNominais(votos);
        }
        else
            sisEleitoral.incTotalVotosLegenda(votos);
    }
}

void readVotos(SistemaEleitoral &sisEleitoral)
{
    ifstream votosFIle;
    // locale loc = locale("pt_BR.UTF-8");
    // votosFIle.imbue(loc);
    votosFIle.exceptions(ifstream::badbit);
    votosFIle.open(sisEleitoral.getPathVotos());
    
    string linha = "";

    getline(votosFIle, linha);
    map<string, int> coluna = criaMapaCabealho(linha);
    linha = "";
 
    while (getline(votosFIle, linha))
    {

        string linha_utf8 = iso_8859_1_to_utf8(linha);
        vector<string> atributos = split(linha);
        contaVotos(atributos, coluna, sisEleitoral);

        linha = "";
    }
}