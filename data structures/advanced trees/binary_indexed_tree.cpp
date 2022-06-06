#include<bits/stdc++.h>
using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);

    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";

    return BITree;
}


// Driver program to test above functions
int main()
{
    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(freq)/sizeof(freq[0]);
    int *BITree = constructBITree(freq, n);
    cout << "Sum of elements in arr[0..5] is "
         << getSum(BITree, 5);

    // Let use test the update operation
    freq[3] += 6;
    updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

    cout << "\nSum of elements in arr[0..5] after update is "
         << getSum(BITree, 5);

    return 0;
}
///introduction
// helps in finding the prefix sum of array e.g. sum from index 0 to 6, 0 to 4 etc;
//time to create Fenwick tree is o(n log n )
//space complexity --> o(n)
//query ---> o(log n)
//update---> o(log n)

///get parent-->
//  1. 2`s complement
//  2. AND it with original number
//  3. Subtract from original number
///get next-->
//  1. 2`s complement
//  2. AND it with original number
//  3. ADD to original number
///structure of tree-->
//1,2,4,8... are the child nodes of 0 as --> if we flip the rightmost 1 bit we get zero hence 0 is parent of 1,2,4,8,...
//similarly 2 is parent of 3 and so on;
//on node 0 nothing is stored
//for n elements of the array we have n+1 elements of Fenwick tree
///filling the tree->
//initially store 0 on all indexes of Fenwick tree array
//start from node 1 which stores the 0th index element; then get next node using above formula and add it to them as well .
//then move to index 1 of the array and add it to node 2 and add the same to the next nodes as well
//repeat the above procedure
///for updating the tree repeat the same procedure as filling the tree
///for query -->
//for sum from index 0 to index x,go to index x+1(in Fenwick array)add it to ans and find parent of x+1 and add it to ans,... carry  on until u find the root node i.e. index 0 of Fenwick array

/*            n  --> No. of elements present in input array.
    BITree[0..n] --> Array that represents Binary Indexed Tree.
    arr[0..n-1]  --> Input array for whic prefix sum is evaluated. */

// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[].
