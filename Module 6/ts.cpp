/*
 * Title: ts.cpp
 * Abstract: This program implements the topological
 *           sorting algorithm. With the input of an 
 *           adjacency matrix, a vertex with no incoming
 *           edges is deleted from the DAG on each 
 *           iteration and a linear ordering of elements
 *           is output
 * Author: Randy Son
 * ID: 7774
 * Date: 2/11/2020
 */

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    string fileName;

    /* Get input file name from user */
    cout << "Enter filename: ";
    cin >> fileName;
    
    /* Read first character from file */
    ifstream infile;
    int arrSize;
    string sLine;

    infile.open(fileName);
    infile >> arrSize;

    /* Create matrix using first line of input file as array size */
    int adjMatrix[arrSize][arrSize];
    bool visitedList[arrSize] = {0};

    /* Read the rest of the file and store into matrix character by character */
    for (int x = 0; x < arrSize; x++) {
        for (int y = 0; y < arrSize; y++) {
            infile >> adjMatrix[x][y];
        }
    }

    /* Print adjacency matrix */
    cout << "Input Adjacency Matrix: " << endl;
    for (int x = 0; x < arrSize; x++) {
        for (int y = 0; y < arrSize; y++) {
            cout << adjMatrix[x][y] << " ";
        }
        cout << endl;
    }

    queue<int> nodeQueue;

    /* Loop through each vertex */
    for (int i = 0; i < arrSize; i++) {
        int degreeList[arrSize] = {0};

        /* Calculate degree list, which shows
           how many connections a node has */
        for (int x = 0; x < arrSize; x++) {
            for (int y = 0; y < arrSize; y++) {
                degreeList[x] += adjMatrix[y][x];
            }
        }

        /* Start at first vertex that has degree of 0
           (no incoming edges) and has not been visited
           yet */
        for (int j = 0; j < arrSize; j++) {
            if (degreeList[j] == 0 && !visitedList[j]) {
                nodeQueue.push(j);
                visitedList[j] = true;
                break;
            }
        }

        /* Remove newly pushed node in adjacency list by filling with 0's */
        for (int k = 0; k < arrSize; k++) {
            adjMatrix[nodeQueue.back()][k] = 0;
        }
    }

    /* Output */
    cout << "Topological sort: ";
    while (!nodeQueue.empty()) {
        cout << nodeQueue.front();

        nodeQueue.pop();
        if (!nodeQueue.empty())
            cout << " -> ";
    }
    return 0;
}