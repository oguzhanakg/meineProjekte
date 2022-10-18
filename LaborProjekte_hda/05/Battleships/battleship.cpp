#include "battleship.h"
#include <iostream>
#include "gameboard.h"

using std::cin;
using std::endl;
using std::cout;


Battleship::Battleship(const std::string &player1Name, const std::string &player2Name) : m_players{player1Name, player2Name}
{

}

void Battleship::play()
{
    srand(time(nullptr));       // muss hier oder in Main aufgerufen werden, damit Schiffe unterschiedliche platziert werden
    m_boards.at(0).randomPlaceShips();     //boards der Spieler werden mit Schiffen gefüllt
    m_boards.at(1).randomPlaceShips();

    int aktiver, inaktiver;
    aktiver = 0;
    inaktiver =1;
    bool ende = true;


    while(ende)
    {
        cout << endl << "Spieler " << m_players[aktiver].getName() << " ist am Zug!";

        m_boards[aktiver].printBoard();
        m_boards[aktiver].printEnemyBoard();

        char r;
        int c, row, col;
        cout << "Welches Feld wollen Sie angreifen? Den Buchstaben zuerst eingeben!" << endl;
        cin >> r;
        cin >> c;

        if (r == 'a' or r == 'b' or r == 'c' or r == 'd' or r == 'e' or r == 'f' or r == 'g' or r == 'h' or r == 'i' or r == 'j')
            row = r -'a';
        else if (r == 'A' or r == 'B' or r == 'C' or r == 'D' or r == 'E' or r == 'F' or r == 'G' or r == 'H' or r == 'I' or r == 'J')
            row = r -'A';
        else
        {
            cout << "Sie haben eine falsche Eingabe getätigt!" << endl;
            continue;
        }

        if (c < 1 or c > 10)
        {
            cout << "Sie haben eine falsche Eingabe getätigt!" << endl;
            continue;
        }
        else
            col = c-1;      // -1 weil die Felder von 1 bis 10 beschriftet sind

        if (m_boards[inaktiver].hit(row, col)==true)
        {
            m_boards[aktiver].mark(row, col, true);
            cout << endl << "Sie haben ein Treffer!" << endl;
        }
        else
        {
            m_boards[aktiver].mark(row, col, false);
            cout << endl << "Sie haben ins Wasser geschossen!" << endl;
        }

        if (m_boards[inaktiver].allShipsSunk()==true)
        {
            cout << endl << m_players[inaktiver].getName() << " hat verloren!" << endl;
            m_players[inaktiver].addGameLost();
            cout << "Glückwunsch " << m_players[aktiver].getName() << " zum Sieg!" << endl;
            m_players[aktiver].addGameWon();
            ende = false;
        }

        int temp;
        temp = inaktiver;
        inaktiver = aktiver;
        aktiver = temp;         //Spielerwechsel
    }
}
