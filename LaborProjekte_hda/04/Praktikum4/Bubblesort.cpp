#include <iostream>
#include <vector>
#include <algorithm>
#include "Bubblesort.h"
#include "p4.h"
#include "Timer.h"

using namespace std;

void bubbleSort(vector<int>& a)
{

    for(int i=0; i<= a.size();i++)
    {
        for (int j=0; j < (a.size()-1); j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
