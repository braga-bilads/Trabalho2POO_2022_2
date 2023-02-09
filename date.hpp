#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;
class Date
{
private:
    int dia;
    int mes;
    int ano;

public:
    Date(){ dia = 0; mes = 0; ano = 0; }
    Date(string &data);

    int getDia() const;
    int getMes() const;
    int getAno() const;   

};


#endif