#include <iostream>
#include <experimental/random>

using namespace std;

int main()
{
    int a;  // Anfangsbereich
    int e;  // Endbereich
    cout << "Geben Sie einen Zahlenbereich an: " << endl;
    do
    {
        cin >> a;
        cin >> e;
        if (a>e)
            cout << "Der erste Wert muss kleiner sein also der zweite! Geben Sie neue Werte ein: ";
    } while (a > e);            // überprüfen, dass a nicht größer e ist
    int v;  //Versuche
    cout << "Geben Sie eine Anzahl an Rateversuchen an: " << endl;
    cin >> v;

    int x = std::experimental::randint(a, e); // !!! clang17 damit kein Fehler erscheint !!!    //Zufallszahl
    int r;  //Rateversuch
    cout << "Erraten Sie die Zahl zwischen " << a << " und " << e << " ?" << endl;
    cin >> r;

    while (x!=r)
    {
        for(int i = 1; i < v; i++)
        {
            if (r <a or r > e)
                cout << "Ihr Rateversuch liegt nicht im Zahlenbereich der zu erratenden Zahl!" << endl;
            if (x < r)
                cout << "Die gesuchte Zahl ist kleiner als ihr Versuch! Raten Sie erneut: " << endl;
            else
                cout << "Die gesuchte Zahl ist größer als ihr Versuch! Raten Sie erneut: " << endl;
            cin >> r;
            if (r==x)		// beendet Schleife frühzeitig beim richtigen erraten
                break;
            if (i==(v-1))   // v-1, da der erste Versuch außerhalb der Klammer passiert
            {
                cout << "Sie hatten " << v << " Rateversuche und haben es nicht geschafft, die richtige Zahl zu erraten!" << endl;
                return 0;
            }
        }
    }
    cout << "Glückwunsch Sie haben die richtige Zahl " << x << " erraten." << endl;

    return 0;
}
