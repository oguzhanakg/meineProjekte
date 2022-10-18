#include "gameboard.h"
#include <iostream>

using std::cout;
using std::endl;

GameBoard::GameBoard()
{
    for (int r=0; r < 10; r++)
    {
        for(int c = 0; c < 10; c++)
        {
            m_enemyBoard[r][c]= '.';
        }
    }
}

void GameBoard::printBoard()
{
    array<array<char, 10>, 10> board;
    char water = '.';
    char a = 'A';
    char x = 'X';
    char s = 'S';

    for (int r=0; r < 10; r++)
    {
        for(int c = 0; c < 10; c++)
        {
            board[r][c]= water;
            for (int i =0; i < m_ships.size(); i++)
            {


                if (m_ships[i].hasPartIn(r, c)== true)  //kontrollieren ob ein Part drin ist
                {                
                    Part &part = m_ships[i].getPartIn(r, c);
                    if (part.isDamaged()==true and m_ships[i].isSunk() == true)
                        board[part.getRow()][part.getCol()] = s;
                    else if (part.isDamaged()==true)
                        board[part.getRow()][part.getCol()] = x;
                    else
                        board[part.getRow()][part.getCol()] = static_cast<char>(i+48);
                }
            }
        }
    }


    cout << endl << "Dein Spielfeld mit deinen Schiffen: " << endl << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for (int r=0; r < 10; r++)
    {
        cout << a << " ";
        for(int c = 0; c < 10; c++)
        {
            cout << board[r][c] << ' ';
        }
        a++;
        cout << endl;
    }
}

void GameBoard::printEnemyBoard()
{
    cout << endl << "Dein Schmierzettel:" << endl;
    for (size_t r = 0; r < 10; r++)
    {
        for (size_t c = 0; c < 10; c++)
        {
            cout << m_enemyBoard[r][c] << ' ';
        }
        cout << endl;
    }
}

bool GameBoard::hit(int row, int col)
{
    for(Ship &ship : m_ships)
        if(ship.hasPartIn(row, col))
        {
            ship.getPartIn(row, col).setDamaged();  //setzt den Schaden für den Part
            return true;
        }
    return false;
}

void GameBoard::mark(int row, int col, bool wasHit)
{
    if(wasHit==true)
        m_enemyBoard[row][col] = 'X';
    else
        m_enemyBoard[row][col] = 'O';
}

//Hilfsfunktion für randomShips

bool GameBoard::platzierung(int row, int col, int lengthOfShip, Direction direction)
{
    if (Direction::north == direction)
    {
        if ((row - lengthOfShip+1) < 0)
            return false;
        Ship ship =Ship(row, col, lengthOfShip, direction);
        {
            for (int i = row; i >= (row-lengthOfShip-1); i--)
            {
                for (Ship& ship : m_ships)
                {
                    if( ship.hasPartIn(i, col))
                        return false;
                }
            }
        }
    }
    else if (Direction::east == direction)
    {
        if ((col + lengthOfShip-1) > 9)
            return false;
        Ship ship =Ship(row, col, lengthOfShip, direction);
        {
            for (int i = col; i <= (col+lengthOfShip-1); i++)
            {
                for (Ship& ship : m_ships)
                {
                    if( ship.hasPartIn(row, i))
                        return false;
                }
            }
        }
    }
    else if (Direction::south == direction)
    {
        if ((row + lengthOfShip-1) > 9)
            return false;
        Ship ship =Ship(row, col, lengthOfShip, direction);
        {
            for (int i = row; i <= (row+lengthOfShip-1); i++)
            {
                for (Ship& ship : m_ships)
                {
                    if( ship.hasPartIn(i, col))
                        return false;
                }
            }
        }
    }
    else if (Direction::west == direction)
    {
        if ((col - lengthOfShip+1) < 0)
            return false;
        Ship ship =Ship(row, col, lengthOfShip, direction);
        {
            for (int i = col; i >= (col-lengthOfShip-1); i--)
            {
                for (Ship& ship : m_ships)
                {
                    if( ship.hasPartIn(row, i))
                        return false;
                }
            }
        }
    }
    return true;
}

void GameBoard::randomPlaceShips()
{
    int shipparts= 5;
    int randRow=0;
    int randCol=0;
    int shipnumber=0;
    Direction dir;

    for (int i=1; i <5; i++)
    {
        for (int j=1; j <=i; j++)
        {
            bool pruefen = false;
            while (!pruefen)
            {
                randRow = rand()%10;    //10 Anzahl der Reihen
                randCol = rand()%10;
                dir =Direction(rand()%4);     // soll für north, south, west, east stehen

                if(platzierung(randRow, randCol, shipparts, dir)==true)
                    pruefen = true;
            }
            m_ships[shipnumber]=Ship(randRow, randCol, shipparts, dir);
            shipnumber++;
        }
        shipparts--;
    }
}

bool GameBoard::allShipsSunk()
{
    for (Ship &ship : m_ships)
    {
        if(ship.isSunk()==false)
            return false;
    }
    return true;
}


