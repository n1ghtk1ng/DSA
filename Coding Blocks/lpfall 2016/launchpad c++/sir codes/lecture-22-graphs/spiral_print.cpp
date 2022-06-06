#include<iostream>
using namespace std;

void print(int b[][100],int n,int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
return;
}

void spiralPrint(int a[][100],int r,int c){
    int startRow=0,startCol=0;
    int endCol = c-1, endRow = r-1;

    while(startRow<=endRow && startCol<=endCol){

       for(int i=startCol;i<=endCol;i++){
        cout<<a[startRow][i]<<" ";
       }
       startRow++;

       for(int i=startRow;i<=endRow;i++){
        cout<<a[i][endCol]<<" ";
       }
       endCol--;

       if(startRow<endRow){
       for(int i=endCol;i>=startCol;i--){
        cout<<a[endRow][i]<<" ";
       }
       endRow--;
       }

       if(startCol<endCol){
       for(int i=endRow;i>=startRow;i--){
        cout<<a[i][startCol]<<" ";
       }
       startCol++;
       }
    }



}

int main(){

    int a[100][100],rows,cols;
    cout<<"Enter Rows & Cols";
    cin>>rows>>cols;

    //Initialize.
    int value=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            a[i][j] = value;
            value++;
        }
    }
    print(a,rows,cols);
    spiralPrint(a,rows,cols);



return 0;
}
