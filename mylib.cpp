#include "mylib.h"
#include "timer.h"
#include "Studentas.h"

vector<Studentas> Failo_nuskaitymas(const string &failas)
{
    ifstream fd(failas);
    if (!fd)
    {
        cout << "nepavyko atidaryti failo: " << failas << endl;
        return {};
    }
    else
    {
        cout << "Nuskaitomas " << failas << endl;
    }
    stringstream buffer;
    vector<Studentas> Grupe;
    string eil;
    buffer << fd.rdbuf(); // Visas failas iš karto perkeliamas į buferį
    fd.close();
    getline(buffer, eil);
    while (getline(buffer, eil))
    {
        istringstream iss(eil); // eilute paverciam i duomenu srauta, pav iss
        Studentas stud(iss);
        Grupe.push_back(stud);
    }
    return Grupe;
}

bool paz_tikrinimas(int laik_paz)
{
    if (cin.fail()) // naudojamas patikrinti ar inputas teisingas.
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ivedete ne skaiciu. Iveskite skaiciu." << endl;
        return false;
    }
    if (laik_paz > 0 && laik_paz <= 10)
    {
        return true;
    }
    else
    {
        cout << "Netinkamas skaicius. Pabandykite dar karta." << endl;
        return false;
    }
}

int atsitiktinis_sk()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10); // uztikrina, kad skaiciai butu butent nuo 1 iki 10.
    return dist(gen);
}

Studentas Stud_iv()
{
    int m, laik_paz, suma = 0, tempE;
    string ats, tempV, tempP;
    Studentas Pirmas;
    vector<int> tempPaz;
    cout << "Prasau ivesti studento duomenis: " << endl;
    cout << "Vardas: ";
    cin >> tempV;
    Pirmas.setVardas(tempV);
    cout << "Pavarde: ";
    cin >> tempP;
    Pirmas.setPavarde(tempP);
    cout << "Ar norite, kad studento (-es) vardu " << Pirmas.vardas() << " pazymiai butu generuojami atsitiktinai (t arba n)? " << endl;
    cin >> ats;

    if (ats == "t")
    {
        bool dar = true;
        int paz = 1;
        while (dar)
        {
            if (paz == 1)
            {
                int x = atsitiktinis_sk();
                cout << "Sugeneruotas " << paz << "-as pazymys yra " << x << endl;
                tempPaz.push_back(x);
                suma += x;
                paz += 1;
            }
            else
            {
                cout << "Ar sugeneruoti dar viena pazymi (t arba n)?" << endl;
                cin >> ats;
                if (ats == "t")
                {
                    int x = atsitiktinis_sk();
                    cout << "Sugeneruotas " << paz << " yra " << x << endl;
                    tempPaz.push_back(x);
                    suma += x;
                    paz += 1;
                }
                else
                {
                    dar = false;
                }
            }
        }
        int x = atsitiktinis_sk();
        cout << "Sugeneruotas egzamino rezultatas yra:" << x << endl;
        tempE = x;
        Pirmas.setPaz(tempPaz);
        Pirmas.setEgz(tempE);
        double tempVid = double(suma) / double(tempPaz.size()) * 0.4 + 0.6 * tempE;
        Pirmas.setGal(tempVid);
        double tempMed = double(Pirmas.Mediana()) * 0.4 + 0.6 * tempE;
        Pirmas.setMed(tempMed);

        return Pirmas;
    }
    else
    {
        bool vedam = true;
        int k = 1;
        cout << "Baige vesti pazymius - iveskite 0." << endl;
        while (vedam)
        {
            cout << "Iveskite " << k << " pazymi:";
            cin >> laik_paz;
            if (laik_paz == 0)
            {
                vedam = false;
                break;
            }
            else
            {
                if (paz_tikrinimas(laik_paz) == true)
                {
                    tempPaz.push_back(laik_paz);
                    suma += laik_paz;
                    k += 1;
                }
                else
                {
                    continue;
                }
            }
        }

        k -= 1;
        cout << "Koks yra egzamino rezultatas? " << endl;
        cin >> tempE;
        Pirmas.setPaz(tempPaz);
        Pirmas.setEgz(tempE);
        double tempGal = double(suma) / double(tempPaz.size()) * 0.4 + 0.6 * tempE;
        Pirmas.setGal(tempGal);
        double tempMed = double(Pirmas.Mediana()) * 0.4 + 0.6 * tempE;
        Pirmas.setMed(tempMed);
    }

    return Pirmas;
}

void rusiuok_vect(vector<Studentas> &konteineris, char pagal = 'g')
{
    sort(konteineris.begin(), konteineris.end(), [pagal](const Studentas &a, const Studentas &b)
         {
        if (pagal == 'v') {
            return a.vardas() < b.vardas();
        }
        else if (pagal == 'p') {
            return a.pavarde() < b.pavarde();
        }
        else if (pagal == 'g') {
            return a.galutinis() > b.galutinis();
        }
        else return false; });
}

