#include<iostream>
using namespace std;

int knapsack(int n,int w,int wts[],int prices[]){
    ///Base Case
    if(n==0||w==0){
        return 0;
    }
    ///Recursive Case
    if(wts[n-1]>w){
        return knapsack(n-1,w,wts,prices);
    }
    else{
        int incl = prices[n-1] + knapsack(n-1,w-wts[n-1],wts,prices);
        int excl = knapsack(n-1,w,wts,prices);
        return max(incl,excl);
    }
}

int knapsackDP(int N,int W,int wts[],int prices[]){

    int dp[100][100]={0};

    for(int n=0;n<=N;n++){
        for(int w=0;w<=W;w++){
            if(n==0||w==0){
                dp[n][w] = 0;
            }
            else{
                if(wts[n-1]>w){    ///if weight in the array is greater than w where w ranges from 0 to max weight of bag
                    dp[n][w] = dp[n-1][w];
                }
                else{
                    int incl = prices[n-1]+dp[n-1][w-wts[n-1]];
                    int exc = dp[n-1][w];
                    dp[n][w] = max(incl,exc);
                }
            }
        }
    }
      for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<"   ";
        }
        cout<<endl;
      }
     return dp[N][W];
}

int main(){

int prices[] = {25,20,20,60};
int wts[] = {4,3,4,15};
int n=4;
int w = 10;

cout<<knapsack(n,w,wts,prices);
cout<<endl;
cout<<knapsackDP(n,w,wts,prices);
return 0;
}
