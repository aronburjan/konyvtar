#include "konyvlista.h"

int KonyvLista::getDarab() const
{
    return darab;
}

void KonyvLista::setDarab(int value)
{
    darab = value;
}

void KonyvLista::printOsszesKonyv() const
{
    for(auto it:konyvLista)
    {
        it.printKonyv();
    }
}

void KonyvLista::printKolcsonozhetoKonyvek() const
{
    for(auto it:konyvLista)
    {
        if(it.getKolcsonozheto())
        {
            it.printKonyv();
        }
    }
}

void KonyvLista::keresKonyvetCim() const
{
    string cim;
    cout << "Keresett konyv cime: ";
    cin.ignore();
    getline(cin,cim);
    bool megvan = false;
    for(auto it:konyvLista)
    {
        if(it.getCim() == cim)
        {
            megvan = true;
            it.printKonyv();
        }
    }
    if(!megvan)
    {
        cout << "A keresett konyv nem elerheto konyvtarunkban." << endl;
    }
}

list<Konyv> KonyvLista::getKonyvLista() const
{
    return konyvLista;
}

KonyvLista::KonyvLista()
{

}
