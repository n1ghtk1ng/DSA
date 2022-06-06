#include<bits/stdc++.h>
using namespace std;

//int ans=0;
int n=2;
int fun(int i,int j,int l,int *arr){
cout<<"i = "<<i<<" j = "<<j<<" l = "<<l<<endl;

if(i>j)
    return 0;

if(i==j)
    return l;

//cout<<"hi "<<endl;
int t=INT_MAX;
int min_index=-1;
for(int k=i;k<=j;k++){
    cout<<"k = "<<k<<endl;
    if(arr[k]!=-1){
        if(t>l+fun(i,k-1,k,arr)+fun(k+1,j,l-k-1,arr)){
            t=l+fun(i,k-1,k,arr)+fun(k+1,j,l-k-1,arr);
            min_index=k;
            cout<<"t = "<<t<<endl;
//            cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<" t = "<<t<<endl;
        }
//        t=min(t,l+fun(i,k-1,k,arr)+fun(k+1,j,l-k-1,arr));
    }
}
arr[min_index]*=-1;
//cout<<"t = "<<t<<endl;
//cout<<"min = "<<min_index<<endl;
return t;

}


int main(){

int n=6;
int arr[3]={1,2,5};
//cout<<"hi"<<endl;
cout<<fun(0,2,n,arr)<<endl;
//cout<<"hi"<<endl;

return 0;
}
