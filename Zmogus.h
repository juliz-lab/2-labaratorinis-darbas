#ifndef ZMOGUS_H // jei nedeklaruotas
#define ZMOGUS_H // tai deklaruok

/**
 * @file Zmogus.h
 * Čia apibrėžta abstrakti Žmogaus bazinė klasė.
 * 
 * Ši klasė yra visų studentų pagrindas.
 * Joje saugomi bendri duomenys apie studentą, t.y., žmogų.
 * Taip pat aprašyti metodai, būtini realizuoti išvestinėse klasėse.
 */

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
 * @class Zmogus
 * @brief Bazinė klasė Zmogus su pagrindinėm žmogaus savybėm.
 * 
 * Klasėje saugomi žmoguas vardas ir pavardė, o funkcija SpausdintiInfo()
 * paliekama realizuoti išvestinėms klasėms.
 */
class Zmogus
{
protected:
    string var_; ///< Žmogaus vardas
    string pav_; ///< Žmogaus pavardė

public:
    /**
     * @brief Virtuali funkcija, kuri turi būti realizuota išvestinėse klasėse.
     */
    virtual void SpausdintiInfo() const = 0;

    /// @return Žmogaus vardas
    inline string vardas() const { return var_; }

    /// @return Žmogaus pavardė
    inline string pavarde() const { return pav_; }

    /// @brief Nustato žmogaus vardą.
    void setVardas(const string &v) { var_ = v; }

    /// @brief Nustato žmogaus pavardę.
    void setPavarde(const string &p) { pav_ = p; }

    /// @brief Numatytaisiais nustatymais sukurtas konstruktorius.
    Zmogus() = default;

    /// @brief Virtualus destruktorius.
    virtual ~Zmogus()
    {
        var_.clear();
        pav_.clear();
    }
    /// @brief Kopijavimo konstruktorius.
    Zmogus(const Zmogus &senas)
    {
        pav_ = senas.pav_;
        var_ = senas.var_;
    }
    /// @brief Kopijavimo pirskyrimo operatorius.
    Zmogus &operator=(const Zmogus &senas)
    {
        pav_ = senas.pav_;
        var_ = senas.var_;

        return *this;
    }
};

#endif
