#include "kunde.h"

const string &Kunde::getName() const
{
    return name;
}

void Kunde::setName(const string &newName)
{
    name = newName;
}

const string &Kunde::getVorname() const
{
    return vorname;
}

void Kunde::setVorname(const string &newVorname)
{
    vorname = newVorname;
}

int Kunde::getKundenID() const
{
    return kundenID;
}

void Kunde::setKundenID(int newKundenID)
{
    kundenID = newKundenID;
}

int Kunde::getPostleitzahl() const
{
    return kundenID;
}

void Kunde::setPostleitzahl(int newPostleitzahl)
{
    postleitzahl = newPostleitzahl;
}

const string &Kunde::getWohnort() const
{
    return wohnort;
}

void Kunde::setWohnort(const string &newWohnort)
{
    wohnort = newWohnort;
}
