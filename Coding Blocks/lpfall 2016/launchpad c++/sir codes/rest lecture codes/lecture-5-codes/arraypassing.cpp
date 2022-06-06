#include<iostream>
using namespace std;

//Arrays are always passed by reference automatically.
int sumOfArray(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += a[i];
        //a[i] = 0;
    }
return sum;
}


int main(){
    int a[100],n;
    cout<<"Enter n ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Sum of array is "<<sumOfArray(a,n);

}
