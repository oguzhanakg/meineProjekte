#include <iostream>
#include <algorithm>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;

int main()
{
        int a;      // Eingabewert
        float d;    // Durchschnitt
        float sum = 0;
        int g =0;   // größter Wert
        int k =0;   // kleinster Wert
        cout << "Geben Sie beliebige Ganzzahlen an, bei 0 oder einer Minuszahl wird die Eingabe beendet!" << endl;

        while(true) // läuft so lange bis durch die if-Bedingung beendet wird
        {
            cin >> a;

            if(a <= 0)
                return 0;   // Beendet die Schleife

            if (a < g or a == g)
                 cout << "Die größte Zahl ist: " << g << "\n";
            else
            {
                g = a;
                cout << "Die größte Zahl ist: " << g << "\n";
            }
            if (g == 0 or k == 0)   // bei Eingabe der ersten Zahl, damit keine 0 ausgegeben wird
            {
                g = a;
                k = a;
                cout << "Die kleinste Zahl ist: " << k << "\n";
            }
            else if (a > k or a == k)
            {
                cout << "Die kleinste Zahl ist: " << k << "\n";
            }
            else
            {
                k = a;
                cout << "Die kleinste Zahl ist: " << k << "\n";
            }

                sum += a;
                cout << "Die Summe aller eingegeben Zahlen: " << sum << endl;
                d = sum/2;
                cout << "Der Durchschnitt aller eingegebenen Zahlen: " << d << "\n";
                cout << endl;

        }
}
