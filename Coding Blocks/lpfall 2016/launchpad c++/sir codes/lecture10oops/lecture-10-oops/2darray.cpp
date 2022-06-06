#include<iostream>
using namespace std;

void fun(int **ptr,int r,int c){

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            ptr[i][j] = 5;
        }
    }
}

int main(){
    int r,c;
    cin>>r>>c;

    int **arr;
    arr = new int*[r];
    for(int i=0;i<r;i++){
        arr[i] = new int[c];
    }
    fun(arr,r,c);
    cout<<arr[r-1][c-1];

return 0;
}
