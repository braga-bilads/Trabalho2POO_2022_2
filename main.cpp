#include <iostream>
#include "candidato.hpp"
#include "partido.hpp"
#include "date.hpp"
#include "sistemaeleitoral.hpp"
#include "processamentoArq.hpp"

#include <string>

using namespace std;

void swap(string &str1, string &str2) {
    return;
}

int main(int argc, const char** argv) {
    
    if (argc != 5)  {
        cout << "USO: java -jar deputados.jar <opção_de_cargo> <caminho_arquivo_candidatos> <caminho_arquivo_votacao> <data>" << endl;
        exit(1);
    }
    string numeroCargo(argv[1]);
    string pathConsulta(argv[2]);
    string pathVotos(argv[3]);
    string data(argv[4]);
    
    Date d(data);
    
    SistemaEleitoral eleicao(numeroCargo, pathConsulta, pathVotos, d);
    ProcessamentoArq pa;
    pa.readConsultaCand(eleicao);
    pa.readVotos(eleicao);



    return 0;
}