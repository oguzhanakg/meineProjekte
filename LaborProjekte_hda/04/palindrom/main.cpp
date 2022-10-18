#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;


bool isPalindrom(const string& p)
{
    float l = p.size()/2;   // l ist die Mitte des Strings bis der gewechselt wird
    string c = p;   // Kopie des eigegeben Strings


    for (int i =0; i < c.size(); i++)
        c[i] = tolower(c[i]);       // Alle Zeichen werden klein

    string umkehr = c;

    for (int i=0; i<l; i++)
         swap(umkehr[0+i], umkehr[c.size()-i-1]); //Tauschen der Werte
    cout << umkehr << endl;

    if (c.find(' ') == c.find(' '))
    {
      c.erase(remove(c.begin(), c.end(), ' '), c.end());   // Leerzeichen entfernen
      umkehr.erase(remove(umkehr.begin(), umkehr.end(), ' '), umkehr.end());
    }


    cout << umkehr << endl << c << endl;
    bool palindrom;
    if (c == umkehr)
        palindrom = true;
    else
        palindrom = false;

    cout << palindrom << endl;  //gibt 0 oder 1 aus
}



int main()
{
    string p;
    cout << "Geben Sie ein, was Sie auf Palindrom überprüfen wollen: " << endl;
    getline(cin, p);
    isPalindrom(p);
    return 0;
}
