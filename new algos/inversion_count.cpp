#include<bits/stdc++.h>
using namespace std;
int merge(int a[],int f,int mid,int l){
    int i=f,j=mid+1,k=f;
    int z=0;
    int c[1000000];

    while(i<=mid && j<=l){
        if(a[i]<a[j]){
            c[k++]=a[i++];
        }
        else{
            c[k++]=a[j++];
            z+=mid+1-i;
        }
    }
    while(i<=mid){
        c[k++]=a[i++];
    }
    while(j<=l){
        c[k++]=a[j++];
    }

    for(int i=f;i<=l;i++){
        a[i]=c[i];
    }
    return z;
}

int invcount(int a[],int f,int l){
    int t=0;
    if(f<l){

        int mid=(f+l)/2;
        t=invcount(a,f,mid);
        t+=invcount(a,mid+1,l);
        t+=merge(a,f,mid,l);
    }
    return t;
}



int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n+1];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<invcount(a,0,n-1)<<endl;
    }

}

