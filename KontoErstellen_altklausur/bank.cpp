#include "bank.h"

Bank::Bank()
{

}

void Bank::benutzerDialog()
{
    char wählen;
    string kontonummer;
    string neubetrag;
    GiroKonto g;
    while (true) {
        cout << "1: Konto anlegen" << endl;
        cout << "2: Kontobuchung" << endl;
        cout << "3: Umsaetze anzeigen" << endl;
        cout << "0: Programm beenden" << endl;
        cin >> wählen;

        switch (wählen) {
        case '1':{
            cout << "Kontonummer ? ";
            cin >> kontonummer;

            Kontenlisten.push_back(&g);
            for (int i = 0; i < (int)Kontenlisten.size(); i++) {
                if (Kontenlisten[i]->getBuchen() == kontonummer){
                    cout << "Die eingegebene Kontonummer existiert bereits." << endl;
                    break;
                }
                else if (Kontenlisten[i]->getBuchen() != kontonummer){
                    cout << "Konto mit Nummer " << kontonummer << " angelegt." << endl;
                    break;
                }
            }
            g.setBuchen(kontonummer);

        }
            break;
        case '2':{
            cout << "Kontonummer ? ";
            cin >> kontonummer;

            for (int j = 0; j < Kontenlisten.size(); ++j) {
                if(Kontenlisten[j]->getBuchen() != kontonummer){
                    cout << "Dieses Konto existiert nicht. " << endl;
                    break;
                }
                else if(Kontenlisten[j]->getBuchen() == kontonummer){
                    Kontenlisten[j]->buchen();
                    break;
                }
            }
        }
            break;
        case '3':{
            cout << "kontonummer ? ";
            cin >> kontonummer;

            for (int k = 0; k < Kontenlisten.size(); ++k) {
                if(Kontenlisten[k]->getBuchen() == kontonummer){
                    Kontenlisten[k]->anzeigen();
                    break;
                }
            }
}
            break;
        case '0':
            return;

        default: cout << "Wählen Sie eine der Menü Nummern" << endl;
            break;
        }
    }
}
