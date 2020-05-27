/*
 * Title: hw1_1.cpp
 * Abstract: This program reads an input file name given by a user which includes
 *           a list of numbers. Using this list, this program determines the closest distance
 *           between two numbers and appends a list of combinations if multiple combinations 
 *           have the same minimum value
 * Author: Randy Son
 * ID: 7774
 * Date: 1/08/2020
 */

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <utility>

using namespace std;

int main() {
    string fileName;
    /* Get input file name from user */
    cout << "Enter input file name: ";
    cin >> fileName;
    
    /* 
        Read file into dynamic array, noting that the first integer
        tells us how many integers are going into our dynamic array
    */
    ifstream infile(fileName);
    int arrSize;
    string sLine;

    /* Read first line of file */
    if (infile.good()) {
        getline(infile, sLine);
        arrSize = stoi(sLine);
    } else { // bad file
        return -1;
    }

    /* Create dynamic array using first line of input file as array size */
    int* numberArray;
    numberArray = new int [arrSize];

    /* Read the rest of the file and store into array */
    int i = 0;
    while (getline(infile, sLine)) {
        numberArray[i] = stoi(sLine);
        i += 1;
    }

   /*
        Loop through the array twice, using i as the initial number
        to compare distance with int j in the inner loop.

        As distances are positive values, take the absolute value of
        result, and compare to lowest value stored
    */
    int minDistance = 1e6, tmpValue = 0;
    set<pair<int, int>> numberPairs;

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize-1; j++) {
            tmpValue = abs((numberArray[i] - numberArray[j]));

            /* Min distance should be greater than 0 */
            if (tmpValue < minDistance && tmpValue != 0) {
                minDistance = tmpValue;
                numberPairs.clear();

                /* Insert the lower number first, this avoids duplicates */
                if (numberArray[i] < numberArray[j])
                    numberPairs.insert(make_pair(numberArray[i], numberArray[j]));
                else
                    numberPairs.insert(make_pair(numberArray[j], numberArray[i]));
    
            /* If the distance is the same, add the number combination to our set*/
            } else if (tmpValue == minDistance) {
                if (numberArray[i] < numberArray[j])
                    numberPairs.insert(make_pair(numberArray[i], numberArray[j]));
                else
                    numberPairs.insert(make_pair(numberArray[j], numberArray[i]));
            }
        }
    }
    
    /* Output results */
    cout << "Min distance: " << minDistance << endl;
    for (auto x : numberPairs) {
        cout << "Two numbers for min distance: " << x.first
             << " and " << x.second << endl;
    }
    cin >> sLine;
    return 0;
}