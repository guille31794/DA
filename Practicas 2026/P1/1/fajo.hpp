/*
    Practica 1 - Ejercicio 1
*/

#ifndef FAJO_HPP
#define FAJO_HPP

#include <vector>
#include <iostream>

class fajo 
{
public:
    fajo();
    fajo(unsigned int v, unsigned int u);

    unsigned int valor() const;
    unsigned int& valor();

    unsigned int unidades() const;
    unsigned int& unidades();

private:
    unsigned int v;
    unsigned int u;
};

using fajos = std::vector<fajo>;

bool operator<(const fajo& f1, const fajo& f2);
std::istream& operator>>(std::istream& fe, fajo& f);
std::ostream& operator<<(std::ostream& fs, const fajo& f);
std::istream& operator>>(std::istream& fe, fajos& f);
std::ostream& operator<<(std::ostream& fs, const fajos& f);

#endif