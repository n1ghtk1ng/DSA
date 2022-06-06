#include<iostream>
using namespace std;

int main(){

    //Create a 2d Array
    int a[40][40];

    int n,m;
    cout<<"Enter no of row & cols";
    cin>>n>>m;

    //Take Input
    int value=1;
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            a[row][col] = value;
            value++;
        }
    }


    //Output
     for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            cout<<a[row][col]<<" ";

        }
        cout<<endl;
    }
    //Spiral Print
    cout<<"Spiral Print "<<endl;
    int startRow=0,startCol=0,endRow=n-1,endCol=m-1;
    while(startRow<=endRow && startCol<=endCol){

        for(int i=startCol;i<=endCol;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;

        for(int i=startRow;i<=endRow;i++){
            cout<<a[i][endCol]<<" ";
        }
        endCol--;

        if(endRow>startRow){
        for(int i=endCol;i>=startCol;i--){
            cout<<a[endRow][i]<<" ";
        }
        endRow--;
        }
        if(endCol>startCol){
        for(int i=endRow;i>=startRow;i--){
            cout<<a[i][startCol]<<" ";
        }
        startCol++;
        }
    }




return 0;
}
