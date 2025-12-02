#include "Studentas.h"
#include <iostream>
/**
 * @file Studentas.cpp
 * Realizuotas Medianos skaičiavimo funkcija ir studentų nuskaitymo funkcija.
 */

 /**
 * @brief Apskaičiuoja studento pažymių medianą.
 *
 * Funkcija kopijuoja pažymių vektorių, surikiuoja jį ir apskaičiuoja medianą.
 * Jei pažymių skaičius nelyginis, grąžinama vidurinio elemento reikšmė.
 * Jei lyginis, grąžinamas dviejų vidurinių elementų vidurkis.
 *
 * @return Studento pažymių mediana.
 */
double Studentas::Mediana()
{
    vector<int> temp = paz_;
    sort(temp.begin(), temp.end());
    if (temp.size() % 2 != 0)
    {
        return temp[temp.size() / 2];
    }
    else
    {
        return (temp[temp.size() / 2]) + temp[(temp.size() / 2) - 1] / 2.0;
    }
}

/**
 * @brief Konstruktorius, nuskaitantis studento duomenis iš istringstream srauto.
 *
 * Tikisi įvesties formatu: vardas pavarde [pažymiai] egzaminas.
 * Paskutinis įvestas pažymys laikomas egzamino rezultatu.
 * Apskaičiuojamas galutinis balas pagal vidurkį ir pagal medianą.
 *
 * @param iss Duomenų srautas su vieno studento informacija.
 */
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
