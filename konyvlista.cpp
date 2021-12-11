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

int KonyvLista::betoltKonyvek(KonyvLista &kl, const string &fajlnev)
{
    ifstream myFileStream(fajlnev);

    if(!myFileStream.is_open())
    {
       cout << "Failed to open file" << endl;
       return 0;
    }
    int id;
    string cim;
    int kiadas;
    string iro;
    string mufaj;
    string tempString;
    string line;
    bool kolcsonozheto;
    while(getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss,tempString,';');
        id = stoi(tempString);
        getline(ss,iro,';');
        getline(ss,tempString,';');
        kiadas = stoi(tempString);
        getline(ss,cim,';');
        getline(ss,mufaj,';');
        getline(ss,tempString,';');
        if(tempString == "1")
        {
            kolcsonozheto = true;
        }
        else{
            kolcsonozheto = false;
        }
        Konyv book(id,cim,kiadas,iro,mufaj,kolcsonozheto);
        kl.konyvLista.push_back(book);
    }
    kl.konyvLista.sort([](const Konyv& k1, const Konyv& k2){
        return k1.getIro() < k2.getIro();
    });
    myFileStream.close();
    return 1;

}

list<Konyv> KonyvLista::getKonyvLista() const
{
    return konyvLista;
}



KonyvLista::KonyvLista()
{

}
