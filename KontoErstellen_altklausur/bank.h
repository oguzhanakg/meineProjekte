#ifndef BANK_H
#define BANK_H


#include "girokonto.h"

class Bank
{
public:
    Bank();
    void benutzerDialog();

private:
    vector<GiroKonto*> Kontenlisten;
};

#endif // BANK_H
