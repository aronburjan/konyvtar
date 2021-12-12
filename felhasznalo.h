#ifndef FELHASZNALO_H
#define FELHASZNALO_H
#include <iostream>
#include "konyv.h"
#include <list>
#include "olvasojegy.h"
#include <chrono>
#include<windows.h>
using namespace std;

class Felhasznalo
{
    int id;
    string fnev, jelszo, email, nev, szuldat, lakcim, telszam;
    bool regisztralt;
    bool vanOlvasojegy;
    list<Konyv> kolcsonzottKonyvek;

    Olvasojegy oj;

public:
    Felhasznalo(int id, string fnev, string jelszo, string email, string nev, string szuldat, string lakcim, string telszam, bool vanolvasojegy);


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
    string getTelszam() const;
    void setTelszam(const string &value);
    Olvasojegy getOj() const;
    bool operator == (const Felhasznalo &f1);

    void setOj(const Olvasojegy &value);
};

#endif // FELHASZNALO_H
