/*
    P1 - E1
*/
#ifndef CAJERO_HPP
#define CAJERO_HPP

#include "fajo.hpp"

class cajero
{
public:
    cajero();
    fajos reintegrar(const fajos& caja, unsigned int cantidad);
    const fajos& obtenerCaja() const {return caja;} 
private:
    void creaCaja();

private:
    fajos caja;
};

#endif