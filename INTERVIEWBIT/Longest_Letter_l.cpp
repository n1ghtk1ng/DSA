#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int m,int n,vector<vector<char> >&v,vector<vector<bool> >&vis){

if(i>=0 && i<m && j>=0 && j<n && !vis[i][j] && v[i][j]=='.'){
    return true;
}
return false;
}

void setvisited(int i,int j,int m,int n,vector<vector<char> >&v,vector<vector<bool> >&vis){

//cout<<"i = "<<i<<" j = "<<j<<endl;
vis[i][j]=true;

if(isSafe(i+1,j,m,n,v,vis)){
    setvisited(i+1,j,m,n,v,vis);
}
if(isSafe(i,j+1,m,n,v,vis)){
    setvisited(i,j+1,m,n,v,vis);
}
if(isSafe(i,j-1,m,n,v,vis)){
    setvisited(i,j-1,m,n,v,vis);
}
if(isSafe(i-1,j,m,n,v,vis)){
    setvisited(i-1,j,m,n,v,vis);
}

}

int fun(int i,int j,int m,int n,vector<vector<char> >&v,vector<vector<bool> >&vis,int ans,char dir){
//    cout<<"i = "<<i<<"j = "<<j<<endl;
    vis[i][j]=true;
    bool x1=false;
    bool x3=false;
    if(isSafe(i+1,j,m,n,v,vis)){
        x1=true;
    }
    if(isSafe(i-1,j,m,n,v,vis)){
        x3=true;
    }

    bool x2=false;
    bool x4=false;
    if(isSafe(i,j+1,m,n,v,vis)){
        x2=true;
    }
    if(isSafe(i,j-1,m,n,v,vis)){
        x4=true;
    }

    if(x1&& x2 || x3 && x2 || x1 && x4 || x3 && x4){
        setvisited(i,j,m,n,v,vis);
        return 0;
    }
    if(x1){
        if(dir=='R' || x3){
            setvisited(i,j,m,n,v,vis);
            return 0;
        }
        return fun(i+1,j,m,n,v,vis,ans+1,dir);
    }
    else if(x2){
        if(ans==1 || x4){
            setvisited(i,j,m,n,v,vis);
            return 0;
        }
        return fun(i,j+1,m,n,v,vis,ans+1,'R');
    }
    else if(dir=='D' && x4 ){
        setvisited(i,j,m,n,v,vis);
        return 0;
    }
    else if(dir=='R' && x3){
        setvisited(i,j,m,n,v,vis);
        return 0;
    }
    else{
        if(dir=='R')
            return ans;
        else{
            return 0;
        }
    }
}

int main(){

int m,n;
//m=3;
//n=4;
cin>>m>>n;

vector<vector<char> >v(m,vector<char>(n));
//v={{'.','*','*','.','*'},{'.','.','*','.','*'},{'.','*','*','.','.'},{'.','.','*','*','*'},{'*','*','*','*','*'},{'.','*','.','.','.'},{'.','*','.','*','*'},{'.','.','*','.','.'}};
//v={{'.','*','*','*'},{'.','.','.','*'},{'*','*','.','*'}};
//for(int i=0;i<m;i++){
//    for(int j=0;j<n;j++){
//        cout<<v[i][j]<<" ";
//    }
//    cout<<endl;
//}

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>v[i][j];
    }
}


vector<vector<bool> >vis(m,vector<bool>(n,false));
int ans=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(v[i][j]=='.' &&!vis[i][j]){
            ans=max(ans,fun(i,j,m,n,v,vis,1,'D'));
//            cout<<"ans = "<<ans<<endl;
        }
    }
}

if(ans!=0){
    cout<<"YES"<<endl;
    cout<<ans<<endl;
}
else{
    cout<<"NO"<<endl;
}
return 0;
}
