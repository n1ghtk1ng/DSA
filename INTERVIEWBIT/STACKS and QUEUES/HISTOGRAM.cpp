#include<bits/stdc++.h>
using namespace std;
 int n;

void buildtree(int *stree,int f,int l,int p,vector<int>&v){
if(f>l)
    return;
if(f==l){
    stree[p]=f;
    return;
}

int mid=(f+l)/2;

buildtree(stree,f,mid,2*p+1,v);
buildtree(stree,mid+1,l,2*p+2,v);

if(v[stree[2*p+1]]<v[stree[2*p+2]]){
    stree[p]=stree[2*p+1];
}
else{
    stree[p]=stree[2*p+2];
}

return;

}

int query(int *stree,int f,int l,int qf,int ql,int p){

///complete overlap
if(qf<=f && ql>=l){
    return stree[p];
}
///no overlap

if(ql<f || qf>l){
    return INT_MAX;
}

///partial overlap

int mid=(f+l)/2;

int x=query(stree,f,mid,qf,ql,2*p+1);
int y=query(stree,mid+1,l,qf,ql,2*p+2);
return min(x,y);
}

int findarea(int*stree,vector<int>&v,int f,int l){
    if(f>l)
        return INT_MIN;
    int idx=query(stree,0,n-1,f,l,0);
    return max( (l-f+1)*v[idx] , max(findarea(stree,v,f,idx-1),findarea(stree,v,idx+1,l))  );
}

int fun(vector<int>&v){
n=v.size();

int *stree=new int[4*n+1];

buildtree(stree,0,n-1,0,v);
return findarea(stree,v,0,n-1);

//return 0;
}



int main(){

vector<int>v={1,2,3,6,5};

cout<<fun(v);




return 0;
}
