#include<iostream>
using namespace std;

int knightMoves(int i,int j){

    if(i==0&&j==0){
        return 1;
    }
    int cell1 = 0,cell2=0;
    if(i-2>=0 && j-1>=0){
        cell1 = knightMoves(i-2,j-1);
    }
    if(j-2>=0 && i-1>=0){
        cell2 = knightMoves(i-1,j-2);
    }
    return cell1+cell2;

}
int knightMovesDP(int m,int n){
    int dp[100][100] ={0};

    dp[0][0]=1;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            int ans=0;
            if(i!=0 && j!=0){
            if((i-2)>=0 && (j-1)>=0){
                ans += dp[i-2][j-1];
            }
            if((j-2)>=0&& (i-1)>=0){
                ans += dp[i-1][j-2];
            }
            dp[i][j]=ans;
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[m][n];

}


int main(){

cout<< knightMoves(3,3)<<endl;
cout<< knightMovesDP(3,3);

return 0;
}
