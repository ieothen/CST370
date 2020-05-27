/*
 * Title: assignment.cpp
 * Abstract: This program takes input from user detailing
 *           cost of a job per person. From this, the program
 *           runs through every permutation and determines
 *           the best way to assign jobs according to cost.
 * Author: Randy Son
 * ID: 7774
 * Date: 2/04/2020
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int numJobs;

    /* Get number of jobs from user */
    cout << "Enter number of jobs: ";
    cin >> numJobs;
    
    int costMatrix[numJobs][numJobs];

    /* Get assignment costs from user */
    cout << "Enter assignment costs of " << numJobs << " persons: " << endl;
    for (int x = 0; x < numJobs; x++) {
        cout << "Person " << x+1 << ": ";

        for (int y = 0; y < numJobs; y++) {
            cin >> costMatrix[x][y];
        }
    }

    cout << endl <<  "Output:" << endl;

    /* 
        Given an m x m matrix, where m is numJobs,
        create an array with values starting from 0
        to numJobs

        If numJobs = 3, then create array {0, 1, 2}
        and permute off of that
    */
    int jobsArray[numJobs];
    for (int i = 0; i < numJobs; i++)
        jobsArray[i] = i;
    
    int i = 1;
    int minCost = 1e6;
    int tmpCost;
    vector<int> minVector;
    vector<int> tmpVector;

    /* 
        Generate each permutation using next_permutation.
        Cross reference each permutation with costMatrix,
        then keep track of minCost and store permutation in
        minVector if a new minCost is found.
    */
    do {
        tmpCost = 0;
        tmpVector.clear();
        cout << "Permutation " << i << ": <";

        for (int j = 0; j < numJobs; j++) {
            if (j != numJobs - 1)
                cout << jobsArray[j] + 1 << ", ";
            else
                cout << jobsArray[j] + 1;
            tmpVector.push_back(jobsArray[j]);
            tmpCost += costMatrix[j][jobsArray[j]];
        }
        if (tmpCost < minCost) {
            minVector.clear();
            copy(tmpVector.begin(), tmpVector.end(), back_inserter(minVector));
            minCost = tmpCost;
        }

        cout << "> => total cost: " << tmpCost << endl;
        i++;
    } while (next_permutation(jobsArray, jobsArray + numJobs));

    /* Output lowest cost permutation */
    cout << endl << "Solution: <";
    for (int j = 0; j < numJobs; j++) {
        if (j != numJobs - 1)
            cout << minVector[j] + 1 << ", ";
        else
            cout << minVector[j] + 1;
    }
    cout << "> => total cost: " << minCost << endl;

    return 0;
}