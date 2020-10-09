/*
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find total number of Derangements of a set of n elements.
Examples : 

Input: n = 2
Output: 1
For two elements say {0, 1}, there is only one 
possible derangement {1, 0}

Input: n = 3
Output: 2
For three elements say {0, 1, 2}, there are two 
possible derangements {2, 0, 1} and {1, 2, 0}

Input: n = 4
Output: 9
For four elements say {0, 1, 2, 3}, there are 9
possible derangements {1, 0, 3, 2} {1, 2, 3, 0}
{1, 3, 0, 2}, {2, 3, 0, 1}, {2, 0, 3, 1}, {2, 3,
1, 0}, {3, 0, 1, 2}, {3, 2, 0, 1} and {3, 2, 1, 0}


*/


// A Naive Recursive C++ program 
// to count derangements


//TC = O(2^n)

#include <bits/stdc++.h>
using namespace std;
 
int countDer(int n)
{
  // Base cases
  if (n == 1) return 0;
  if (n == 2) return 1;
 
  // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
  return (n - 1) * (countDer(n - 1) + countDer(n - 2));
}

-----------------------------------------------------------------------------
//Dp approach

//TC = O(n)
//SC = O(n)

int countDer(int n)
{
    // Create an array to store 
    // counts for subproblems
    int der[n + 1] = {0};
 
    // Base cases
    der[1] = 0;
    der[2] = 1;
 
    // Fill der[0..n] in bottom up manner 
    // using above recursive formula
    for (int i = 3; i <= n; ++i)
        der[i] = (i - 1) * (der[i - 1] + 
                            der[i - 2]);
 
    // Return result for n
    return der[n];
}
