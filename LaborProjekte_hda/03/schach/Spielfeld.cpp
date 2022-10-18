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



void Spielfeld(string z[reihe][spalte])
{
    for (size_t r=0; r < reihe; r++)
    {
        for (size_t s=0; s < spalte; s++)
        {
            z[0][0] = 'A';
            z[0][9] = 'A';
            z[1][0] = 'B';
            z[1][9] = 'B';
            z[2][0]= 'C';
            z[2][9] = 'C';
            z[3][0]= 'D';
            z[3][9]= 'D';
            z[4][0]= 'E';
            z[4][9] = 'E';
            z[5][0] = 'F';
            z[5][9] = 'F';
            z[6][0] = 'G';
            z[6][9]= 'G';
            z[7][0]= 'H';
            z[7][9]= 'H';
        }
    }

    constexpr int feld_wid =8;

    cout << setw(5) << "1" << setw(5) <<  "2" << setw(5) << "3" << setw(5) << "4" << setw(5) <<  "5" << setw(5) << "6" << setw(5) << "7" <<  setw(5) << "8" << endl;
    for (size_t r=0; r < reihe ; r++)
    {
        for(size_t s=0; s <spalte; s++)
        {
            cout.width(feld_wid);
            cout << z [r][s];
        }
        cout << endl;
    }
    cout << endl << setw(5) << "1" << setw(12) <<  "2" << setw(12) << "3" << setw(12) << "4" << setw(12) <<  "5" << setw(12) << "6" << setw(12) << "7" <<  setw(12) << "8" << endl;
    cout << endl;
}

