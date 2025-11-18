#ifndef STUDENTAS_H //jei nedeklaruotas 
#define STUDENTAS_H //tai deklaruok

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::istringstream;
using std::sort;

class Studentas
{
    string var_;
    string pav_;
    vector<int> paz_;
    int egz_;
    double gal_, med_;

    public:
        Studentas(): egz_(0) {} //random studentas
        // seteriu truksta.
        Studentas(istringstream& iss); 
        inline string vardas() const {return var_;}
        inline string pavarde() const {return pav_;}
        inline double galutinis() const {return gal_;}
        inline double galutinisMed() const {return med_;}
        double Mediana();
        void setVardas(string& v) {var_ = v;}
        void setPavarde(string& p) {pav_ = p;}
        void setPaz(vector <int>& p) {paz_ = p;}
        void setEgz(int& e) {egz_ = e;}
        void setGal(double& g) {gal_ = g;}
        void setMed(double& m) {med_ = m;}
        ~Studentas(){
            var_.clear();
            pav_.clear();
            paz_.clear();
            paz_.shrink_to_fit();
        }
        
};
