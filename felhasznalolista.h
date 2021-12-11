#ifndef FELHASZNALOLISTA_H
#define FELHASZNALOLISTA_H
#include <iostream>
#include "felhasznalo.h"
#include <list>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class FelhasznaloLista
{
    int darab;

public:
    list<Felhasznalo> felhasznalok;
    FelhasznaloLista();

    int getDarab() const;
    void setDarab(int value);
    void letrehozFelhasznalokFile(FelhasznaloLista& fl, const string& filename);
    int betoltFelhasznalok(FelhasznaloLista& fl,const string& filename);
    void listaz() const;
    int checkLogin(const string& felh, const string& jelszo) const;
};

#endif // FELHASZNALOLISTA_H
