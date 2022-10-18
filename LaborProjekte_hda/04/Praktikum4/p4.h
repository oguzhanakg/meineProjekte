/**
 * \file p4.h
 * \author Michael Roth
 * \date 15.05.2019, last changed 29.11.2021
 *
 */

#ifndef P4_H
#define P4_H
#include <vector>
using std::vector;

#include <string>
using std::string;

/**
 * @brief Checks if vector is sorted in ascending order
 * @param[in] v The vector to be checked
 * @return true if elements in v are sorted in an ascending order, false
 * otherwise
 */
bool isSorted(const vector<int>& v);

/**
 * @brief Sorts vector v in place using Bubble Sort
 * @param[in, out] v The vector to be sorted
 */
void bubbleSort(vector<int>& v);

/**
 * @brief Sorts vector v in place using Insertion Sort
 * @param[in, out] v The vector to be sorted
 */
void insertionSort(vector<int>& v);

/**
 * @brief Sorts vector v by using the Bucket Sort algorithm
 * @param[in,out] v The vector to be sorted
 */
void bucketSort(vector<int>& v);

/**
 * @brief Fills a vector with random values
 * @param[in, out] v The vector to be filled
 *
 * The function expects a vector to be correctly sized, e.g. `vector<int>
 * v(100)` and then passed to this function.
 * The vector is to be filled from v[0] to v[v.size()-1] with random numbers.
 * You can find an example for creating random numbers in the provided main.cpp
 */
void fillVector(vector<int>& v);

/**
 * @brief Checks if a given string is a palindrome
 * @param[in] p the string to be checked
 * @return True if \ref p was a palindrome, false otherwise
 *
 * This functions checks if the parameter string \ref p is a palindrome.
 * Colloquially, this means that the string can be read forwards and backwards
 * while having the same meaning.
 *
 * On a more format note, letter capitalization and punctuation as well as
 * whitespaces shall be ignored. So 'Anna' is palindrome, as well as 'Pur ist
 * Saft fast Sirup'.
 */
bool isPalindrome(const string& p);

#endif // P4_H
