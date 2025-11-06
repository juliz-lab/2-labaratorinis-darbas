#include "Studentas.h"

Studentas::Studentas(istringstream& iss) {
    iss >> var_ >> pav_;
    int p, suma = 0;
    while (iss >> p)
    {
        paz_.push_back(p);
        suma += p;
    }
    suma -= p;
    egz_ = paz_.back();
    paz_.pop_back();
    gal_ = double(suma) / double(paz_.size()) * 0.4 + 0.6 * egz_;
    
}