#include<bits/stdc++.h>
using namespace std;

int maxcoin(vector<int> &A) {

    vector<vector<int> >dp(A.size(),vector<int>(A.size()));

    for(int i=A.size()-1;i>=0;i--){
        for(int j=i;j<A.size();j++){
            if(j==i){
                dp[i][j]=A[i];
            }
            else if(i+1==j){
                dp[i][j]=max(A[i],A[j]);
            }
            else{
                dp[i][j]=max(A[i]+min(dp[i+2][j],dp[i+1][j-1]),A[j]+min(dp[i+1][j-1],dp[i][j-2]));
            }
        }
    }

//    for(int i=0;i<dp.size();i++){
//        for(int j=0;j<dp[i].size();j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[0][A.size()-1];
}

int main(){

vector<int>v={20, 30, 2, 2, 2, 10};
cout<<maxcoin(v);

return 0;
}
