#ifndef GIROKONTO_H
#define GIROKONTO_H


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GiroKonto
{
public:
    GiroKonto();
    void buchen();
    void zweiteBuchung();
    void anzeigen();

    string getBuchen();
    double getAnlegen();
    double getNeukontostand();
    string getBuchungstext();
    void setBuchen(string& newKontoNummer);
    void setAnlegen(double& newKontoStand);
    void setBuchungstext(string& newBuchungsText);
    void setNeukontostand(double& newNeuKontoStand);

private:
    std::string kontoNummer;
    string buchungstext;
    double neukontoStand;
    double kontoStand = 0;
    vector<GiroKonto*> zusätzlich;
};
#endif // GIROKONTO_H
