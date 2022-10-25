#include <iostream>
#include "kundenkartei.h"
using namespace std;
int main(){
    char menuAuswahl;
    KundenKartei kundenKartei;
    while (true){
        cout << "Menue:" << endl
             << "(e) Eingabe eines neuen Kunden von Hand" << endl
             << "(l) löschen eines Kunden" << endl
             << "(a) Ausgabe aller Kunden" << endl
             << "(v) eintrag verdoppeln" << endl
             << "(x) beenden" << endl;
        cin >> menuAuswahl;
        switch(menuAuswahl){
        case 'e':
            kundenKartei.neuerKunde();
            break;
        case 'l':
            kundenKartei.löschen();
            break;
        case 'a':
            kundenKartei.alleKunden();
            break;
        case 'v':
            kundenKartei.verdoppeln();
            break;
        case 'x':
            cout << "bis bald" << endl;
            return 0;
        default:
            cout << "etwas ist schief gelaufen" << endl;
            break;
        }
    }
}
