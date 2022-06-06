#include<bits/stdc++.h>
using namespace std;

int isMatch(const string A, const string B) {

vector<vector<bool> >dp(1+A.size(),vector<bool>(1+B.size(),false));

for(int i=0;i<=A.size();i++){
    dp[i][0]=false;
}
dp[0][0]=true;
for(int i=1;i<=B.size();i++){
    if(B[i-1]=='*'){
        dp[0][i]=dp[0][i-2];
    }
    else
        dp[0][i]=false;
}


for(int i=1;i<=A.size();i++){
    for(int j=1;j<=B.size();j++){
        if(A[i-1]==B[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }
        else if(B[j-1]=='*'){
            dp[i][j]=dp[i][j-2];

            if(A[i-1]==B[j-2]||B[j-2]=='.'){
                dp[i][j]=dp[i][j]|dp[i-1][j];
            }
        }
        else if(B[j-1]=='.'){
            dp[i][j]=dp[i-1][j-1];
        }
        else if(B[j-1]!=A[i-1]){
            dp[i][j]=false;
        }
    }
}
/*
for(int i=0;i<=A.size();i++){
    for(int j=0;j<=B.size();j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<endl;
}
*/
return dp[A.size()][B.size()]==true?1:0;
}


int main(){
string a="ab";
string b=".*";

cout<<isMatch(a,b);
return 0;
}

