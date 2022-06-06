// C++ program to find Length of the Longest AP (llap) in a given sorted seti.
// The code strictly implements the algorithm provided in the reference.
#include <iostream>
using namespace std;

// Returns length of the longest AP subseti in a given seti
int lenghtOfLongestAP(int seti[], int n)
{
    if (n <= 2)  return n;

    // Create a table and initialize all values as 2. The value of
    // L[i][j] stores LLAP with seti[i] and seti[j] as first two
    // elements of AP. Only valid entries are the entries where j>i
    int L[n][n]={0};
    int llap = 2;  // Initialize the result

    // Fill entries in last column as 2. There will always be
    // two elements in AP with last number of seti as second
    // element in AP
    for (int i = 0; i <= n-1; i++){
        for(int j=i+1;j<=n-1;j++){
            L[i][j]=2;
        }
    }
//        L[i][n-1] = 2;

    // Consider every element as second element of AP
    for (int j=n-2; j>=1; j--)
    {
        // Search for i and k for j
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
//            cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<endl;
           if (seti[i] + seti[k] < 2*seti[j])
               k++;

           // Before changing i, seti L[i][j] as 2
           else if (seti[i] + seti[k] > 2*seti[j])
           {   i--;   }

           else
           {
               // Found i and k for j, LLAP with i and j as first two
               // elements is equal to LLAP with j and k as first two
               // elements plus 1. L[j][k] must have been filled
               // before as we run the loop from right side
               L[i][j] = L[j][k] + 1;

               // Update overall LLAP, if needed
               llap = max(llap, L[i][j]);

               // Change i and k to fill more L[i][j] values for
               // current j
               if(k+1==n)
                i--;
               else if(i-1<0)
                k++;
                else{
                    i--;
                    k++;
                }
           }
        }

        // If the loop was stopped due to k becoming more than
        // n-1, seti the remaining entties in column j as 2

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }

    return llap;
}

/* Drier program to test above function*/
int main()
{
//    int seti1[] = {2,4,6,6,8,10,12};
//    int n1 = sizeof(seti1)/sizeof(seti1[0]);
//    cout <<   lenghtOfLongestAP(seti1, n1) << endl;
//
//    int seti2[] = {1, 7, 10, 15, 27, 29};
//    int n2 = sizeof(seti2)/sizeof(seti2[0]);
//    cout <<   lenghtOfLongestAP(seti2, n2) << endl;

    int seti3[] = {2,2,2,2,2};
    int n3 = sizeof(seti3)/sizeof(seti3[0]);
    cout <<   lenghtOfLongestAP(seti3, n3) << endl;

    return 0;
}
