#include<iostream>
using namespace std;

void mySwap(int *aptr,int *bptr){

    int temp = *aptr;
    *aptr = *bptr;
    *bptr = temp;
}


int main(){
    int a=10,b=12;
    mySwap(&a,&b);
    cout<<a<<" "<<b<<endl;
return 0;
}
