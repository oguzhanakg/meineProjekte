#include <iostream>
#include <vector>
#include "p4.h"
#include "insertion_sort.h"
#include "bucket_sort.h"
#include "Timer.h"
#include "Zufallswerte.h"
#include "Bubblesort.h"
#include "isSorted.h"
#include <random>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


void vectorAusgabe(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " " << endl;
    }
}

int main()
{
    int g = 1000;    // Größe des Vectors
    vector<int> v(g);
    fillVector(v);  // Vector mit zufälligen Zahlen füllen
    isSorted(v);    //sollte false ausgeben, da noch kein Sortierverfahren angewendet wurde
    cout << endl;

    {
        Timer t("Zeit zum Sortieren: ");
        {
            //Geben Sie das Sortierverfahren in die Klaamer ein und starten sie das Programm im Release Mode

            //for (int i = 0; i < g; i++)  //Bei Verwendung von bucketsort und rek_bucketsort benutzen


        }
    }
    //verschiedene Sortierverfahren, das gewünschte auswählen und die anderen mit "//" nicht ausführen lassen

    //bubbleSort(v);
    //insertionSort(v);
    rek_bucketSort(v);
    //bucketSort(v);

    vectorAusgabe(v);     //den Sortieren Vector ausgeben lassen
    isSorted(v);    //sollte true sein, wenn vorher ein Sortierverfahren ausgewählt wurde
    return 0;
}
