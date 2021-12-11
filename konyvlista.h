#ifndef KONYVLISTA_H
#define KONYVLISTA_H
#include "konyv.h"
#include <list>
#include <iostream>
#include <string>
using namespace std;

class KonyvLista
{
    int darab;


public:
    list<Konyv> konyvLista;
    KonyvLista();

    int getDarab() const;
    void setDarab(int value);

    void kiKolcsonoz(int id);
    void hozzaadKonyvet(const Konyv& k1);
    void szuresMufaj(string) const;
    void szuresEv(string) const;
    void szuresSzerzo(string) const;
    void printOsszesKonyv() const;
    void printKolcsonozhetoKonyvek() const;
    void keresKonyvetCim() const;
    list<Konyv> getKonyvLista() const;
};

#endif // KONYVLISTA_H
