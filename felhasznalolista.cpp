#include "felhasznalolista.h"

int FelhasznaloLista::getDarab() const
{
    return darab;
}

void FelhasznaloLista::setDarab(int value)
{
    darab = value;
}

void FelhasznaloLista::letrehozFelhasznalokFile(FelhasznaloLista &fl, const string &filename)
{
    //létrehozzuk a felhasználó filet a build konyvtárba egy default első értékkel, ami az admin
    ofstream file;
    //elmentjük a felhasználót fileba
    Felhasznalo admin(1,"admin","admin","admin@admin.com","Admin Nev","1998-03-12","Veszprem","062342323",true);
    file.open("felhasznalok.txt");
    file << 1 << ";" << "admin" << ";" << "admin" << ";" << "admin@admin.com" <<
            ";" << "Admin Nev" << ";" << "1998-03-12" << ";" << "Veszprem" << ";" << "06234232342" << 1 << '\n';

    fl.felhasznalok.push_back(admin);
    file.close();
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
    string olvasoJegyString;
    bool readVanOlvasojegy;
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
        getline(ss,olvasoJegyString,';');
        if(olvasoJegyString == "1")
        {
            readVanOlvasojegy = true;
        }
        else{
            readVanOlvasojegy = false;
        }
        Felhasznalo user(id,readFelh,readJelszo,email,nev,szuldat,lakcim,telszam,readVanOlvasojegy);
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

void FelhasznaloLista::DBupdate(const string &filename)
{
    ofstream file;
    file.open(filename);
    for(auto it:felhasznalok)
    {
        file << it.getId() << ";" << it.getFnev() << ";" << it.getJelszo() << ";" << it.getEmail() << ";" << it.getNev() << ";" << it.getSzuldat() << ";"
             << it.getLakcim() << ";" << it.getTelszam() << ";";
        if(it.getVanOlvasojegy())
        {
            file << "1" << '\n';
        }
        else{
            file << "0" << '\n';
        }
    }
    file.close();

}

void FelhasznaloLista::keszitOlvasojegyet(list<Felhasznalo>& l1, Felhasznalo &f1)
{

    if(!f1.getVanOlvasojegy()){
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
        for(auto &it:l1)
        {
            if(it.getId() == f1.getId())
            {
                it.setVanOlvasojegy(true);
                f1.setVanOlvasojegy(true);
            }
        }

        FelhasznaloLista::DBupdate("felhasznalok.txt");
        Sleep(2000);
        cout << "A tranzakcio sikeres volt!" << endl;
        Olvasojegy o1(f1.getId(),chrono::system_clock::now(),true);
        time_t end_t =chrono::system_clock::to_time_t(o1.getLejar());
        cout << "Olvasojegyet " << ctime(&end_t) << " -ig hasznalhatja." << endl;
        f1.setOj(o1);
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

FelhasznaloLista::FelhasznaloLista()
{

}
