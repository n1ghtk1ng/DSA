#include<iostream>
#include<algorithm>
using namespace std;

int main(){

int a[100];
int n;
cin>>n;
//Input
for(int i=0;i<n;i++){
    cin>>a[i];
}
//Sort
sort(a,a+n);

//Print
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}




return 0;
}