void spausdink_grupe(const vector<Studentas> &vekt, string tipas)
{
    stringstream ss;
    ss << setw(16) << left << "Pavarde" << setw(15) << left << "Vardas";
    if (tipas == "v")
    {
        ss << setw(10) << left << "Gal.";
        for (auto &stud : vekt)
        {
            ss << endl
               << setw(16) << left << stud.pavarde() << setw(15) << left << stud.vardas() << setw(10) << fixed << setprecision(2) << stud.galutinis();
        }
    }
    if (tipas == "m")
    {
        ss << "Med.";
        for (auto &stud : vekt)
        {
            ss << endl
               << setw(16) << left << stud.pavarde() << setw(15) << left << stud.vardas() << setw(10) << fixed << setprecision(2) << stud.galutinisMed();
        }
    }
    if (tipas == "a")
    {
        ss << setw(10) << "Gal. " << setw(10) << " Med.";
        for (auto &stud : vekt)
        {
            ss << endl
               << setw(16) << left << stud.pavarde() << setw(15) << left << stud.vardas() << setw(10) << fixed << setprecision(2) << stud.galutinis() << setw(10) << fixed << setprecision(2) << stud.galutinisMed();
        }
    }

    if (vekt[0].galutinis() >= 5)
    {
        ofstream out("moksliukai.txt");
        out << ss.str();
        out.close();
    }
    else
    {
        ofstream out("nemoksos.txt");
        out << ss.str();
        out.close();
    }
}

void pasiskirstymas_vector_1(const vector<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t; // paleidzia laikmati
    vector<Studentas> moksliukai, nemoksos;
    moksliukai.reserve(irasu_sk);
    nemoksos.reserve(irasu_sk);

    for (auto &stud : Grupe)
    {
        if (stud.galutinis() >= 5.0)
        {
            moksliukai.push_back(stud);
        }
        else
        {
            nemoksos.push_back(stud);
        }
    }
    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 1 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(moksliukai, nemoksos, "1", "vector");
    }
}

void pasiskirstymas_list_1(const list<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> moksliukai, nemoksos;
    for (auto &stud : Grupe)
    {
        if (stud.galutinis() >= 5.0)
        {
            moksliukai.push_back(stud);
        }
        else
        {
            nemoksos.push_back(stud);
        }
    }
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 1 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(moksliukai, nemoksos, "1", "list");
    }
}

void pasiskirstymas_vector_2(vector<Studentas> Grupe, const int &irasu_sk)
{
    Timer t;
    vector<Studentas> nemoksos;
    nemoksos.reserve(irasu_sk);
    size_t i = 0;

    for (size_t j = 0; j < Grupe.size(); ++j)
    {
        if (Grupe[j].galutinis() >= 5.0)
        {
            Grupe[i] = move(Grupe[j]);
            i++;
        }
        else
        {
            nemoksos.push_back(move(Grupe[j]));
        }
    }
    Grupe.erase(Grupe.begin() + i, Grupe.end());
    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 2 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "2", "vector");
    }
}

void pasiskirstymas_list_2(list<Studentas> Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> nemoksos;
    for (auto it = Grupe.begin(); it != Grupe.end();)
    {
        if (it->galutinis() < 5.0)
        {
            nemoksos.push_back(*it);
            it = Grupe.erase(it);
        }
        else
        {
            ++it;
        }
    }
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 2 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "2", "list");
    }
}

void pasiskirstymas_vector_3(vector<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    vector<Studentas> nemoksos;
    nemoksos.reserve(irasu_sk);

    auto it = partition(Grupe.begin(), Grupe.end(),
                        [](const Studentas &s)
                        { return s.galutinis() >= 5.0; });
    nemoksos.assign(it, Grupe.end());
    Grupe.erase(it, Grupe.end());

    cout << irasu_sk << " vektoriaus padalijimo i dvi grupes, vykdant 3 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "3", "vector");
    }
}

void pasiskirstymas_list_3(list<Studentas> &Grupe, const int &irasu_sk)
{
    Timer t;
    list<Studentas> nemoksos;
    Grupe.remove_if([&nemoksos](const Studentas &s)
                    {
                        if (s.galutinis() < 5.0)
                        {
                            nemoksos.push_back(s);
                            return true; // pasalins is grupes si studenta
                        }
                        return false; // paliks studenta
                    });
    cout << irasu_sk << " saraso padalijimo i dvi grupes, vykdant 3 strategija, laikas " << t.elapsed() << endl;
    if (irasu_sk == 1000)
    {
        Spausdink(Grupe, nemoksos, "3", "list");
    }
}
