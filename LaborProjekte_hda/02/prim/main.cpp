#include <iostream>

using namespace std ;
int main ( void )
{
    int zahl , i , anz =0;

    cout << " Gib eine natürliche Zahl ein : ";
    cin >> zahl ;

    cout << " Zerlegung : ";
    if (zahl == 1)                      // wenn es genau 1 ist sollte es ausgeführt werden
        cout << "1";
    else
    {
        for ( i =2; i <= zahl ; i ++)   // Die for-Schleife ist als Kontrollstruktur da
        while (zahl%i == 0)             // while-Schleife wiederholt Anweisungen, solange die Bedingung true liefert
        {
            if ( anz == 0)
                cout << i ;
            else
                cout << " * " << i ;
            anz ++;
            zahl /= i;
        }
    }
    cout << endl;
    return 0;
}
