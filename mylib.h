
/**
 * @file mylib.h
 * Čia apibrėžtos visos naudojamos funkcijos. 
 */

 #include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random> 
#include <fstream>
#include <chrono>
#include <map>
#include <list>
#include <chrono>
#include <iterator>


#include "Zmogus.h"
#include "Studentas.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::istringstream; // stringe esančių žodžių sk skaičiavimui
using std::left;
using std::list;
using std::map;
using std::move;
using std::mt19937;
using std::ofstream;
using std::partition;
using std::random_device;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::stringstream;
using std::to_string;
using std::uniform_int_distribution;
using std::vector;
using std::ws;

void rusiuok_vect(vector<Studentas> &konteineris, char pagal);
void spausdink_grupe(const vector <Studentas> &vekt, string tipas);

/**
 * @brief Padalija studentų vektorių į dvi grupes pagal galutinį balą.
 * 
 * Funkcija sukuria du naujus vektorius: vieną moksliukams 
 * (galutinis balas >= 5.0) ir vieną nemoksoms 
 * (galutinis balas < 5.0).
 * 
 * Iš paduoto studentų sąrašo atitinkamai kiekvienas studentas yra 
 * priskiriamas vienai iš grupių.
 * 
 * @param Grupe Pradinis visų studentų vektorius.
 */
void pasiskirstymas_vector_1(const vector<Studentas> &Grupe, const int &irasu_sk);

/**
 * @brief Padalija studentų sąrašą į dvi grupes pagal galutinį balą.
 * 
 * Funkcija sukuria du naujus sąrašus: vieną moksliukams 
 * (galutinis balas >= 5.0) ir vieną nemoksoms 
 * (galutinis balas < 5.0).
 * 
 * Iš paduoto studentų sąrašo atitinkamai kiekvienas studentas yra 
 * priskiriamas vienai iš grupių.
 * 
 * @param Grupe Pradinis visų studentų vektorius.
 */
void pasiskirstymas_list_1(const list<Studentas> &Grupe, const int &irasu_sk);

/**
 * @brief Padalija studentų sąrašą į dvi grupes pagal galutinį balą.
 * 
 * Funkcija perrašo pradinį vektorių taip, kad pradžioje liktų
 * tik išlaikę studentasi ( galutinis balas >= 5.0), o neišlaikę
 * surenkami į atskirą vektorių. 
 * 
 * Pirmiausiai pereiname per pradinį vektorių. Tada studentai su galutiniu
 * balu >=5.0 perkeliami į vektoriaus pradžią. Studentai su galutiniu balu <5.0
 * surenkami į atskirą vektorių nemoksos.
 * 
 * @param Grupe Pradinis visų studentų vektorius.
 */
void pasiskirstymas_vector_2(vector<Studentas> Grupe, const int &irasu_sk);

/**
 * @brief Padalija studentų sąrašą į dvi grupes pagal galutinį balą.
 * 
 * Funkcija perrašo pradinį sąrašą taip, kad liktų
 * tik išlaikę studentai (galutinis balas >= 5.0), o neišlaikę
 * surenkami į atskirą vektorių. 
 * 
 * Pirmiausiai pereiname per pradinį sąrašą. Tada studentai su galutiniu
 * balu < 5.0 dedami į nemoksu sąrašą ir iš pradinio vektoriaus
 * pašalinami.
 * 
 * @param Grupe Pradinis visų studentų sąrašas.
 */
void pasiskirstymas_list_2(list<Studentas> Grupe, const int &irasu_sk);

/**
 * @brief Padalija studentų sąrašą į dvi grupes pagal galutinį balą.
 * 
 * Funkcija naudoja std::partition, kurie perrašo pradinį vektorių taip, kad liktų
 * priekyje tik išlaikę studentai (galutinis balas >= 5.0), o neišlaikę gale, vėliau
 * surenkami į atskirą vektorių. 
 * 
 * @param Grupe nuoroda į pradinį visų studentų vektorių.
 */
void pasiskirstymas_vector_3(vector<Studentas> &Grupe, const int &irasu_sk);

/**
 * @brief Padalija studentų sąrašą į dvi grupes pagal galutinį balą.
 * 
 * Funkcija naudoja std::remove_if, kuris perrašo pradinį sarašą taip, kad liktų
 * tik išlaikę studentai (galutinis balas >= 5.0), o neišlaikę
 * surenkami į atskirą vektorių. 
 * 
 * @param Grupe nuoroda į pradinį visų studentų sąrašą.
 */
void pasiskirstymas_list_3(list<Studentas> &Grupe, const int &irasu_sk);

/**
  * @brief Vykdomas nurodyto failo nuskaitymas per buferį.
  * 
  * Funkcija atidaro tekstinį failą, perskaito visą jo turinį į buferį
  * ir pagal kiekvieną eilutę sukuria 'Studentas' objektus, kuriuos
  * sudeda į vektorių.
  * 
  * @param failas Kelias iki failo, kurį reikia nuskaityti.
  * 
  * @return Vektorius 'Studentas' objektų, nuskatytų iš failo.
  * 
  * @note Jei failo nepavyksta atidaryti, grąžinamas tuščias vektorius.
  */
vector<Studentas> Failo_nuskaitymas(const string &failas);

/**
  * @brief Vykdoma tik tada, kada žmogus pasirenka įvesti duomenis rankyte.
  * 
  * Funkcija sukuria objektą Studentas ir surenka visus duomenis apie jį.
  * 
  * @return Objektas 'Studentas' apie kurį surinkta visa reikalinga informacija.
  * 
  */
Studentas Stud_iv();
double Mediana();

/**
 * @brief Išsaugo studentų duomenis į tekstinius failus.
 *
 * Funkcija sukuria du failus: vieną moksliukams, kitą nemoksoms.
 * Studentai išrašomi į atskirus failus (vardas, pavardė ir galutinis pažymys)
 *
 * Failų pavadinimai generuojami pagal perduotą strategiją ir konteinerio tipą.
 *
 * @tparam Container Bet kuris konteinerio tipas.
 *
 * @param moksliukai Konteineris su išlaikiusiais studentais.
 * @param nemoksos Konteineris su neišlaikiusiais studentais.
 * @param strategija Naudotos strategijos numeris (pvz., "1", "2", "3").
 * @param konteineris Konteinerio pavadinimas (pvz., "vector", "list").
 */
template <typename Container>
void Spausdink(const Container &moksliukai, const Container &nemoksos, const string &strategija, const string &konteineris)
{
    string sablonas = "rezultatai_" + strategija + "_" + konteineris;
    ofstream frM(sablonas + "_moksliukai.txt");
    ofstream frN(sablonas + "_nemoksos.txt");
    for (auto it = std::begin(moksliukai); it != std::end(moksliukai); ++it)
    {
        frM << it->vardas() << ' ' << it->pavarde() << ' ' << it->galutinis() << endl;
    }
    for (auto it = std::begin(nemoksos); it != std::end(nemoksos); ++it)
    {
        frN << it->vardas() << ' ' << it->pavarde() << ' ' << it->galutinis() << endl;
    }
}
