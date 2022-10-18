#include <iostream>
#include <vector>
#include "p4.h"
#include "insertion_sort.h"
#include "Timer.h"

using std::endl;
using std::vector;

void insertionSort(vector<int>& v)
{
int tmp;
int j;

 for (int i = 1; i < v.size(); i++)
 {
     j = i-1;
     tmp = v[i];
     while (j >= 0 && tmp < v[j])
     {
           v[j+1] = v[j];
           j = j-1;
     }
     v[j+1]=tmp;
 }
}

