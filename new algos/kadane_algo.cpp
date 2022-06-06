#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int maxsum = INT_MIN, current_sum = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        current_sum += a[i];

        if (maxsum < current_sum)
        {
            maxsum = current_sum;
            start = s;
            end = i;
        }

        if (current_sum < 0)
        {
            current_sum = 0;
            s = i+1;
        }
    }
    cout << "Maximum contiguous sum is "
        << maxsum << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    return 0;
}
