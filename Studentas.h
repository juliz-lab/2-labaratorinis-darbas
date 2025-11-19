#ifndef STUDENTAS_H // jei nedeklaruotas
#define STUDENTAS_H // tai deklaruok

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::istringstream;
using std::sort;
using std::string;
using std::vector;

class Studentas
{
    string var_;
    string pav_;
    vector<int> paz_;
    int egz_;
    double gal_, med_;

public:
    Studentas() : egz_(0) {} // random studentas
    // seteriu truksta.
    Studentas(istringstream &iss);
    inline string vardas() const { return var_; }
    inline string pavarde() const { return pav_; }
    inline double galutinis() const { return gal_; }
    inline double galutinisMed() const { return med_; }
    double Mediana();
    void setVardas(string &v) { var_ = v; }
    void setPavarde(string &p) { pav_ = p; }
    void setPaz(vector<int> &p) { paz_ = p; }
    void setEgz(int &e) { egz_ = e; }
    void setGal(double &g) { gal_ = g; }
    void setMed(double &m) { med_ = m; }
    ~Studentas()
    {
        var_.clear();
        pav_.clear();
        paz_.clear();
        paz_.shrink_to_fit();
    }
    Studentas(const Studentas &senas)
    {
        cout << "Iskviestas kopijavimo konstruktorius." << endl;
        egz_ = senas.egz_;
        pav_ = senas.pav_;
        var_ = senas.var_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;
    }
    Studentas &operator=(const Studentas &senas)
    {
        cout << "Iskviestas priskirimo operatorius." << endl;
        egz_ = senas.egz_;
        pav_ = senas.pav_;
        var_ = senas.var_;
        paz_ = senas.paz_;
        med_ = senas.med_;
        gal_ = senas.gal_;

        return *this;
    }
};

#endif
