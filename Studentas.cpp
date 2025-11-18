#include "Studentas.h"

double Studentas::Mediana()
{
    sort(paz_.begin(), paz_.end());
    if (paz_.size() % 2 != 0)
    {
        return paz_[paz_.size() / 2];
    }
    else
    {
        return (float(paz_[paz_.size() / 2]) + paz_[(paz_.size() / 2) - 1]) / 2;
    }
}

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
    med_ = Mediana() * 0.4 + 0.6 * egz_;
    
}
