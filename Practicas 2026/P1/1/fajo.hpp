/*
    Practica 1 - Ejercicio 1
*/

#include <vector>
#include <iterator>
#include <istream>
using namespace std;

class fajo 
{
public:
    fajo(): v{0}, u{0} {}
    fajo(unsigned int v, unsigned int u): v{v}, u{u} {}
    unsigned int valor() const { return v; }
    unsigned int& valor() { return v; }
    unsigned int unidades() const { return u; }
    unsigned int& unidades() { return u; }
private:
    unsigned int v, u;
    // Valor y número de unidades de cada billete.
};

using fajos = std::vector<fajo>;

std::istream& operator >>(std::istream& fe, fajo& f)
{
    return fe >> f.valor() >> f.unidades();
}

std::istream& operator >>(std::istream& fe, fajos& f)
{
    istream_iterator<fajo> ife(fe), fin;
    copy(ife, fin, back_inserter(f));
    return fe;
}

std::ostream& operator <<(std::ostream& fs, const fajo& f)
{
    return fs << f.unidades() << " billete"
    << (f.unidades() == 1 ? "" : "s") << " de " << f.valor();
}

std::ostream& operator <<(std::ostream& fs, const fajos& f)
{
    copy(std::begin(f), std::end(f), std::ostream_iterator<fajo>(fs, "\n"));
    return fs;
}

