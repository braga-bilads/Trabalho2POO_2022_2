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

    int getDia();
    int getMes();
    int getAno();
    void dateprint();      
    ~Date();

    
};


#endif