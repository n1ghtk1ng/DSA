#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &arr,int k) {

    int n=arr.size();

    if(n==0)
        return 0;

    vector<vector<int> >dp(k+1,vector<int>(n+1,0));

    for(int i=0;i<n+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<k+1;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=k;i++){
        int maxi=INT_MIN;

        for(int j=1;j<=n;j++){
//            cout<<"i = "<<i<<" j = "<<j<<endl;
            dp[i][j]=dp[i][j-1];
//            int maxi=INT_MIN;
//            for(int k=1;k<j;k++){
//                maxi=max(maxi,dp[i-1][k]+arr[j-1]-arr[k-1]);
//            }
//            dp[i][j]=max(dp[i][j],maxi);
            maxi=max(maxi,dp[i-1][j-1]-arr[j-1]);
            dp[i][j]=max(dp[i][j],maxi+arr[j-1]);

//            cout<<"maxi = "<<maxi<<endl;
        }
    }
    return dp[k][n];
}



int main(){

vector<int>v={100, 30, 15, 10, 8, 25, 80};
int k=3;
cout<<maxProfit(v,k);

return 0;
}


