#include<bits/stdc++.h>
using namespace std;


void buildtree(int *stree,int f,int l,int p){
if(f>l)
    return;

if(f==l){
    stree[p]=1;
    return;
}
int mid=(f+l)/2;

buildtree(stree,f,mid,2*p+1);
buildtree(stree,mid+1,l,2*p+2);

stree[p]=stree[2*p+1]+stree[2*p+2];
return;

}

int query(int*stree,int f,int l,int p,int spaces){

if(f>l)
    return -1;

if(f==l)
    return f;

    int mid=( f+l)/2;

    int leftspaces=stree[2*p+1];
    int rightspaces=stree[2*p+2];

    if(spaces<=leftspaces)
        return query(stree,f,mid,2*p+1,spaces);
    else{
        return query(stree,mid+1,l,2*p+2,spaces-leftspaces);
    }

}

void update(int *stree,int f,int l,int p,int idx){

if(f>l)
    return;
if(f==l){
    stree[p]=0;
    return;
}

    int mid=(f+l)/2;

    if(idx<=mid){
        update(stree,f,mid,2*p+1,idx);
    }
    else{
        update(stree,mid+1,l,2*p+2,idx);
    }
    stree[p]=stree[2*p+1]+stree[2*p+2];
    return;

}


vector<int>order(vector<int> &A, vector<int> &B) {

vector<int>ans(A.size());
int *stree=new int[4*A.size()+4];

buildtree(stree,0,A.size()-1,0);


vector<pair<int,int> >v;

for(int i=0;i<A.size();i++){
    v.push_back(make_pair(A[i],B[i]));
}
sort(v.begin(),v.end());

for(int i=0;i<A.size();i++){
    int index=query(stree,0,A.size()-1,0,v[i].second+1);
//    cout<<"index = "<<index<<endl;
    ans[index]=v[i].first;

    update(stree,0,A.size()-1,0,index);
}


return ans;
}


int main(){

vector<int>a={5, 3, 2, 6, 1, 4};
vector<int>b={0, 1, 2, 0, 3, 2};
vector<int>ans=order(a,b);

for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}


return 0;
}
