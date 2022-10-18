#include <iostream>
#include <vector>
#include <algorithm>
#include "isSorted.h"
#include "Timer.h"
#include "p4.h"

using namespace std;


bool isSorted(const vector<int> &a)
{
    int n = a.size();

    while (true)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (a[i] > a[i+1])
            {
                cout << "ist nicht sortiert!" << endl;
                return false;
            }
        }
        cout << "ist sortiert!" << endl;
        return true;
    }
}
