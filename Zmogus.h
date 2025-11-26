#ifndef ZMOGUS_H // jei nedeklaruotas
#define ZMOGUS_H // tai deklaruok

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


class Zmogus
{
protected:
    string var_;
    string pav_;

public:
    virtual void SpausdintiInfo() const = 0;

    inline string vardas() const { return var_; }
    inline string pavarde() const { return pav_; }

    void setVardas(const string &v) { var_ = v; }
    void setPavarde(const string &p) { pav_ = p; }

    Zmogus() = default;

    virtual ~Zmogus()
    {
        var_.clear();
        pav_.clear();
    }
    Zmogus(const Zmogus &senas)
    {
        pav_ = senas.pav_;
        var_ = senas.var_;
    }
    Zmogus &operator=(const Zmogus &senas)
    {
        pav_ = senas.pav_;
        var_ = senas.var_;

        return *this;
    }
};

#endif
