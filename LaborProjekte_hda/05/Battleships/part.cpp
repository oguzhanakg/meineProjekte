#include "part.h"
#include <iostream>

Part::Part(int row, int col) : m_row(row), m_col(col), m_status(0)  //Part wird unbeschädigt erstellt
{
}

bool Part::isDamaged() const
{
    if (m_status ==0)
        return false;   //kein Schaden am Part
    else if (m_status ==1)
        return true;
}

void Part::setDamaged()
{
    m_status =1;
}

int Part::getRow() const
{
    return m_row;
}

int Part::getCol() const
{
    return m_col;
}
