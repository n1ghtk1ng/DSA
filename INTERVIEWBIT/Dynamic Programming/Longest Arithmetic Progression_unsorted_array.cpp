#include <iostream>
using namespace std;

int lenghtOfLongestAP(int seti[], int n)
{
    if (n <= 2)  return n;

    int L[n][n];
    int llap = 2;

    for (int i = 0; i <= n-1; i++){
        for(int j=i+1;j<=n-1;j++){
            L[i][j]=2;
        }
    }
    int ans=INT_MIN;

    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            int req=2*seti[j]-seti[i];

            for(int k=j+1;k<n;k++){
                if(seti[k]==req){
                    L[i][j]=max(L[i][j],1+L[j][k]);
                    ans=max(ans,L[i][j]);
                }
            }
        }
    }


    return ans;
}

int main()
{
    int seti1[] = {1,2,3,4,5};
    int n1 = sizeof(seti1)/sizeof(seti1[0]);
    cout <<   lenghtOfLongestAP(seti1, n1) << endl;

    int seti2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(seti2)/sizeof(seti2[0]);
    cout <<   lenghtOfLongestAP(seti2, n2) << endl;

    int seti3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(seti3)/sizeof(seti3[0]);
    cout <<   lenghtOfLongestAP(seti3, n3) << endl;

    return 0;
}

