#ifndef FIGURES_H
#define FIGURES_H

#include <string>
using std::string;

const string sD="s_Dame";
const string sK="s_Koenig";
const string sL="s_Laeufer";
const string sT="s_Turm";
const string sS="s_Springer";
const string sB="s_Bauer";
const string wD="w_Dame";
const string wK="w_Koenig";
const string wT="w_Turm";
const string wS="w_Springer";
const string wL="w_Laeufer";
const string wB="w_Bauer";
constexpr size_t reihe=8;
constexpr size_t spalte=10;

struct Pos
{
    int reihe;
    int spalte;
};

struct Zug
{
    Pos von;
    Pos nach;
};

void Tausch(string z[reihe][spalte], int& x, int& y, int& c, int& v);
void Spielfeld(string z[reihe][spalte]);
void Turmzug(string o[reihe][spalte], int& r, int& t, int& a, int& s);
void Starter();
void Laeuferzug(string o[reihe][spalte], int& r, int& t, int& a, int& s);

#endif // FIGURES_H
