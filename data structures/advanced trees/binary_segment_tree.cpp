#include<bits/stdc++.h>
using namespace std;

/// if length of given array is power of 2 e.g.--> 4 ,then length of segment tree array will be 2*4 -1 =7 ;
/// if length of given array is not a power of 2 e.g.---> 5 then find next power of 2 i.e. 8 and multiply by 2 and subtract 1 i.e. 2*8-1=15;

int lazy[1000]={0};
void buildtreehelper(int arr[],int sarr[],int l,int h,int p){
    if(l==h){
        sarr[p]=arr[l];
        return ;
    }
    int mid=(l+h)/2;
    buildtreehelper(arr,sarr,l,mid,2*p+1);
    buildtreehelper(arr,sarr,mid+1,h,2*p+2);
    sarr[p]=min(sarr[2*p+1],sarr[2*p+2]);

}
int *buildtree(int n,int arr[]){
    int *sarr=new int[4*n+1];
    buildtreehelper(arr,sarr,0,n-1,0);
    return sarr;
}
int query(int *stree,int f,int l,int qf,int ql,int p){
///complete overlap
if(f>=qf && l<=ql)
    return stree[p];
///no overlap
if(f>ql || l<qf)
    return INT_MAX;

///partial overlap
int mid=(f+l)/2;
int x=query(stree,f,mid,qf,ql,2*p+1);
int y=query(stree,mid+1,l,qf,ql,2*p+2);
return min(x,y);
}
void updaterange(int *stree,int f,int l,int inc,int qf,int ql,int p){
    ///no overlap
    if(f>ql || l<qf)
        return;
    ///leaf node
    if(f==l){
        stree[p]+=inc;
        return;
    }
    int mid=(f+l)/2;
    updaterange(stree,f,mid,inc,qf,ql,2*p+1);
    updaterange(stree,mid+1,l,inc,qf,ql,2*p+2);
    stree[p]=min(stree[2*p+1],stree[2*p+2]);
}
void updaterangelazy(int *stree,int f,int l,int qf,int ql,int inc,int p){
    ///update lazy values
    if(lazy[p]!=0){
        stree[p]+=lazy[p];
        if(f!=l){
            lazy[2*p+1]+=lazy[p];
            lazy[2*p+2]+=lazy[p];
        }
        lazy[p]=0;
    }
    ///no overlap
    if(f>ql || l<qf){
        return;
    }
    ///complete overlap
    if(f>=qf && l<=ql){
        stree[p]+=inc;
            if(f!=l){
                lazy[2*p+1]+=inc;
                lazy[2*p+2]+=inc;
            }
            return;
    }

    ///partial overlap

    int mid=(f+l)/2;
    updaterangelazy(stree,f,mid,qf,ql,inc,2*p+1);
    updaterangelazy(stree,mid+1,l,qf,ql,inc,2*p+2);

    stree[p]=min(stree[2*p+1],stree[2*p+2]);

}
int querylazy(int *stree,int f,int l,int qf,int ql,int p){
    if(lazy[p]!=0){
        stree[p]+=lazy[p];
        if(f!=l){
            lazy[2*p+1]+=lazy[p];
            lazy[2*p+2]+=lazy[p];
        }
        lazy[p]=0;
    }
    ///no overlap
    if(f>ql || l<qf)
        return INT_MAX;
    ///complete overlap
    if(f>=qf && l<=ql)
        return stree[p];

    ///partial overlap
    int mid=(f+l)/2;
    int x=querylazy(stree,f,mid,qf,ql,2*p+1);
    int y=querylazy(stree,mid+1,l,qf,ql,2*p+2);
    return min(x,y);
}
int main(){
    int a[] = {1,2,0,4,3,5};

    int t,qs,qe,i,inc;
    char ch;
    cin>>t;

    int*tree = buildtree(6,a);
    int l,r;
    while(t--){
        cin>>ch;
        if(ch=='Q'){
            cin>>qs>>qe;
            cout<<"Ans is "<<querylazy(tree,0,5,qs,qe,0);
            cout<<endl;
        }
        else{
            cin>>l>>r>>inc;
            updaterangelazy(tree,0,5,l,r,inc,0);
        }
    }
return 0;
}
