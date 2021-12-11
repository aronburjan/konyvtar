#include "olvasojegy.h"



chrono::system_clock::time_point Olvasojegy::getKeszult() const
{
    return keszult;
}

chrono::system_clock::time_point Olvasojegy::getLejar() const
{
    return lejar;
}

bool Olvasojegy::getAktiv() const
{
    return aktiv;
}

void Olvasojegy::kolcsonzes(Konyv &k1)
{
    if(k1.getKolcsonozheto())
    {
        kikolcsonzottKonyvek.push_back(k1);
        k1.setKolcsonozheto(false);
    }
    else{
        cout << "A konyv jelenleg nem elerheto." << endl;
        return;
    }
}

Olvasojegy::Olvasojegy(int id, chrono::system_clock::time_point keszult, bool aktiv):
    id(id)
{
    keszult = chrono::system_clock::now();
    lejar = keszult + std::chrono::hours(30*24); //az olvasojegy 30 napig ervenyes
    this->aktiv = aktiv;
}
