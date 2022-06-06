#include<iostream>
using namespace std;
///Recursion with Memoisation / TOP-DOWN DP
int fib(int n,int dp[]){
    ///Base Case
    if(n==0||n==1){
        return n;
    }
    ///Rec Case
    if(dp[n]==-1){
        dp[n] = fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
    }
    else{
        return dp[n];
    }
}
///Bottom UP DP/ Iterative Approach
int fib(int n){
    int dp[100];
    dp[0]=0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}



int main(){

    int dp[100];
    for(int i=0;i<100;i++){
        dp[i]=-1;
    }
    cout<<fib(5,dp);

return 0;
}
