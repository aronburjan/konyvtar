#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
#include "konyv.h"
#include <list>
using namespace std;

class Felhasznalo
{
    int id;
    string fnev, jelszo, email, nev, szuldat, lakcim, telszam;
    bool regisztralt;
    bool vanOlvasojegy;
    list<Konyv> kolcsonzottKonyvek;
public:
    Felhasznalo(int id, string fnev, string jelszo, string email, string nev, string szuldat, string lakcim, string telszam);
    Felhasznalo()=default;
    string getEmail() const;
    void setEmail(const string &value);
    string getNev() const;
    void setNev(const string &value);
    string getFnev() const;
    void setFnev(const string &value);
    string getJelszo() const;
    void setJelszo(const string &value);
    string getSzuldat() const;
    void setSzuldat(const string &value);
    string getLakcim() const;
    void setLakcim(const string &value);
    int getId() const;
    void setId(int value);
    bool getRegisztralt() const;
    void setRegisztralt(bool value);
    bool getVanOlvasojegy() const;
    void setVanOlvasojegy(bool value);
};

#endif // FELHASZNALO_H