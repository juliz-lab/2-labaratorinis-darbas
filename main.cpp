#include "mylib.h"

int main()
{
    char p;
    cout << "Pasirinkite, ka norite, daryti:" << endl;
    cout << "1 - Nuskaityti studentus is failo." << endl;
    cout << "2 - Irasyti studentus pats." << endl;
    cout << "3 - Tikrinti sparta." << endl;
    cin >> p;

    if (p == '1')
    {
        char ats;
        string pasirinkimas;
        char pagal;
        cout << "Koki faila noretumete nuskaityti: a - 1000, b - 10000, c - 100000, d - 1000000, e - 10000000? ";
        cin >> ats;
        map<char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
        int irasu_sk = tipai[ats];
        string fail_pav = "studentai" + to_string(irasu_sk) + ".txt";

        cout << "Pagal ka rikiuojame? v - vardas, p - pavarde, g - galutinis pazymys: ";
        cin >> pagal;

        cout << "Ar noretumete gauti tik v - vidurki, tik m - mediana ar a - abu? ";
        cin >> pasirinkimas;
        vector<Studentas> Grupe, moksliukai, nemoksos;
        Grupe = Failo_nuskaitymas(fail_pav);

        for (auto &stud : Grupe)
        {
            if (stud.galutinis() >= 5)
            {
                moksliukai.push_back(stud);
            }
            else
            {
                nemoksos.push_back(stud);
            }
        }
        rusiuok_vect(moksliukai, pagal);
        rusiuok_vect(nemoksos, pagal);

        spausdink_grupe(moksliukai, pasirinkimas);
        spausdink_grupe(nemoksos, pasirinkimas);
    }
    else if (p == '2')
    {
        vector<Studentas> Grupe, nemoksos;
        cout << "Kiek studentu yra grupeje? ";
        int n;
        cin >> n;
        for (auto z = 0; z < n; z++)
        {
            Grupe.push_back(Stud_iv());
        }

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
        
        spausdink_grupe(Grupe, "v");
        spausdink_grupe(nemoksos, "v");

        /*ofstream out("rezultatas.txt");
        out << "Vardas " << setw(15) << "Pavarde " << setw(10) << "Gal." << endl;
        for (auto &s : Grupe)
        {
            out << s.vardas() << setw(15) << s.pavarde() << setw(15) << s.galutinis() << endl;
        }*/

        // JEIGU REIKIA PARODYTI, KAD KOPIJAVIMO KONSTRUKTORIUS IR KOPIJAVIMO PRISKYRIMO OPERATORIUS VEIKIA:
        /*Studentas a1 = Grupe[0];
        cout << "Studento a1 vardu " << a1.vardas() << " galutinis pazymys " << a1.galutinis() << endl;
        Studentas a2 = a1;
        cout << "Studento a2 vardu " << a2.vardas() << " galutinis pazymys " << a2.galutinis() << endl;

        Studentas a3;
        cin >> a3;
        cout << "Studentas a3: " << a3 << endl;
        a3 = a1;
        cout << "Studento a3: " << a3 << endl;*/
    }
    else if (p == '3')
    {
        for (int i = 1'000; i <= 1'000'000; i *= 10)
        {
            vector<Studentas> Grupe = Failo_nuskaitymas("studentai" + to_string(i) + ".txt");
            list<Studentas> Grupelist(Grupe.size());
            std::copy(Grupe.begin(), Grupe.end(), Grupelist.begin());
            pasiskirstymas_vector_1(Grupe, i);
            pasiskirstymas_vector_2(Grupe, i);
            pasiskirstymas_vector_3(Grupe, i);

            pasiskirstymas_list_1(Grupelist, i);
            pasiskirstymas_list_2(Grupelist, i);
            pasiskirstymas_list_3(Grupelist, i);

            cout << endl;
        }
    }
    else
    {
        cout << "Tokio pasirinkimo nebuvo. " << endl;
    }
}
