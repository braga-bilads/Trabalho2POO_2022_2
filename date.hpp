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
    /**
     * @brief Construct a new Date 
     * 
     */
    Date(){ dia = 0; mes = 0; ano = 0; }

    /**
     * @brief Construct a new Date from another
     * 
     * @param data 
     */
    Date(string &data);

    /**
     * @brief Get Dia 
     * 
     * @return int 
     */
    int getDia() const;

    /**
     * @brief Get Mes 
     * 
     * @return int 
     */
    int getMes() const;

    /**
     * @brief Get Ano 
     * 
     * @return int 
     */
    int getAno() const;   

};


#endif