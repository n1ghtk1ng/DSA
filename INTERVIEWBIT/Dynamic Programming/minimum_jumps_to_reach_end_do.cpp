#include<bits/stdc++.h>
using namespace std;

int main(){

int arr[]={0, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
int n = sizeof(arr)/sizeof(int);

vector<int>dp(n,INT_MAX);

if(n<=1){
    cout<<0<<endl;
    return 0;
}
dp[0]=(arr[0]==0)?INT_MAX:0;
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(dp[j]!=INT_MAX && j+arr[j]>=i){
            dp[i]=min(dp[i],1+dp[j]);
        }
    }
}
if(dp[n-1]==INT_MAX)
cout<<-1<<endl;
else
cout<<dp[n-1]<<endl;

return 0;
}
