#ifndef STUDENTAS_H // jei nedeklaruotas
#define STUDENTAS_H // tai deklaruok

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

class Studentas : public Zmogus
{
private:
    vector<int> paz_;
    int egz_;
    double gal_, med_;

public:
    Studentas() : Zmogus(), egz_(0) {}
    Studentas(istringstream &iss);

    void SpausdintiInfo() const
    {
        std::cout << "Studentas :" << var_ << " " << pav_ << ", Egz.: " << egz_ << std::endl;
    }

    double Mediana();
    inline int egazaminas() const { return egz_; }
    inline double galutinis() const { return gal_; }
    inline double galutinisMed() const { return med_; }

    void setPaz(vector<int> &p) { paz_ = p; }
    void setEgz(int &e) { egz_ = e; }
    void setGal(double &g) { gal_ = g; }
    void setMed(double &m) { med_ = m; }

    ~Studentas()
    {
        paz_.clear();
        paz_.shrink_to_fit();
    }

    Studentas(const Studentas &senas) : Zmogus(senas)
    {
        egz_ = senas.egz_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;
    }

    Studentas &operator=(const Studentas &senas)
    {
        Zmogus::operator=(senas);
        egz_ = senas.egz_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Studentas &stud)
    {
        out << "Vardas: " << stud.var_ << ", pavarde: " << stud.pav_ << ", egzamino pazymys: " << stud.egz_ << std::endl;
        return out;
    }
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
