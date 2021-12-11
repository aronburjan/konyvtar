#ifndef OLVASOJEGY_H
#define OLVASOJEGY_H
#include "konyv.h"
#include <chrono>
class Olvasojegy
{
    int id;
    chrono::system_clock::time_point keszult;
    chrono::system_clock::time_point lejar;
    bool aktiv;
    list<Konyv> kikolcsonzottKonyvek;
public:
    Olvasojegy()=default;
    Olvasojegy(int id, chrono::system_clock::time_point keszult, bool aktiv);
    chrono::system_clock::time_point getKeszult() const;
    chrono::system_clock::time_point getLejar() const;
    bool getAktiv() const;
    void kolcsonzes(Konyv &k1);
};

#endif // OLVASOJEGY_H
