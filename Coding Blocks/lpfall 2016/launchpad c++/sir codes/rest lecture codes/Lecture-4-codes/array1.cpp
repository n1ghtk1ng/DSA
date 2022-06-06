#include<iostream>
using namespace std;

int main(){

    int a[10];
    cout<<"Enter 5 Numbers ";

    for(int i=0;i<5;i++){
        cin>>a[i];
    }

    //Output in Reverse Order
    for(int i=4;i>=0;i--){
        cout<<a[i]<<" ";
    }

return 0;
}
