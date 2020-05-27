/*
 * Title: select-sort-k.cpp
 * Abstract: This program is a modified version of the selection sort
 *           algorithm that stops after k minimum values found, returning
 *           a sorted list of k elements.
 * Author: Randy Son
 * ID: 7774
 * Date: 2/04/2020
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string fileName;

    /* Get input file name from user */
    cout << "Enter a file name: ";
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

    /* Use vector container to store our numbers */
    vector<int> numberArray;

    /* Read the rest of the file and store into array */
    int i = 0;
    while (getline(infile, sLine)) {
        numberArray.push_back(stoi(sLine));
    }

    /* Get k value from user, which is the number of sorted values */
    int k;
    cout << "Enter the value k: ";
    cin >> k;

    /* Create new array of k length */
    vector<int> sortedArray;

    int minValue = 1e6;
    int minIndex = 0;

    /* Loop k-1 times until values are found */
    for (int i = 0; i < k; i++) {
        /* Look for minimum values and store them and their index */
        for (int j = 0; j < numberArray.size(); j++) {
            if (numberArray[j] < minValue) {
                minValue = numberArray[j];
                minIndex = j;
            }
        }

        /* Store found min value and push into array. 
           Pop the index off original array */
        sortedArray.push_back(minValue);
        numberArray.erase(numberArray.begin() + minIndex);
        minValue = 1e6;
    }

    /* Output */
    cout << "Output: " << endl;
    for (auto i : sortedArray) {
        cout << i << endl;
    }

    return 0;
}