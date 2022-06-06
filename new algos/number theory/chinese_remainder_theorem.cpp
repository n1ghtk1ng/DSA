//Chinese Remainder Theorem | Set 2 (Inverse Modulo based Implementation)
//We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:
//
//
//     x % num[0]    =  rem[0],
//     x % num[1]    =  rem[1],
//     .......................
//     x % num[k-1]  =  rem[k-1]
//Example:
//
//Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
//Output: 11
//Explanation:
//11 is the smallest number such that:
//  (1) When we divide it by 3, we get remainder 2.
//  (2) When we divide it by 4, we get remainder 3.
//  (3) When we divide it by 5, we get remainder 1.
//We strongly recommend to refer below post as a prerequisite for this.
//
//Chinese Remainder Theorem | Set 1 (Introduction)
//
//We have discussed a Naive solution to find minimum x. In this article, an efficient solution to find x is discussed.
//
//The solution is based on below formula.
//
//
//x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
//   Where 0 <= i <= n-1
//
//rem[i] is given array of remainders
//
//prod is product of all given numbers
//prod = num[0] * num[1] * ... * num[k-1]
//
//pp[i] is product of all but num[i]
//pp[i] = prod / num[i]
//
//inv[i] = Modular Multiplicative Inverse of
//         pp[i] with respect to num[i]
//Example:
//
//Let us take below example to understand the solution
//   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
//   prod  = 60
//   pp[]  = {20, 15, 12}
//   inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
//                        // (12*3)%5 = 1
//
//   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
//        rem[2]*pp[2]*inv[2]) % prod
//     = (2*20*2 + 3*15*3 + 1*12*3) % 60
//     = (40 + 135 + 36) % 60
//     = 11
//Refer this for nice visual explanation of above formula.
//
//Below is C++ implementation of above formula. We can use Extended Euclid based method discussed here to find inverse modulo.

// A C++ program to demonstrate working of Chinise remainder
// Theorem
#include<bits/stdc++.h>
using namespace std;

// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
// http://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int inv(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
//    if (g != 1)
//        cout << "Inverse doesn't exist";
    //else
    //{
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
        //cout << "Modular multiplicative inverse is " << res;
    //}
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}

// Driver method
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}
