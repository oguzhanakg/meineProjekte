#include "girokonto.h"

GiroKonto::GiroKonto()
{

}

void GiroKonto::buchen()
{
    GiroKonto k;
    cout << "Betrag ? ";
    cin >> kontoStand;

    if(kontoStand >= 0){
        cout << "Buchungstext ? ";
        cin.ignore();
        getline (cin, buchungstext);


        zusätzlich.push_back(&k);
        setBuchungstext(buchungstext);

    }
    else if(kontoStand >= 0){
        cout << "Kein ausreichendes Guthaben fuer diese Buchung " << endl;
    }

    zusätzlich.push_back(&k);

}


void GiroKonto::anzeigen()
{
     cout << buchungstext << " " << kontoStand << endl;
}



string GiroKonto::getBuchen()
{
    return kontoNummer;
}

double GiroKonto::getAnlegen()
{
    return kontoStand;
}

double GiroKonto::getNeukontostand()
{
    return neukontoStand;
}

string GiroKonto::getBuchungstext()
{
    return buchungstext;
}

void GiroKonto::setBuchen(string& newKontoNummer)
{
    kontoNummer = newKontoNummer;
}

void GiroKonto::setAnlegen(double& newKontoStand)
{
    kontoStand = newKontoStand;
}

void GiroKonto::setBuchungstext(string &newBuchungsText)
{
    buchungstext = newBuchungsText;
}

void GiroKonto::setNeukontostand(double &newNeuKontoStand)
{
    neukontoStand = newNeuKontoStand;
}


