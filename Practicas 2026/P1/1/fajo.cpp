#include "fajo.hpp"

fajo::fajo()
    : v{0}, u{0}
{}

fajo::fajo(unsigned int v, unsigned int u)
    : v{v}, u{u}
{}

unsigned int fajo::valor() const {
    return v;
}

unsigned int& fajo::valor() {
    return v;
}

unsigned int fajo::unidades() const {
    return u;
}

unsigned int& fajo::unidades() {
    return u;
}

bool operator<(const fajo& f1, const fajo& f2) {
    return f1.valor() * f1.unidades() < f2.valor() * f2.unidades();
}

std::istream& operator>>(std::istream& fe, fajo& f) {
    fe >> f.valor() >> f.unidades();
    return fe;
}

std::ostream& operator<<(std::ostream& fs, const fajo& f) {
    fs << f.valor() << " " << f.unidades();
    return fs;
}

std::istream& operator>>(std::istream& fe, fajos& f) {
    fajo aux;
    while (fe >> aux) {
        f.push_back(aux);
    }
    return fe;
}

std::ostream& operator<<(std::ostream& fs, const fajos& f) {
    for (const auto& elemento : f) {
        fs << elemento << "\n";
    }
    return fs;
}