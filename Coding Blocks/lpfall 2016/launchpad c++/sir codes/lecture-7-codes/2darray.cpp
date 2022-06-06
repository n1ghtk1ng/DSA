#include<iostream>
using namespace std;

int main(){

    //Create a 2d Array
    int a[40][40];

    int n,m;
    cout<<"Enter no of row & cols";
    cin>>n>>m;

    //Take Input
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            cin>>a[row][col];
        }
    }

    //Output
     for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            cout<<a[row][col]<<" ";

        }
        cout<<endl;
    }


return 0;
}
