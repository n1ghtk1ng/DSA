#include<bits/stdc++.h>
using namespace std;



int main(){

int arr[]={5,6,3,4,5};

int n=sizeof(arr)/sizeof(int);

int f=0,l=n-1;

while(f<=l){
    int mid=(f+l)/2;
//    cout<<"mid = "<<mid<<endl;

    if(mid-1>=f && arr[mid]<arr[mid-1]){
        cout<<mid-1<<endl;
        break;
    }
    if(mid+1<=l && arr[mid]>arr[mid+1]){
        cout<<mid<<endl;
        break;
    }

    if(arr[f]>=arr[mid]){
        l=mid-1;
    }
    else if(arr[l]<=arr[mid]){
        f=mid+1;
    }
    else{
        break;
    }
}



return 0;
}
