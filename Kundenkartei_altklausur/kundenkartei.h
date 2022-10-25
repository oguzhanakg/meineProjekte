#ifndef KUNDENKARTEI_H
#define KUNDENKARTEI_H
#include <vector>
#include "kunde.h"
using namespace std;
class KundenKartei{
private:
    vector <Kunde> kunden;
    int countkundenID;
public:
    KundenKartei();
    void neuerKunde();
    void löschen();
    void alleKunden();
    void verdoppeln();
};

#endif // KUNDENKARTEI_H
