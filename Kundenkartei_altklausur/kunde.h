#ifndef KUNDE_H
#define KUNDE_H

#include <iostream>
using namespace std;
class Kunde{
private:
    string name;
    string vorname;
    int kundenID;
    int postleitzahl;
    string wohnort;
public:
    const string &getName() const;
    void setName(const string &newName);
    const string &getVorname() const;
    void setVorname(const string &newVorname);
    int getKundenID() const;
    void setKundenID(int newKundenID);
    int getPostleitzahl() const;
    void setPostleitzahl(int newPostleitzahl);
    const string &getWohnort() const;
    void setWohnort(const string &newWohnort);
};


#endif // KUNDE_H
