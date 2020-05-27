#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void printVector(vector<int> v) {
    for (auto x: v) {
        cout << x << endl;
    }
}

int main()
{
    vector<int> A;
    vector<int> S;
    vector<int> Count;
    Count.push_back(0);
    Count.push_back(0);
    Count.push_back(1);
    Count.push_back(0);
    Count.push_back(0);
    Count.push_back(0);
    A.push_back(60);
    A.push_back(10);
    A.push_back(60);
    A.push_back(10);
    A.push_back(20);
    A.push_back(50);
    S.push_back(0);
    S.push_back(0);
    S.push_back(1);
    S.push_back(0);
    S.push_back(0);
    S.push_back(0);

    int n = 6;
    cout << "N: " << n << endl;

    // Initialize count to 0
    for (int i = 0; i <= n-1; i++)
        Count[i] = 0;
    
    cout << "Initial Count vector: " << endl;
    printVector(Count);

    for (int i = 0; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++) {
            if (A[i] < A[j]) {
                Count[j] += 1;
            }
                
            else {
                Count[i] += 1;
            }
        }
    }

    for (int i = 0; i <= n-1; i++) {
        S[Count[i]] = A[i];
    }

    cout << "Printing vector Count: " << endl;
    printVector(Count);

    cout << "Printing vector S: " << endl;
    printVector(S);
}


