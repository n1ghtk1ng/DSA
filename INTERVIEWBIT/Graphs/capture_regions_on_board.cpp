#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int m,int n,vector<vector<bool> >&vis,vector<vector<char> > &A){

if(i>=0 && i<m && j>=0 && j<n && !vis[i][j] && A[i][j]=='O')
    return true;
return false;

}

void dfs(int i,int j,int m,int n,vector<vector<bool> >&vis,vector<vector<char> > &A){

vis[i][j]=true;
A[i][j]='o';

int x[]={-1,1,0,0};
int y[]={0,0,-1,1};

for(int k=0;k<4;k++){
    if(isSafe(i+x[k],j+y[k],m,n,vis,A)){
        dfs(i+x[k],j+y[k],m,n,vis,A);
    }
}
}
void solve(vector<vector<char> > &A) {

int m=A.size();
int n=A[0].size();

vector<vector<bool> >vis(m,vector<bool>(n,false));

for(int i=0;i<A[0].size();i++){
    if(A[0][i]=='O' && !vis[0][i]){
        dfs(0,i,m,n,vis,A);
    }
}
for(int i=0;i<A[m-1].size();i++){
    if(A[m-1][i]=='O' && !vis[m-1][i]){
        dfs(m-1,i,m,n,vis,A);
    }
}
for(int i=0;i<m;i++){
    if(A[i][0]=='O' && !vis[i][0]){
        dfs(i,0,m,n,vis,A);
    }
}
for(int i=0;i<m;i++){
    if(A[i][n-1]=='O' && !vis[i][n-1]){
        dfs(i,n-1,m,n,vis,A);
    }
}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(A[i][j]=='o'){
            A[i][j]='O';
        }
        else{
            A[i][j]='X';
        }
    }
}

}


int main(){

vector<vector<char> >A={
{'X', 'O', 'X', 'X' },
{'X', 'X', 'O', 'X' },
{'X', 'X', 'O', 'X' },
{'X', 'O' ,'X', 'X' }
};

solve(A);

for(int i=0;i<A.size();i++){
    for(int j=0;j<A[i].size();j++){
        cout<<A[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
