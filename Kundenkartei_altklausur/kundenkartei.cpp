#include "kundenkartei.h"
KundenKartei::KundenKartei(){
    countkundenID = 0;
}
void KundenKartei::neuerKunde(){
    countkundenID++;
    Kunde kunde;
    string name;
    string vorname;
    int kundenID = countkundenID;
    int postleitzahl;
    string wohnort;

    cout << "Name des Kundens: " << endl;
    cin >> name;
    cout << "Vorname des Kundens: " << endl;
    cin >> vorname;
    cout << "Postleitzahl des Kundens: " << endl;
    cin >> postleitzahl;
    cout << "Wohnort des Kundens: " << endl;
    cin >> wohnort;

    kunde.setKundenID(kundenID);
    kunde.setName(name);
    kunde.setPostleitzahl(postleitzahl);
    kunde.setVorname(vorname);
    kunde.setWohnort(wohnort);

    kunden.push_back(kunde);
}
void KundenKartei::löschen(){
    int kundenID;
    cout << "KundenID des zu löschenden Kundens: ";
    cin >> kundenID;
    for (unsigned int i = 0; i <= kunden.size(); i++){
        if (kunden[i].getKundenID() == kundenID){
            cout << "kunde wird gelöscht." << endl;
            kunden.erase(kunden.begin()+i);
            return;
        }
    }
    cout << "kunde wurde nicht gefunden." << endl;
    return;
}
void KundenKartei::alleKunden(){
    for (Kunde kunde:kunden){
        cout << "===============" << endl;
        cout << "KundenID: " << kunde.getKundenID() << endl;
        cout << "Name, Vorname: " << kunde.getName() << ", " <<
                kunde.getVorname() << endl;
        cout << "postleitzahl Wohnort: " << kunde.getPostleitzahl() << " "
             << kunde.getWohnort() << endl;
    }
}
void KundenKartei::verdoppeln(){
    int selKundenID;
    cout << "welcher Kunde soll verdoppelt werden? ";
    cin >> selKundenID;
    for (Kunde altKunde : kunden){
        if (altKunde.getKundenID() == selKundenID){
            Kunde newKunde;
            countkundenID++;
            newKunde.setName(altKunde.getName());
            newKunde.setVorname(altKunde.getVorname());
            newKunde.setPostleitzahl(altKunde.getPostleitzahl());
            newKunde.setWohnort(altKunde.getWohnort());
            newKunde.setKundenID(countkundenID);
        }
    }
    cout << "kunde wurde nicht gefunden." << endl;
    return;
}
