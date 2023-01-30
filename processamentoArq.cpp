#include <iostream>
#include <string>
#include "processamentoArq.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <locale>
#include <algorithm>

bool compare_pt_BR(const string &s1, const string &s2)
{
    locale loc = locale("pt_BR.UTF-8");
    const collate<char> &col = use_facet<collate<char>>(loc);
    return (col.compare(s1.data(), s1.data() + s1.size(),
                        s2.data(), s2.data() + s2.size()) < 0);
}

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

void ProcessamentoArq::readConsultaCand(SistemaEleitoral &eleicao)
{
    ifstream consultaFile;
    // locale loc = locale("pt_BR.ISO8859-1");
    // consultaFile.imbue(loc);
    consultaFile.exceptions(ifstream::badbit); // para tratar exceções depois
    consultaFile.open("candidatos.csv");

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

        //exemplo: pegar o valor da coluna "CD_CARGO"
        // auto it = coluna.find("CD_CARGO");
        // string dadoLido = atributos[it->second];
        // cout << dadoLido << endl;
        linha = "";
    }
}
void ProcessamentoArq::readVotos(SistemaEleitoral &eleicao)
{
    ifstream votosFIle;
    // locale loc = locale("pt_BR.ISO8859-1");
    // votosFIle.imbue(loc);
    votosFIle.exceptions(ifstream::badbit);
    votosFIle.open("votacao.csv");

    string linha = "";

    getline(votosFIle, linha);
    map<string, int> coluna = criaMapaCabealho(linha);       
    linha = "";    

    
    while (getline(votosFIle, linha)) {
        string linha_utf8 = iso_8859_1_to_utf8(linha);
        vector<string> atributos = split(linha_utf8);
        auto it = coluna.find("NM_VOTAVEL");                       
        linha = "";
    }
}