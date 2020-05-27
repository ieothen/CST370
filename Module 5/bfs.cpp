/*
 * Title: bfs.cpp
 * Abstract: This program takes in an input file that is read in
 *           as an adjacency matrix and implements the BFS algorithm
 *           utilizing a queue.
 * Author: Randy Son
 * ID: 7774
 * Date: 2/04/2020
 */

#include <iostream>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    string fileName;

    /* Get input file name from user */
    cout << "Enter a filename: ";
    cin >> fileName;
    
    /* Read first character from file */
    ifstream infile;
    int arrSize;
    string sLine;

    infile.open(fileName);
    infile >> arrSize;

    /* Create dynamic matrix using first line of input file as array size */
    int** adjMatrix = new int* [arrSize];
    bool* marked = new bool [arrSize];

    for (int i = 0; i < arrSize; i++) {
        adjMatrix[i] = new int [arrSize];
        marked[i] = false;
    }

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

    /* Get start vertex from user */
    int startVertex;
    cout << "Enter a start vertex: ";
    cin >> startVertex;

    /* BFS implementation beginning at startVertex */
    queue<int> nodeQueue;
    marked[startVertex] = true;
    nodeQueue.push(startVertex);

    while(!nodeQueue.empty()) {
        startVertex = nodeQueue.front();
        cout << startVertex;

        for (int y = 0; y < arrSize; y++) {
            if (adjMatrix[nodeQueue.front()][y] == 1 && !marked[y]) {
                marked[y] = true;
                nodeQueue.push(y);
            }
        }
        nodeQueue.pop();
        if (!nodeQueue.empty())
            cout << " -> ";
    }

    return 0;
}