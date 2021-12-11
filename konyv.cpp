#include "konyv.h"

int Konyv::getId() const
{
    return id;
}

string Konyv::getIro() const
{
    return iro;
}

int Konyv::getKiadas() const
{
    return kiadas;
}

string Konyv::getCim() const
{
    return cim;
}

string Konyv::getMufaj() const
{
    return mufaj;
}

bool Konyv::getKolcsonozheto() const
{
    return kolcsonozheto;
}

list<string> Konyv::getHozzaszolasok() const
{
    return hozzaszolasok;
}

void Konyv::printKonyv() const
{
    cout << getIro() << " : " << getCim() << " (" << getKiadas() << ")" << " - " << getMufaj();
    if(getKolcsonozheto())
    {
        cout << " [kolcsonozheto]" << endl;
    }
    else{
        cout << " [nem elerheto]" << endl;
    }
}

Konyv::Konyv(int id, const string &iro, int kiadas, const string &cim, const string &mufaj, bool kolcsonozheto):
    id(id),
    iro(iro),
    kiadas(kiadas),
    cim(cim),
    mufaj(mufaj),
    kolcsonozheto(kolcsonozheto)
{

}
