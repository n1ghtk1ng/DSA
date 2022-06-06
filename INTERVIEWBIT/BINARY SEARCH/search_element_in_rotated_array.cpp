#include<bits/stdc++.h>
using namespace std;

int fun(int arr[],int f,int l,int el){

    if(f>l){
        return -1;
    }
    int mid=(f+l)/2;
    if(arr[mid]==el){
        return mid;
    }

    if(arr[f]<=arr[mid]){
        if(arr[f]<=el && arr[mid]>=el){
            return fun(arr,f,mid-1,el);
        }
        else{
            return fun(arr,mid+1,l,el);
        }
    }
    if(arr[l]>=arr[mid]){
        if(arr[mid]<=el && arr[l]>=el){
            return fun(arr,mid+1,l,el);
        }
        else{
            return fun(arr,f,mid-1,el);
        }
    }


}


int main(){

int arr[]={7,8,1,2,3,4,5,6};
int n=sizeof(arr)/sizeof(int);
for(int i=0;i<n;i++)
cout<<fun(arr,0,n-1,arr[i])<<endl;



return 0;
}
