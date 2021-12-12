#ifndef HOZZASZOLAS_H
#define HOZZASZOLAS_H
#include <iostream>
using namespace std;

class Hozzaszolas
{
    string fnev;
    string szoveg;
    int ertekeles;
    int konvyvid;
public:
    Hozzaszolas(const string& szoveg, int konyvID);
};

#endif // HOZZASZOLAS_H
