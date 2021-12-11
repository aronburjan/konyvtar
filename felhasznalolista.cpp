#include "felhasznalolista.h"

int FelhasznaloLista::getDarab() const
{
    return darab;
}

void FelhasznaloLista::setDarab(int value)
{
    darab = value;
}

int FelhasznaloLista::betoltFelhasznalok(FelhasznaloLista& fl, const string &filename)
{
    ifstream myFileStream(filename);

    if(!myFileStream.is_open())
    {
       cout << "Failed to open file" << endl;
       return 0;
    }
    int id;
    string readFelh;
    string readJelszo;
    string email;
    string nev;
    string szuldat;
    string lakcim;
    string line;
    string telszam;
    string tempString;
    while(getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss,tempString,';');
        id = stoi(tempString);
        getline(ss,readFelh,';');
        getline(ss,readJelszo,';');
        getline(ss,email,';');
        getline(ss,nev,';');
        getline(ss,szuldat,';');
        getline(ss,lakcim,';');
        getline(ss,telszam,';');
        Felhasznalo user(id,readFelh,readJelszo,email,nev,szuldat,lakcim,telszam);
        fl.felhasznalok.push_back(user);
    }
}

void FelhasznaloLista::listaz() const
{
    for(auto it:felhasznalok)
    {
        cout << "id: " << it.getId() <<
                " nev: " << it.getNev() <<
                " felhasznalonev: " << it.getFnev() <<
                " email: " << it.getEmail() << endl;

    }
}

int FelhasznaloLista::checkLogin(const string &felh, const string &jelszo) const
{
    for(auto it:felhasznalok)
    {
        if(it.getFnev() == felh && it.getJelszo() == jelszo)
        {
            return it.getId();
        }
    }
    return 0;
}

FelhasznaloLista::FelhasznaloLista()
{

}
