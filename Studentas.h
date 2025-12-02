#ifndef STUDENTAS_H // jei nedeklaruotas
#define STUDENTAS_H // tai deklaruok

/**
 * @file Studentas.h
 * Čia apibrėžta išvestinė klasė Studentas.
 * 
 * Čia saugomi studento pažymiai ir egzamino rezultatas.
 */

#include "Zmogus.h"

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using std::istream;
using std::istringstream;
using std::ostream;
using std::sort;
using std::string;
using std::vector;
/** 
* @class Studentas
 * @brief Išvestinė klasė iš Zmogus, apibrėžianti studento savybes.
 *
 * Klasėje saugomi studento pažymiai ir egzamino rezultatas. Realizuota 
 * SpausdintiInfo() funkcija ir operatoriai.
 */
class Studentas : public Zmogus
{
private:
    vector<int> paz_; ///< Studento pažymiai
    int egz_; ///< Studento egzamino rezultatas 
    double gal_, med_; ///< Studento galutinis pažymys imant vidurkį ir medianą.

public:

    /// @brief Priskiriamos bendros savybės žmogui ir egzamino rezultatas išsaugomas kaip 0.
    Studentas() : Zmogus(), egz_(0) {}

    /**
     * @brief Konstruktorius, nuskaitantis studento duomenis iš istringstream.
     * @param iss Duomenų srautas su vieno studento informacija.
     */
    Studentas(istringstream &iss);

    /**
     * @brief Spausdinamas studentas.
     */
    void SpausdintiInfo() const
    {
        std::cout << "Studentas :" << var_ << " " << pav_ << ", Egz.: " << egz_ << std::endl;
    }

    double Mediana();
    /// @return Egzamino rezultatas.
    inline int egazaminas() const { return egz_; }

    /// @return Galutinis balas pagal vidurkį.
    inline double galutinis() const { return gal_; }

    /// @return Galutinis balas pagal medianą.
    inline double galutinisMed() const { return med_; }

    /// @brief Nustato pažymių masyvą.
    void setPaz(vector<int> &p) { paz_ = p; }

    /// @brief Nustato egzamino rezultatą.
    void setEgz(int &e) { egz_ = e; }
    /// @brief Nustato galutinį rezultatą pagal vidurkį.
    void setGal(double &g) { gal_ = g; }
    /// @brief Nustato galutinį balą pagal medianą.
    void setMed(double &m) { med_ = m; }

    /**
     * @brief Destruktorius. Atlaisvina atmintį.
     */
    ~Studentas()
    {
        paz_.clear();
        paz_.shrink_to_fit();
    }

    /**
     * @brief Kopijavimo konstruktorius.
     * @param senas Kopijuojamas objektas.
     */
    Studentas(const Studentas &senas) : Zmogus(senas)
    {
        egz_ = senas.egz_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;
    }

    /**
     * @brief Kopijavimo priskyrimo operatorius.
     * @param senas Kopijuojamas objektas.
     * @return Nuoroda į priskirtą objektą.
     */
    Studentas &operator=(const Studentas &senas)
    {
        Zmogus::operator=(senas);
        egz_ = senas.egz_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;

        return *this;
    }

    /**
     * @brief Išvedimo operatorius.
     * @param out Išvesties srautas.
     * @param stud Studentas, kurį norima išvesti.
     */
    friend ostream &operator<<(ostream &out, const Studentas &stud)
    {
        out << "Vardas: " << stud.var_ << ", pavarde: " << stud.pav_ << ", egzamino pazymys: " << stud.egz_ << std::endl;
        return out;
    }

    /**
     * @brief Įvedimo operatorius. Leidžia vartotojui įvesti studento duomenis.
     *
     * Tikimasi įvesties formatu:
     * vardas pavarde pažymiai (paskutinis turi būti 0) egzaminas
     *
     * @param in Įvesties srautas.
     * @param stud Studentas, į kurį įrašomi duomenys.
     */
    friend istream &operator>>(istream &in, Studentas &stud)
    {
        std::cout << "Iveskite studento varda, pavarde, pazymius (paskutini iveskite 0) ir egzamino pazymi." << std::endl;
        in >> stud.var_ >> stud.pav_;
        int temp;
        while (true)
        {
            in >> temp;
            stud.paz_.push_back(temp);
            if (temp == 0)
                break;
        }
        in >> stud.egz_;
        return in;
    }
};

#endif
