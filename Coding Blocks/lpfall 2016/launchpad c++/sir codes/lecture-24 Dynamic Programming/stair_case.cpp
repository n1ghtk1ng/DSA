#include<iostream>
using namespace std;

int countSteps(int n){
    int dp[100];
    dp[0]=dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[n];
}

int steps(int n,int k){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        ans += steps(n-i,k);
    }
    return ans;

}

int stepsDP(int n,int k){
    int dp[100]={0};

    dp[0]=1;


    for(int i=1;i<=n;i++){
            int ans=0;

            for(int jump=1;jump<=k;jump++){
                if(i-jump>=0){
                    ans += dp[i-jump];
                }
            }
            dp[i] = ans;
    }
    return dp[n];
}


int main(){

    cout<<countSteps(5)<<endl;
    cout<<steps(5,5)<<endl;
    cout<<stepsDP(6,5)<<endl;
}
