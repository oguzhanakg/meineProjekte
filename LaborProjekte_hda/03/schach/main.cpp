#include <iostream>
#include "figures.h"
#include <array>
#include <string>
#include <iomanip>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::array;
using std::setw;
using std::fill;
using std::fill_n;

const string leer = "______";
bool spieler = true;
bool quit = false;

void Starter()
{
    spieler = !spieler;
}

void Tausch(string z[reihe][spalte], int& x, int& y, int& c, int& v)
{

    const string leer = "______";
    if (z[c][v].find('K') ==  2)  // Spielbeenden wenn König geschlagen wird
    {
        z[c][v] = leer;
        string i;       // folgende Zeilen der move
        i = z[c][v];
        z[c][v] = z[x][y];
        z[x][y] = i;

        Spielfeld(z);

        cout << "Sie haben den gegnerischen König geschlagen und gewonnen! Glückwunsch!" << endl;
        quit = true;
    }
    else if (z[c][v].find('s') ==0 or z[c][v].find('w') ==0)     //Figur im Zielfeld
    {
        z[c][v] = leer;
        string i;       // folgende Zeilen der move
        i = z[c][v];
        z[c][v] = z[x][y];
        z[x][y] = i;
        cout << "Sie haben eine gegnerische Figur geschlagen!" << endl;
        Starter();

    }
    else                                                                //Leerfeld im Zielfeld
    {
        string i;       // folgende Zeilen der move
        i = z[c][v];
        z[c][v] = z[x][y];
        z[x][y] = i;
        Starter();
    }
}

int main()
{

    string f, z;   //f Startfeld; z Zielfeld
    string brett [reihe][spalte];

    for (size_t r=0; r < reihe; r++)
    {
        for (size_t s=0; s < spalte; s++)
        {
            brett[0][1] = wT;
            brett[0][2] = wS;
            brett[0][3] = wL;
            brett[0][4] = wD;
            brett[0][5]= wK;
            brett[0][6] = wL;
            brett[0][7]= wS;
            brett[0][8]= wT;
            brett[1][s]= wB;
            brett[2][s] = leer;
            brett[3][s] = leer;
            brett[4][s] = leer;
            brett[5][s] = leer;
            brett[6][s]= sB;
            brett[7][1]= sT;
            brett[7][2]= sS;
            brett[7][3]= sL;
            brett[7][4] = sD;
            brett[7][5] = sK;
            brett[7][6] = sL;
            brett[7][7] = sS;
            brett[7][8] = sT;
        }
    }

    while (quit != true)
    {
        Spielfeld(brett);

        if (spieler)    //Spieler der beginnt
            cout << "Spieler mit weißen Figuren am Zug!" << endl;
        else
            cout << "Spieler mit schwarzen Figuren am Zug!" << endl;
        cout << "Geben Sie das Startfeld und das Zielfeld der Figur an, dessen Zug Sie machen wollen.";
        cin >> f >> z;

        if (f == "quit" or z == "quit")
        return 0;

        Zug zug;
        zug.von.reihe = f[0] - 'a';
        zug.von.spalte = f[1] - '0';
        zug.nach.reihe = z[0] - 'a';
        zug.nach.spalte= z[1] - '0';

        if (spieler)        // nur weiße Figuren auswählbar
        {
            if (brett[zug.von.reihe][zug.von.spalte].find('w') == brett[zug.nach.reihe][zug.nach.spalte].find('w'))
            {
                cout << "Zug nicht möglich!" << endl;
                continue;
            }
            if (brett[zug.von.reihe][zug.von.spalte].find('w') != 0)
            {
                cout << "Keine weiße Figur ausgewählt!" << endl;
                continue;
            }
        }
        if (!spieler)       // nur schwarze Figuren auswählbar
        {
            if (brett[zug.von.reihe][zug.von.spalte].find('s') != 0)
            {
                cout << "Keine schwarze Figur ausgewählt!" << endl;
                continue;
            }
            if (brett[zug.von.reihe][zug.von.spalte].find('s') == brett[zug.nach.reihe][zug.nach.spalte].find('s'))
            {
                cout << "Zug ist nicht möglich!" << endl;
                continue;
            }
        }
        if (zug.von.reihe <= -1 or zug.von.reihe >= 8 or zug.von.spalte  <= 0 or zug.von.spalte  >= 9 or zug.nach.reihe <= -1 or zug.nach.reihe >= 8 or zug.nach.spalte <= 0 or zug.nach.spalte >= 9)   //f und z liegen im Spielfeld
        {
            cout << "Figur nicht auf dem Feld!" << endl;
            continue;
        }

        if (brett[zug.von.reihe][zug.von.spalte].find('S') ==  2)   //Spielzug für Springer
        {
            if ((zug.von.reihe+2 == zug.nach.reihe and zug.von.spalte+1 == zug.nach.spalte) or (zug.von.reihe+2 ==zug.nach.reihe && zug.von.spalte-1 ==zug.nach.spalte) || (zug.von.reihe+1 == zug.nach.reihe && zug.von.spalte+2 ==zug.nach.spalte) || (zug.von.reihe+1 ==zug.nach.reihe && zug.von.spalte-2 ==zug.nach.spalte) || (zug.von.reihe-1 == zug.nach.reihe && zug.von.spalte+2 ==zug.nach.spalte) || (zug.von.reihe-2 ==zug.nach.reihe && zug.von.spalte-1 ==zug.nach.spalte) || (zug.von.reihe-1 == zug.nach.reihe && zug.von.spalte-2 ==zug.nach.spalte) || (zug.von.reihe-2 == zug.nach.reihe && zug.von.spalte+1 == zug.nach.spalte))
            {               
                Tausch(brett, zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte);
            }
            else
            {
                cout << "Der Zug ist nicht möglich!" << endl;
                continue;
            }
        }
        else if (brett[zug.von.reihe][zug.von.spalte].find('L') ==  2)  // Spielzug vom Läufer
            {
                if (abs(zug.nach.reihe-zug.von.reihe)!= abs(zug.nach.spalte-zug.von.spalte))
                {
                    cout << "Zug ist nicht möglich!" << endl;
                    continue;
                }
                if (abs(zug.nach.reihe-zug.von.reihe)==0 && abs(zug.nach.spalte-zug.von.spalte)==0)
                {
                    cout << "Zug ist nicht möglich!" << endl;
                    continue;
                }
                Laeuferzug(brett, zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte);
            }

        else if (brett[zug.von.reihe][zug.von.spalte].find('T') ==  2)  // Spielzug für Turm
        {
            if (zug.von.reihe != zug.nach.reihe and zug.von.spalte != zug.nach.spalte)
            {
                cout << "Zug ist nicht möglich!" << endl;
                continue;
            }
            if (zug.von.reihe == zug.nach.reihe and zug.von.spalte == zug.nach.spalte)
            {
                cout << "Zug ist nicht möglich!" << endl;
                continue;
            }
            Turmzug(brett, zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte);
        }
        else
        {
            Tausch(brett, zug.von.reihe, zug.von.spalte, zug.nach.reihe, zug.nach.spalte);
        }
    }
    return 0;
}
