#include "date.hpp"
#include <string.h>
#include <iostream>

Date::Date(string &data)
{

    size_t pos = 0;
    string token, delimiter = "/";

    for (int i = 0; (pos = data.find(delimiter)) != string::npos; i++)
    {
        token = data.substr(0, pos);
        if (i == 0)
            dia = stoi(token);

        else if (i == 1)
            mes = stoi(token);

        data.erase(0, pos + delimiter.length());
    }
    ano = stoi(data.substr(0, data.length()));
}

int Date::getDia() const
{
    return this->dia;
}
int Date::getMes() const
{
    return this->mes;
}
int Date::getAno() const
{
    return this->ano;
}

Date::~Date()
{
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d.getDia() << '/' << d.getMes() << '/' << d.getAno() << endl;
    return os;
}
