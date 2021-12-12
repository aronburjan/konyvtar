#ifndef KONYV_H
#define KONYV_H
#include <iostream>
using namespace std;
#include "hozzaszolas.h"
#include <list>


class Konyv
{
    int id;
    string iro;
    int kiadas; //kiadás éve
    string cim;
    string mufaj;
    bool kolcsonozheto;
    list<string> hozzaszolasok;

public:
    Konyv();
    Konyv(int id, const string& cim, int kiadas, const string& iro, const string& mufaj, bool kolcsonozheto);
    int getId() const;
    string getIro() const;
    int getKiadas() const;
    string getCim() const;
    string getMufaj() const;
    bool getKolcsonozheto() const;
    list<string> getHozzaszolasok() const;
    void printKonyv() const;
    void setKolcsonozheto(bool value);
    void printHozzaszolasok();
    void hozzadKomment();
};

#endif // KONYV_H
