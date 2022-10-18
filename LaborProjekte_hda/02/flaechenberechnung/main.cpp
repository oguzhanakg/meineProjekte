#include <iostream>

using namespace std;

int main()
{
    char i;

    constexpr double pi = 3.14159;	// Pi ist festgelegt
    float a;
    float b;
    float s;
    float g;
    float h;

    do
    {
        cout << "Herzlich Willkommen zum Flächenberechner !" << endl;
        cout << endl;
        cout << "Von welcher geometrischen Figur soll die Fläche berechnet werden?" << endl;
        cout << endl;
        cout << "k) Kreis" << endl;
        cout << "r) Rechteck" << endl;
        cout << "d) Dreieck" << endl;
        cout << endl;
        cout << "q) Beenden" << endl;
        cin >> i;

        switch (i)
        {
        case 'k':
            cout << "Geben Sie den Radius an:"  << endl;
            cout << "Radius: ";
            cin >> s;
            cout << "Flächeninhalt: " << s * s * pi << endl;
            cout << endl;
            continue;		// fängt am Anfang der do-while Schleife an
        case 'r':
            cout << "Geben Sie Länge und die Breite des Rechtecks an." << endl;
            cout << "Länge: ";
            cin >> a;
            cout << "Breite: ";
            cin >> b;
            cout << "Flächeninhalt: "  << a * b << endl;
            cout << endl;
            continue;
        case 'd':
            cout << "Geben Sie die Grundlänge und die Höhe an:" << endl;
            cout << "Grundlänge: ";
            cin >> g;
            cout << "Höhe: ";
            cin >> h;
            cout << "Flächeninhalt: "  << g * h / 2 << endl;
            cout << endl;
            continue;
        case 'q':
            break;			// abbruch
        default:
            cout << endl;
            continue;
        }
    return 0;				// Programm wird wirklich geschlossen
    } while (true);
}
