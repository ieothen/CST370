/*
 * Title: palindrome.cpp
 * Abstract: This program determines if an input string is a palindrome or not.
 *           A palindrome is a word that is the same forwards and backwards.
 * Author: Randy Son
 * ID: 7774
 * Date: 1/14/2020
 */

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {

   /* Start j off at the end of the string */
   int j = s.length() - 1;

    /* Start i from beginning of string, loop til half way of string */
    for (int i = 0; i < s.length() / 2; i++) {

        /* Check if indexes on opposite side match, exit early if no match */
        if (s[i] == s[j])
            /* Move index j left, while index i will move right */
            j--;
        else
            return false;
    }

    /* Passed palindrome test */
    return true;
}

int main() {
    string s;
    bool result;
    int numLoops = 3;

    /* Main loop */
    for (int i = 1; i <= numLoops; i++) {
        cout << "Input string " << i << ": ";
        cin >> s;
        result = isPalindrome(s);

        if (result)
            cout << "Yes, it's a palindrome" << endl;
        else
            cout << "No, it's not a palindrome" << endl;
    }
    return 0;
}
