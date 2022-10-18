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


void Turmzug(string o[reihe][spalte], int& zugVR, int& zugVS, int& zugNR, int& zugNS)
{
    if (zugVR+1 == zugNR or zugVR-1 ==zugNR or zugVS+1 == zugNS or zugVS-1 ==zugNS)
    {
        Tausch(o, zugVR, zugVS, zugNR, zugNS);
    }
    else if (zugVR < zugNR)
    {
        for (int i =zugVR+1; i < zugNR; i++)
        {
            if(o[i][zugVS].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == zugNR-1 and o[i][zugNS].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVR > zugNR)
    {
        for (int i =zugNR+1; i < zugVR; i++)
        {
            if(o[i][zugVS].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == zugVR-1 and o[i][zugNS].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVS < zugNS)
    {
        for (int i = zugVS+1; i < zugNS; i++)
        {
            if(o[zugNR][i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == zugNS-1 and o[zugNR][i].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVS > zugNS)
    {
        for (int i = zugNS+1; i < zugVS; i++)
        {
            if(o[zugNR][i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == zugVS-1 and o[zugNR][i].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
}

void Laeuferzug(string o[reihe][spalte], int& zugVR, int& zugVS, int& zugNR, int& zugNS)
{
    if ((zugVR+1 == zugNR  and zugVS+1 == zugNS) or (zugVR+1 == zugNR  and zugVS-1 == zugNS) or (zugVR-1 == zugNR  and zugVS+1 == zugNS) or (zugVR-1 == zugNR  and zugVS-1 == zugNS))
    {
        Tausch(o, zugVR, zugVS, zugNR, zugNS);
    }
    else if (zugVR < zugNR and zugVS < zugNS)
    {
        for (int i =1; i < abs(zugNR-zugVR); i++)
        {
            if(o[zugVR+i][zugVS+i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == abs(zugNR-zugVR)-1 and o[zugNR-1][zugNS-1].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVR > zugNR and zugVS > zugNS)
    {
        for (int i =1; i < abs(zugNR-zugVR); i++)
        {

            if(o[zugVR-i][zugVS-i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == abs(zugNR-zugVR)-1 and o[zugVR-1][zugVS-1].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVR > zugNR and zugVS < zugNS)
    {
        for (int i = 1; i < abs(zugNR-zugVR); i++)
        {

            if(o[zugVR-i][zugVS+i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == abs(zugNR-zugVR)-1 and o[zugVR-1][zugVS+1].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
    else if (zugVR < zugNR and zugVS > zugNS)
    {
        for (int i = 1; i < abs(zugNR-zugVR); i++)
        {

            if(o[zugVR+i][zugVS-i].find('_') != 0)
            {
                cout << "Zug nicht möglich!" << endl;
                break;
            }
            else if (i == abs(zugNR-zugVR)-1 and o[zugVR+1][zugVS-1].find('_') == 0)
            {
                Tausch(o, zugVR, zugVS, zugNR, zugNS);
                break;
            }
            else{}
        }
    }
}
