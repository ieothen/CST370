/*
 * Title: prim.cpp
 * Abstract: This program implements Prim's algorithm
 *           to calculate the minimum spanning tree (MST)
 * Author: Randy Son
 * ID: 7774
 * Date: 2/25/2020
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int minKey(int* key, bool* mstSet, int vertices) { 
    int min = 1e6, min_index; 
  
    for (int i = 0; i < vertices; i++) 
        if (mstSet[i] == false && key[i] < min) {
            min = key[i];
            min_index = i; 
        }
            
  
    return min_index; 
} 

int main() {
    int startVertex;
    string fileName;
    
    /* Get inputs from user */
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << "Enter the first vertex to start: ";
    cin >> startVertex;
    cout << endl;
    
    /* Read edge/vertex information into adjacency matrix */
    ifstream infile;
    int vertices, edges;
    infile.open(fileName);   
    infile >> vertices;
    infile >> edges;
    
    int adjMatrix[vertices][vertices] = {0};
	
	for (int i = 0; i < edges; i++){
	    int x, y, weight; 

	    infile >> x >> y >> weight;
	    adjMatrix[x-1][y-1] = weight; // Offset by one to account for t1.txt edges starting at 1
	    adjMatrix[y-1][x-1] = weight;
	}
    
    /* Output adjacency matrix for sanity's sake */
    cout << "Adjacency Matrix: " << endl;
    for (int i = 0; i < vertices; i++){    
		for (int j = 0; j < vertices; j++){
			cout << adjMatrix[i][j] << " ";
		}
        cout << endl; 
	}

    /* Prim's algorithm */
    int parent[vertices]; 
    int key[vertices]; 
    bool mstSet[vertices] = {0}; 
    
    /* Set keys to big number, to compare viable paths with */
    for (int i=0; i < vertices; i++) 
        key[i] = 1e6; 
  
    key[startVertex-1] = 0; 
    parent[startVertex-1] = -1;  
  
    for (int count = 0; count < vertices-1; count++) { 
        /* Pick minimum vertex available from set */
        int i = minKey(key, mstSet, vertices); 

        /* Add picked vertex to set */
        mstSet[i] = true; 

        /* Loop through all vertices, looking at each
           vertices not in MST yet and update key for which
           edge is smaller than current vertice key */
        for (int j = 0; j < vertices; j++) 
            if (adjMatrix[i][j] && mstSet[j] == false && adjMatrix[i][j] < key[j]) {
                parent[j] = i;
                key[j] = adjMatrix[i][j]; 
            }
    } 
    
    /* Output */
    for (int i = 1; i < vertices; i++) 
        cout << "(" << i << ") New edge: " << parent[i] + 1 << "," << i+1 << " - cost " << adjMatrix[i][parent[i]] << endl;
    
    return 0;
}
