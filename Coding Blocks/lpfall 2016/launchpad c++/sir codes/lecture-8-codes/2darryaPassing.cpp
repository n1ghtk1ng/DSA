#include<iostream>
using namespace std;

void print(int a[][100],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
            //value++;
        }

    cout<<endl;
    }
}

int main(){

 int a[100][100];
 int m,n;
 cout<<"Enter the Rows & Cols";
 cin>>n>>m;

 int value=1;
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        a[i][j] = value;
        value++;
    }
 }
 print(a,n,m);
return 0;
}
