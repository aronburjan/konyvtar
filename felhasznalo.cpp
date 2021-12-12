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

bool Felhasznalo::operator ==(const Felhasznalo &f1)
{
    if(this->getId() == f1.getId() && this->getFnev() == f1.getFnev() && this->getJelszo() == f1.getJelszo())
    {
        return true;
    }
    return false;
}




void Felhasznalo::setOj(const Olvasojegy &value)
{
    oj = value;
}

Felhasznalo::Felhasznalo(int id, string fnev, string jelszo, string email, string nev, string szuldat, string lakcim, string telszam, bool vanolvasojegy):
    id(id),
    fnev(fnev),
    jelszo(jelszo),
    email(email),
    nev(nev),
    szuldat(szuldat),
    lakcim(lakcim),
    telszam(telszam),
    vanOlvasojegy(vanolvasojegy)
{

}
