//Given a sorted set, find if there exist three elements in Arithmetic Progression or not

#include <iostream>
using namespace std;

// The function returns true if there exist three elements in AP
// Assumption: set[0..n-1] is sorted
bool arithmeticThree(int set[], int n)
{
    // One by fix every element as middle element
    for (int j=1; j<n-1; j++)
    {
        // Initialize i and k for the current j
        int i = j-1, k = j+1;

        // Find if there exist i and k that form AP
        // with j as middle element
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] == 2*set[j])
                return true;
            (set[i] + set[k] < 2*set[j])? k++ : i--;
        }
    }

    return false;
}

/* Drier program to test above function*/
int main()
{
    int set1[] = {1, 7, 10, 15, 27, 29};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    arithmeticThree(set1, n1)? cout << "Yes\n" : cout << "No\n";

    int set2[] = {1, 7, 10, 15, 27, 28};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    arithmeticThree(set2, n2)? cout << "Yes\n" : cout << "No\n";
    return 0;
}

