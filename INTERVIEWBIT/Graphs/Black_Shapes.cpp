#include<bits/stdc++.h>
using namespace std;


bool isSafe(int i,int j,int m,int n,vector<vector<bool> >&vis,vector<string>&v){
    if(i>=0 && i<m && j>=0 && j<n && !vis[i][j] && v[i][j]=='X')
    return true;
    return false;
}


void dfs(vector<string>&v,vector<vector<bool> >&vis,int i,int j,int m,int n){
    int x[]={-1,1,0,0};
    int y[]={0,0,-1,1};

    vis[i][j]=true;

    for(int k=0;k<4;k++){
        int X=i+x[k];
        int Y=j+y[k];

        if(isSafe(X,Y,m,n,vis,v))
        dfs(v,vis,X,Y,m,n);
    }
}


int black(vector<string> &A) {

    vector<vector<bool > >vis(A.size(),vector<bool>(A[0].size(),false));
    int ans=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            if(A[i][j]=='X' && !vis[i][j]){
                dfs(A,vis,i,j,A.size(),A[0].size());
                ans++;
            }
        }
    }
    return ans;

}

int main(){

vector<string>v={"OOOXOOO", "OOXXOXO", "OXOOOXO"};
cout<<black(v);

return 0;
}
