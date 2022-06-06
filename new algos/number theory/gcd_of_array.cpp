The GCD of three or more numbers equals the product of the prime factors common to all the numbers, but it can also be calculated by repeatedly taking the GCDs of pairs of numbers.

gcd(a, b, c) = gcd(a, gcd(b, c))
             = gcd(gcd(a, b), c)
             = gcd(gcd(a, c), b)
For an array of elements, we do following.

result = arr[0]
For i = 1 to n-1
   result = GCD(result, arr[i])
Below is C++ implementation of above idea.

// C++ program to find GCD of two or
// more numbers
#include<bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i=1; i<n; i++)
        result = gcd(arr[i], result);

    return result;
}

// Driven code
int main()
{
    int arr[] = {2, 4, 6, 8, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findGCD(arr, n) << endl;
    return 0;
}
Run on IDE
Output:

2
