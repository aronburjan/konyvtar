#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "felhasznalolista.h"
#include "konyvlista.h"
using namespace std;

Felhasznalo sessionUser(0,"0","0","0","0","0","0","0","0");
FelhasznaloLista felhasznalok;
KonyvLista konyvek;
bool belepve = false;



void bejelentkezes(FelhasznaloLista& fl)
{
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
                sessionUser = it;
                cout << "Sikeres bejelentkezes!" << endl;

                return;
            }
        }
    }
    cout << "Hibas felhasznalonev vagy jelszo!" << endl;


}

void regisztracio(FelhasznaloLista& fl)
{
    int id;
    string email;
    string felh;
    string jelszo;
    string nev;
    string szuldat;
    string lakcim;
    string telszam;
    cout << "e-mail: ";
    cin >> email;
    cout << endl;
    cout << "felhasznalonev: ";
    cin >> felh;
    cout << endl;
    cout << "jelszo: ";
    cin >> jelszo;
    cout << endl;
    cout << "nev: ";
    cin.ignore();
    getline(cin,nev);
    cout << endl;
    cout << "szuletesi datum (eeee-hh-nn): ";
    cin >> szuldat;
    cout << endl;
    cout << "lakcim (varos): ";
    cin >> lakcim;
    cout << endl;
    cout << "telszam: ";
    cin >> telszam;
    //kiszedjük a legutolsó id-t
    ifstream myFileStream("felhasznalok.txt");
    string line;
    string tempString;
    string checkFelh;
    string checkEmail;
    if(!myFileStream.is_open())
    {
       cout << "Failed to open file" << endl;
       return;
    }
    else{
        while(getline(myFileStream, line))
        {
            stringstream ss(line);
            getline(ss,tempString,';');
            id = stoi(tempString);
            getline(ss,checkFelh,';');
            getline(ss,tempString,';');
            getline(ss,checkEmail,';');
            if(checkEmail == email)
            {
                cout << "Ehhez az e-mail cimhez mar tartozik felhasznalo. Probalkozzon ujra!" << endl;
                return;
            }
            if(checkFelh == felh)
            {
                cout << "Felhasznalonev mar foglalt. Probalkozzon ujra!" << endl;
                return;
            }


        }
    }
    //megnöveljük egyel az id-t
    id++;
    cout << id;
    Felhasznalo f1(id,felh,jelszo,email,nev,szuldat,lakcim,telszam,false);
    //hozzáadjuk a felhasználót a listához
    fl.felhasznalok.push_back(f1);
    ofstream file;
    //elmentjük a felhasználót fileba
    file.open("felhasznalok.txt", std::ios_base::app);

    file << f1.getId() << ";" << f1.getFnev() << ";" << f1.getJelszo() << ";" << f1.getEmail() <<
            ";" << f1.getNev() << ";" << f1.getSzuldat() << ";" << f1.getLakcim() << ";" << f1.getTelszam()  << ";" << "0" << '\n';


    file.close();
}

void kikolcsonzes()
{
    if(sessionUser.getVanOlvasojegy()){
    string cim;
    Konyv k1;
    cout << "Konyv cime: " << endl;
    cin.ignore();
    getline(cin,cim);
    bool talalat = false;
    for(auto it:konyvek.konyvLista)
    {
        if(it.getCim() == cim)
        {
            k1=it;
            sessionUser.getOj().kolcsonzes(konyvek,k1);
            talalat = true;
        }
    }
    if(talalat == false)
    {
        cout << "A kikolcsonozni kivant konyvet nem talaltuk meg." << endl;
        return;
    }
    }
    else{
        cout << "A kolcsonzeshez olvasojegy szukseges." << endl;
    }


}

void betoltFelhasznalok(FelhasznaloLista& fl)
{
    fl.betoltFelhasznalok(fl,"felhasznalok.txt");
}

void betoltKonyvek(KonyvLista& kl)
{
    kl.betoltKonyvek(kl,"konyvek.txt");
}

void KonyvtarStart()
{
    cout << "Udvozoljuk a konyvtar alkalmazasban!" << endl;

    //felhasznalok.letrehozFelhasznalokFile(felhasznalok,"felhasznalok.txt"); //csak legeloszor kell lefuttatni
    konyvek.betoltKonyvek(konyvek,"konyvek.txt");
    felhasznalok.betoltFelhasznalok(felhasznalok, "felhasznalok.txt");


        while(true)
        {
            if(!belepve)
            {
                unsigned valasztas;
                cout << "----------------------------------" << endl;
                cout << "1: bejelentkezes" << endl;
                cout << "2: regisztracio" << endl;
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
                        regisztracio(felhasznalok);
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
                cout << "8: olvasojegy keszitese" << endl;
                cout << "9: hozzaszolas" << endl;
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
                        kikolcsonzes();
                    break;
                    case 8:
                        felhasznalok.keszitOlvasojegyet(felhasznalok.felhasznalok,sessionUser);
                    break;
                    case 9:
                        konyvek.hozzaSzolas();
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


