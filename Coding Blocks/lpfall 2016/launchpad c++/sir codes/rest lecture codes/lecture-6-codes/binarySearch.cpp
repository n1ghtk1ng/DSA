#include<iostream>
using namespace std;

int binarySearch(int a[],int n,int key){
    int s = 0,e = n-1,m;

    while(s<=e){
        m = (s+e)/2;

        if(a[m]==key){
            return m;
        }
        else if(a[m]>key){
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
return -1;
}


int main(){

int a[100];
int n;
cin>>n;
//Input
for(int i=0;i<n;i++){
    cin>>a[i];
}
int key;
cout<<"Enter the key ";
cin>>key;

int ans = binarySearch(a,n,key);

if(ans!=-1){
    cout<<"Found at index "<<ans;
}
else{
    cout<<"Not found ! ";
}
return 0;
}
