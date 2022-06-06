#include<bits/stdc++.h>
using namespace std;

void buildtree(int *stree,int *arr,int f,int l,int p){
    if(f==l){
        stree[p]=f;
        return;
    }
    int mid=(f+l)/2;
    buildtree(stree,arr,f,mid,2*p+1);
    buildtree(stree,arr,mid+1,l,2*p+2);
    int x=stree[2*p+1];
    int y=stree[2*p+2];
    stree[p]=arr[x]<arr[y]?x:y;
    return;

}
int query(int *stree,int *arr,int f,int l,int qf,int ql,int p){
    ///complete overlap
    if(qf<=f && ql>=l){
        return stree[p];
    }
    ///no overlap
    if(f>ql || l<qf)
        return INT_MAX;
    ///partial overlap
    int mid=(f+l)/2;

    int x=query(stree,arr,f,mid,qf,ql,2*p+1);
    int y=query(stree,arr,mid+1,l,qf,ql,2*p+2);
    if(x==INT_MAX)
        return y;
    if(y==INT_MAX)
        return x;
    return arr[x]<arr[y]?x:y;

}

int getmaxAreaRec(int *hist,int *stree,int n,int l,int r){
if(l>r)
    return INT_MIN;
if(l==r)
    return hist[l];
int minindex=query(stree,hist,0,n-1,l,r,0);
int a=getmaxAreaRec(hist,stree,n,l,minindex-1);
int b=getmaxAreaRec(hist,stree,n,minindex+1,r);
int c=(r-l+1)*(hist[minindex]);

return max(a,max(b,c));
}

int main(){

int hist[] =  {6, 1, 5, 4, 5, 2, 6};
int n=(sizeof hist)/(sizeof hist[0]);


int *stree=new int[4*n+1];
buildtree(stree,hist,0,n-1,0);
cout<<getmaxAreaRec(hist,stree,n,0,n-1);
return 0;
}
