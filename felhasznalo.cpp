#include "felhasznalo.h"

string Felhasznalo::getEmail() const
{
    return email;
}

void Felhasznalo::setEmail(const string &value)
{
    email = value;
}

string Felhasznalo::getNev() const
{
    return nev;
}

void Felhasznalo::setNev(const string &value)
{
    nev = value;
}

string Felhasznalo::getFnev() const
{
    return fnev;
}

void Felhasznalo::setFnev(const string &value)
{
    fnev = value;
}

string Felhasznalo::getJelszo() const
{
    return jelszo;
}

void Felhasznalo::setJelszo(const string &value)
{
    jelszo = value;
}

string Felhasznalo::getSzuldat() const
{
    return szuldat;
}

void Felhasznalo::setSzuldat(const string &value)
{
    szuldat = value;
}

string Felhasznalo::getLakcim() const
{
    return lakcim;
}

void Felhasznalo::setLakcim(const string &value)
{
    lakcim = value;
}

int Felhasznalo::getId() const
{
    return id;
}

void Felhasznalo::setId(int value)
{
    id = value;
}

bool Felhasznalo::getRegisztralt() const
{
    return regisztralt;
}

void Felhasznalo::setRegisztralt(bool value)
{
    regisztralt = value;
}

bool Felhasznalo::getVanOlvasojegy() const
{
    return vanOlvasojegy;
}

void Felhasznalo::setVanOlvasojegy(bool value)
{
    vanOlvasojegy = value;
}

string Felhasznalo::getTelszam() const
{
    return telszam;
}

void Felhasznalo::setTelszam(const string &value)
{
    telszam = value;
}

Olvasojegy Felhasznalo::getOj() const
{
    return oj;
}



void Felhasznalo::keszitOlvasojegyet()
{
    if(!vanOlvasojegy){
    string valasz;
    cout << "Az olvasojegy ara: 2000 Ft." << endl;
    cout << "Megvasarolja a jegyet? (y/n) " << endl;
    cin >> valasz;
    if(valasz == "y")
    {
        string bankszamlaszam, lejarati, ccv;
        cout << "Bankszamlaszam: ";
        cin >> bankszamlaszam;
        cout << endl;
        cout << "Lejarati datum: ";
        cin >> lejarati;
        cout << endl;
        cout << "CCV kod: ";
        cin >> ccv;
        cout << endl;
        Sleep(2000);
        cout << "A tranzakcio sikeres volt!" << endl;
        Olvasojegy o1(id,chrono::system_clock::now(),true);
        time_t end_t =chrono::system_clock::to_time_t(o1.getLejar());
        cout << "Olvasojegyet " << ctime(&end_t) << " -ig hasznalhatja." << endl;
         oj = o1;
         setVanOlvasojegy(true);
         return;
    }
    cout << "A tranzakciot megszakitottuk." << endl;
    return;
    }
    else{
        cout << "Mar rendelkezik olvasojeggyel." << endl;
        return;
    }



}

Felhasznalo::Felhasznalo(int id, string fnev, string jelszo, string email, string nev, string szuldat, string lakcim, string telszam):
    id(id),
    fnev(fnev),
    jelszo(jelszo),
    email(email),
    nev(nev),
    szuldat(szuldat),
    lakcim(lakcim),
    telszam(telszam)
{

}
