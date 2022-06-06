#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int fun(int n,int s,vector<vector<int> >&dp){

if(n==0){
    if(s==0)
        return 1;
    return 0;
}
if(dp[n][s]!=-1){
    return dp[n][s];
}
if(s==0){
    return 1;
}
int ans=0;
for(int i=0;i<=9;i++){
    if(s-i>=0){
        ans=(ans+fun(n-1,s-i,dp))%mod;
    }
}
dp[n][s]=ans;
return ans;
}

int Solution::solve(int A, int B) {

if(A==1 && B==0)
    return 0;

vector<vector<int> >dp(A+1,vector<int>(B+1,-1));
int ans=0;
for(int i=1;i<=9;i++){
    if(B-i>=0){
        ans=(ans+fun(A-1,B-i,dp))%mod;
    }
}
/*
for(int i=0;i<=A;i++){
    for(int j=0;j<=B;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}
*/
return ans;

}


int main(){

cout<<solve(3,6);

return 0;
}
