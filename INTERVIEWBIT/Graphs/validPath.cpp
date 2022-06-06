#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int m,int n){
    if(i>=0 && i<=m && j>=0 && j<=n){
        return true;
    }
    return false;
}

bool isSafe2(int i,int j,int m,int n,vector<vector<bool> >&vis,vector<vector<bool> >&v){
    if(i>=0 && i<=m && j>=0 && j<=n && !vis[i][j] && v[i][j]==true){
        return true;
    }
    return false;
}

bool fun(vector<vector<bool> >&v,int i,int j,int m,int n,vector<vector<bool> >&vis){
//cout<<"i = "<<i<<" j = "<<j<<endl;
if(i==m && j==n){
    if(v[i][j]==true)
    return true;
    return false;
}
int x[]={-1,0,1,-1,1,-1,0,1};
int y[]={-1,-1,-1,0,0,1,1,1};

for(int k=0;k<8;k++){
    if(isSafe2(i+x[k],j+y[k],m,n,vis,v)){
        vis[i+x[k]][j+y[k]]=true;
        bool t=fun(v,i+x[k],j+y[k],m,n,vis);
            if(t==true)
                return true;
    }
}
return false;

}

void fun2(int x,int y,int r,vector<vector<bool> >&v,int m,int n){
if(r==0)
    return;

v[x][y]=false;
if(isSafe(x,y-1,m,n)){
    v[x][y-1]=false;
    fun2(x,y-1,r-1,v,m,n);
}
if(isSafe(x,y+1,m,n)){
    v[x][y+1]=false;
    fun2(x,y+1,r-1,v,m,n);
}
if(isSafe(x+1,y,m,n)){
    v[x+1][y]=false;
    fun2(x+1,y,r-1,v,m,n);
}
if(isSafe(x-1,y,m,n)){
    v[x-1][y]=false;
    fun2(x-1,y,r-1,v,m,n);
}

}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

vector<vector<bool> >v(A+1,vector<bool>(B+1,true));
vector<vector<bool> >vis(A+1,vector<bool>(B+1,false));

//for(int i=0;i<C;i++){
//    int x=E[i] ;
//    int y=F[i];
//    fun2(x,y,D,v,A,B);
//}

for(int i=0;i<=A;i++){
    for(int j=0;j<=B;j++){
        for(int k=0;k<C;k++){
            if( sqrt( pow((E[k]-i),2) +  pow((F[k]-j),2) ) <= D )
                v[i][j]=false;
        }
    }
}

/*
for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}*/
if(v[0][0]==false){
    return "NO";
}

bool ans=fun(v,0,0,A,B,vis);

if(ans){
    return "YES";
}
return "NO";
//return "hi";
}


int main(){
    int x,y,N,R;
    vector<int>A={6 ,25 ,33 ,28 ,16 ,15 ,11};
    vector<int>B={6 ,19 ,7 ,3 ,24 ,17 ,2};
    x = 35;
    y = 26;
    N = 6;
    R = 8;

    cout<<solve(x,y,N,R,A,B);

return 0;
}
