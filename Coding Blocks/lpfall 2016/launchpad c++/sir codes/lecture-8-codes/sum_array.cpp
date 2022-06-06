#include<iostream>
using namespace std;

int sum(int a[],int n){
    //Base Case
    if(n==0)
        return 0;

    int chotaArray[100];
    for(int i=1;i<n;i++){
        chotaArray[i-1]=a[i];
    }

    int ans = a[0] + sum(chotaArray,n-1);
    return ans;
}

int sum2(int a[],int n,int i){
    if(i==n){
        return 0;
    }
    int ans = a[i] + sum2(a,n,i+1);
    return ans;
}
//From last to first
int sum3(int a[],int n){
    if(n==0)
        return 0;

    int ans = a[n-1] + sum3(a,n-1);
    return ans;
}


int main(){
int a[] = {1,2,3,4,5,6};
cout<<sum(a,6)<<endl;
cout<<sum2(a,6,0)<<endl;
cout<<sum3(a,6)<<endl;
return 0;
}
