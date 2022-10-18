#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include "Timer.h"
#include "p4.h"

using namespace std;

void fillVector(vector<int>& v)
{
    srand((unsigned)time(NULL));

    for (int i = 0; i < v.size(); i++)
    {
       v[i] = rand() % 10000;   //Zufallszahlen bis 10000
       cout << v[i] << endl;
    }
}
