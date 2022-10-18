#include "ship.h"
#include <iostream>

Ship::Ship()
{

}

Ship::Ship(int row, int col, int lengthOfShip, Direction direction)
{
    if (Direction::north == direction)
    {
        if ((row - lengthOfShip+1) >= 0)
        {
            for (int i =0; i < lengthOfShip; i++)
            {
                m_parts.push_back(Part(row, col));
                row--;              // damit der Pushback nicht immer im gleichen Feld passiert
            }
        }
    }
    if (Direction::east == direction)
    {
        if ((col + lengthOfShip-1) <= 9)
        {
            for (int i =0; i < lengthOfShip; i++)
            {
                m_parts.push_back(Part(row, col));
                col++;
            }
        }
    }
    if (Direction::south == direction)
    {
        if ((row + lengthOfShip-1) <= 9)
        {
            for (int i =0; i < lengthOfShip; i++)
            {
                m_parts.push_back(Part(row, col));
                row++;
            }
        }
    }
    if (Direction::west == direction)
    {
        if ((col - lengthOfShip+1) >= 0)
        {
            for (int i =0; i < lengthOfShip; i++)
            {
                m_parts.push_back(Part(row, col));
                col--;
            }
        }
    }
}

bool Ship::hasPartIn(int row, int col)
{
    for (Part &part : m_parts)       //geht den Vector durch
    {
        if(part.getRow() == row and part.getCol() == col)
            return true;
    }
    return false;
}

Part &Ship::getPartIn(int row, int col)
{    
    for(int i=0; i< m_parts.size(); i++ )
    {
        if(m_parts[i].getRow() == row and m_parts[i].getCol() == col)
            return m_parts[i];                  //Gibt die Referenz auf das Schiffteil zurück
    }
}

bool Ship::isDamaged()
{
    for (Part &part : m_parts)
    {
        if (part.isDamaged()==true)       //wenn einer der Parts damaged ist gibts true aus
            return true;
    }
    return false;
}

bool Ship::isSunk()
{
    for (Part &part : m_parts)
    {
        if (part.isDamaged() == false)       //wenn einer der Parts damaged ist gibts false aus und beendet die Überprfung
            return false;
    }
    return true;    //wenn alle Teile durchsucht wurden und alle Damaged sind gibts true aus
}
