#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "felhasznalolista.h"
#include "konyvlista.h"
using namespace std;

Felhasznalo sessionUser;
bool belepve = false;

int betoltKonyvek(KonyvLista& kl, const string& fajl)
{
    ifstream myFileStream(fajl);

    if(!myFileStream.is_open())
    {
       cout << "Failed to open file" << endl;
       return 0;
    }
    int id;
    string cim;
    int kiadas;
    string iro;
    string mufaj;
    string tempString;
    string line;
    bool kolcsonozheto;
    while(getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss,tempString,';');
        id = stoi(tempString);
        getline(ss,iro,';');
        getline(ss,tempString,';');
        kiadas = stoi(tempString);
        getline(ss,cim,';');
        getline(ss,mufaj,';');
        getline(ss,tempString,';');
        if(tempString == "1")
        {
            kolcsonozheto = true;
        }
        else{
            kolcsonozheto = false;
        }
        Konyv book(id,cim,kiadas,iro,mufaj,kolcsonozheto);
        kl.konyvLista.push_back(book);
    }
    kl.konyvLista.sort([](const Konyv& k1, const Konyv& k2){
        return k1.getIro() < k2.getIro();
    });
    myFileStream.close();
    return 1;
}

void bejelentkezes(FelhasznaloLista& fl)
{
    Felhasznalo loginUser;
    for(auto it:fl.felhasznalok)
    {
        cout << it.getNev() << endl;
    }
    string felhasznalonev;
    string jelszo;
    cout << "felhasznalonev: ";
    cin >> felhasznalonev;
    cout << endl << "jelszo: ";
    cin >> jelszo;
    int loginid = fl.checkLogin(felhasznalonev, jelszo);
    if(loginid != 0)
    {
        for(auto it:fl.felhasznalok)
        {
            if(loginid == it.getId())
            {
                belepve = true;
                loginUser = it;
                cout << "Sikeres bejelentkezes!" << endl;
                return;
            }
        }
    }
    cout << "Hibas felhasznalonev vagy jelszo!" << endl;


}

void betoltFelhasznalok(FelhasznaloLista& fl)
{
    fl.betoltFelhasznalok(fl,"felhasznalok.txt");
}

void KonyvtarStart()
{
    cout << "Udvozoljuk a konyvtar alkalmazasban!" << endl;
    FelhasznaloLista felhasznalok;
    KonyvLista konyvek;

    betoltKonyvek(konyvek,"konyvek.txt");
    felhasznalok.betoltFelhasznalok(felhasznalok, "felhasznalok.txt");


        while(true)
        {
            if(!belepve)
            {
                unsigned valasztas;
                cout << "----------------------------------" << endl;
                cout << "1: bejelentkezes" << endl;
                cout << "2: regisztracio" << endl;
                cout << "3: konyv keresese" << endl;
                cout << "4: osszes konyv" << endl;
                cout << "5: kolcsonozheto konyvek" << endl;
                cout << "6: konyv keresese (cim szerint)" << endl;
                cout << "0: kilepes" << endl;
                cout << "Valasszon egy menupontot: ";
                cin >> valasztas;
                cout << endl;
                switch (valasztas)
                {
                    case 0:
                        exit(0);
                    break;

                    case 1:
                        bejelentkezes(felhasznalok);
                    break;

                    case 2:
                        cout << "regisztracio" << endl;
                    break;

                    case 3:
                        cout << "konyv keresese" << endl;
                    break;

                    case 4:
                        konyvek.printOsszesKonyv();
                    break;

                    case 5:
                        konyvek.printKolcsonozhetoKonyvek();
                    break;

                    case 6:
                        konyvek.keresKonyvetCim();
                    break;

                    default:
                        cout << "nem ervenyes menupont!" << endl;
                    break;

                }
                cout << endl;
            }
            //menü belépés után
            else
            {
                unsigned valasztas;
                cout << "----------------------------------" << endl;
                cout << "3: konyv keresese" << endl;
                cout << "4: osszes konyv" << endl;
                cout << "5: kolcsonozheto konyvek" << endl;
                cout << "6: konyv keresese (cim szerint)" << endl;
                cout << "7: kolcsonzes" << endl;
                cout << "0: kilepes" << endl;
                cout << "Valasszon egy menupontot: ";
                cin >> valasztas;
                cout << endl;
                switch (valasztas)
                {
                    case 0:
                        exit(0);
                    break;
                    case 3:
                        cout << "konyv keresese" << endl;
                    break;

                    case 4:
                        konyvek.printOsszesKonyv();
                    break;

                    case 5:
                        konyvek.printKolcsonozhetoKonyvek();
                    break;

                    case 6:
                        konyvek.keresKonyvetCim();
                    break;
                    case 7:
                        cout << "Kolcsonzes" << endl;
                    break;

                    default:
                        cout << "nem ervenyes menupont!" << endl;
                    break;

                }
                cout << endl;
            }
            }
        }





int main()
{
    KonyvtarStart();
    return 0;
}


