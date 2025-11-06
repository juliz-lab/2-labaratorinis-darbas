#ifndef STUDENTAS_H //jei nedeklaruotas 
#define STUDENTAS_H //tai deklaruok

#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;

class Studentas
{
        string var_;
        string pav_;
        vector<int> paz_;
        int egz_;
        double gal_;
    public:
        Studentas(): egz_(0) {}
        Studentas(istringstream& iss); 
        inline string vardas() const { return var_;}
        inline string pavarde() const { return pav_;}
        inline double galutinis() const {return gal_;}
        ~Studentas(){}
};
#endif
