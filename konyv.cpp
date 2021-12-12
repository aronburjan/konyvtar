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

void Konyv::setKolcsonozheto(bool value)
{
    kolcsonozheto = value;
}

void Konyv::printHozzaszolasok()
{
    for(auto it:hozzaszolasok)
    {
        cout << "Hozzaszolas: " << it << endl;
    }
}

void Konyv::hozzadKomment()
{
    string komment;
    cout << "Irja meg a hozzaszolast: ";
    cin.ignore();
    getline(cin,komment);
    this->hozzaszolasok.push_back(komment);
}

Konyv::Konyv()
{

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
