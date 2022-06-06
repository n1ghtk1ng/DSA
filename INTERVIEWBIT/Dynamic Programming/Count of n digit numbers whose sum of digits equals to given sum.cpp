#include<bits/stdc++.h>
using namespace std;

unsigned long long int lookup[101][501];

unsigned long long int countRec(int n, int sum)
{
    if (n == 0)
       return sum == 0;

    if (lookup[n][sum] != -1)
       return lookup[n][sum];

    if (sum == 0)
       return 1;

    unsigned long long int ans = 0;

    for (int i=0; i<=9; i++)
       if (sum-i >= 0)
          ans += countRec(n-1, sum-i);

    return lookup[n][sum] = ans;
}
unsigned long long int finalCount(int n, int sum)
{
    unsigned long long int ans = 0;

    memset(lookup, -1, sizeof lookup);

    for (int i = 1; i <= 9; i++)
      if (sum-i >= 0)
         ans += countRec(n-1, sum-i);

    return ans;
}

int main()
{
    int n = 3, sum = 6;
    cout <<finalCount(n, sum);
    return 0;
}
