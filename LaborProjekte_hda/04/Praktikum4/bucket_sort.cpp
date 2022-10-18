#include <iostream>
#include <vector>
#include "p4.h"
#include "bucket_sort.h"
#include "Timer.h"
#include <algorithm>
#include <numeric>

using std::endl;
using std::vector;
using std::cout;


void bucketSort(vector<int>& k)
{
    int max = *std::max_element(begin(k), end(k));  //größtes Element in k
    int n = k.size();   // Anzahl der Buckets
    vector<int> b[n];   // Bucketvector

    for (int i = 0; i < n; i++) {
        int bi = (n * k[i]) / (max+1);
        b[bi].push_back(k[i]);
    }

    for (int i = 0; i < n; i++){
        insertionSort(b[i]);        // Sortierverfahren
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            k[index++] = b[i][j];   // Buckets zusammenfügen in den Vector k
}

void rek_bucketSort(vector<int>& k)
{
    int max = *std::max_element(begin(k), end(k));
    int n = k.size();   //Anzahl der Buckets n
    vector<int> b[n];

    for (int i = 0; i < n; i++)
    {
        int bi = (n * k[i]) / (max+1);
        b[bi].push_back(k[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i].size() > 2)    // k = 2
        {
            for (int j = 0; j < n; j++) //erneute Aufteilung in Buckets
            {
                int maxx = *std::max_element(begin(b[i]), end(b[i]));
                int p = b[i].size();
                vector<int> c[p];
                int bj = (p * b[i].size()) / (maxx+1);
                c[bj].push_back(k[i]);
            }
        }
        if (b[i].size() <= 2)
            insertionSort(b[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            k[index++] = b[i][j];
}
