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

    Date(string &data);

    int getDia() const;
    int getMes() const;
    int getAno() const;   

};


#endif