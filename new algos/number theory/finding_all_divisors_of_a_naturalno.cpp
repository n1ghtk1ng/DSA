// A O(sqrt(n)) program that prints all divisors
// in sorted order
#include <bits/stdc++.h>
using namespace std;

// function to print the divisors
void printDivisors(int n)
{
    // Vector to store half of the divisors
    vector<int> v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i) // check if divisors are equal
                printf("%d ", i);
            else
            {
                printf("%d ", i);

                // push the second divisor in the vector
                v.push_back(n/i);
            }
        }
    }

    // The vector will be printed in reverse
    for (int i=v.size()-1; i>=0; i--)
        printf("%d ", v[i]);
}

/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    printDivisors(100);
    return 0;
}
Run on IDE
Output :

The divisors of 100 are:
1 2 4 5 10 20 25 50 100
Time Complexity : O(sqrt(n))
Auxiliary Space : O(sqrt(n))
