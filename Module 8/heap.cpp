/*
 * Title: heap.cpp
 * Abstract: This program implements heap operations, taking
 *           in numbers from the user and displaying if it is
 *           a heap or not. Then it constructs a heap if it 
 *           is not one already.
 * Author: Randy Son
 * ID: 7774
 * Date: 2/25/2020
 */


#include <iostream>
using namespace std;

void printArray(int* heap, int size) {
    for (int i = 1; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

bool isHeap(int* heap, int size) {
    int halfOfHeap = size/2;

    if (size%2 == 1) {
        halfOfHeap = size/2+1;
    }

    for (int i = 1; i < halfOfHeap; i++) {
        if (heap[2*i] > heap[i] || heap[2*i+1] > heap[i]) {
            return false;
        }
    }
    return true;
}

void swap (int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int* constructHeap(int* heap, int size) {
    int halfOfHeap = size/2;

    if (size%2 == 1) {
        halfOfHeap = size/2+1;
    }

    for (int i = 1; i < halfOfHeap; i++) {
        if (heap[2*i] > heap[i]) {
            swap(heap[i], heap[2*i]);
        }
        if (heap[2*i+1] > heap[i]) {
            swap(heap[i], heap[2*i+1]);
        }
    }
    return heap;
}

int* insertValue(int* heap, int* size) {
    /* Increase array size and copy elements over to new array */
    *size = *size+1;
    int* newHeap = new int[*size];

    for (int i = 1; i < *size-1; i++) {
        newHeap[i] = heap[i];
    }

    delete [] heap;

    cout << "Enter a number: ";
    cin >> newHeap[*size-1];

    while (!isHeap(newHeap, *size)) {
        newHeap = constructHeap(newHeap, *size);
    }

    return newHeap;
}

int* deleteMax(int* heap, int* size) {
    *size = *size-1;
    int* newHeap = new int[*size];

    for(int i = 2; i < *size+1; i++) {
        newHeap[i-1] = heap[i];
    }

    delete [] heap;

    while (!isHeap(newHeap, *size)) {
        newHeap = constructHeap(newHeap, *size);
    }

    return newHeap;
}

void heapSort(int* heap, int size) {
   cout << "Heap sort: ";
   while (size > 1) {
       cout << heap[1] << " ";
       heap = deleteMax(heap, &size);
   }
   cout << endl;

}

void heapMenu(int* heap, int size) {
   int choice;

   cout << "Select an operation" << endl;
   cout << "\t1. Insert a number" << endl;
   cout << "\t2. Delete the max" << endl;
   cout << "\t3. Heapsort & Quit" << endl;
   cin >> choice;

   switch (choice){
       case 1:
           heap = insertValue(heap, &size);
           cout << "Updated heap: ";
           printArray(heap, size);
           heapMenu(heap, size);
           break;
       case 2:
           heap = deleteMax(heap, &size);
           cout << "Updated heap: ";
           printArray(heap, size);
           heapMenu(heap, size);
           break;
       case 3:
           heapSort(heap, size);
           cout << "Bye!";
           break;
   }
}


int* determineHeap(int* heap, int size) {
    if (isHeap(heap, size)) {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;

        heap = constructHeap(heap, size);

        while (!isHeap(heap, size)){
            heap = constructHeap(heap, size);
        }
        cout << "Heap constructed: ";
        printArray(heap, size);
    }

    return heap;
}

int main() {

    int size;

    /* Get heap array size */
    cout << "Input size: ";
    cin >> size;
    size++;

    int* heap = new int[size];

    /* Get heap numbers */
    cout << "Enter numbers: ";

    for (int i = 1; i < size; i++) {
        cin >> heap[i];
    }

    /* Initial determination and construction of heap */
    heap = determineHeap(heap, size);

    /* Loop through heap operations */
    heapMenu(heap, size);
    return 0;
}