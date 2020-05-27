/*
 * Title: sieve.cpp
 * Abstract: This program utilizes the sieve of Eratothenes to generate a list of prime numbers
 *           up to a number n.
 * Author: Randy Son
 * ID: 7774
 * Date: 1/13/2020
 */

#include <iostream>
#include <math.h>

using namespace std;
// int* sieve(int n) {
//     int* primes;

//     /* Dynamically allocate arrays based on n and initialize arrays to 1.
//        Assume everything is prime until we mark it as a composite */
//     primes = new int [n+1];
//     fill_n(primes, n+1, 1);

//     /* Loop numbers 2 to sqrt(n). Start at 2 because 0 & 1 are edge cases
//        End at sqrt(n) because we are marking composites as we go */
//     for (int i = 2; i <= sqrt(n) ; i++) {
//         /* Check if value is marked*/
//         if (primes[i] == 1) {

//             /* Mark any multiples as composites */
//             for (int j = i*i; j <= n; j += i) {
//                 if (j % i == 0)
//                     primes[j] = 0;
//             }
//         }
//     }
//     return primes;
// }

int* sieve(int n) {
    int* numbersList;
    int* primes;

    /* Dynamically allocate arrays based on n and initialize arrays to 1.
       Assume everything is prime until we mark it as a composite */
    numbersList = new int[n+1];
    primes = new int[n];

    for (int i = 2; i <= n; i++) {
        numbersList[i] = i; 
        primes[i] = 0;
    }
    
    /* Loop numbers 2 to sqrt(n). Start at 2 because 0 & 1 are edge cases
       End at sqrt(n) because we are marking composites as we go */
    for (int i = 2; i <= sqrt(n) ; i++) {

        /* Check if value is marked*/
        if (numbersList[i] != 0) {

            /* Mark any multiples as composites */
            int j = i * i;

            while (j <= n) {
                numbersList[j] = 0;
                j += i;
            }
        }
    }

    /* Copy prime numbers from numbers list into a separate clean array */
    int p = 0;
    for (int i = 2; i <= n; i++) {

        if (numbersList[i] != 0) {
            primes[p] = numbersList[i];
            p++;
        }
    }
    return primes;
}

/* 
    Print primes in a comma separated list
    Print first prime without a comma in front
    and other with a comma infront
*/
void printPrimes(int* arr, int n) {
    cout << "List of primes: " << endl;
    cout << arr[0];
    
    for (int i = 1; i <= n; i++) {
        /* Exit loop if we finish off the primes */
        if (arr[i] == 0)
            break;
        cout << "," << arr[i];
    }
}

int main() {
    int n;
    int* primes;

    /* Inputs */
    cout << "Sieve of Eratosthenes - generates list of prime numbers up to a number n" << endl;
    cout << "Input number: ";
    cin >> n;

    /* Main function */
    primes = sieve(n);

    /* Output */
    printPrimes(primes, n);

    return 0;
}
