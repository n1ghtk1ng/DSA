#include<bits/stdc++.h>
using namespace std;

int Solution::maxProfit(const vector<int> &arr) {

    int n=arr.size();

    if(n==0)
        return 0;
//    int ans=0;

    vector<int>dp(n+1,0);
    int maxi=arr[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i]=max(dp[i+1],maxi-arr[i]);
        maxi=max(maxi,arr[i]);
    }
    int mini=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1],dp[i]+arr[i]-mini);
        mini=min(mini,arr[i]);
    }

    return dp[n-1];

}



int main(){

vector<int>v={4,3,5,6,2,4,8};

cout<<maxProfit(v);

return 0;
}

