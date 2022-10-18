#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "player.h"
#include "battleship.h"

int main()
{
    string player1, player2;
    cout << "Geben Sie den Namen des 1 Spielers ein: ";
    cin >> player1;
    cout << "Gebens Sie den Namen des 2 Spieler ein: ";
    cin >> player2;

    Battleship B(player1, player2);
    B.play();
    return 0;
}
