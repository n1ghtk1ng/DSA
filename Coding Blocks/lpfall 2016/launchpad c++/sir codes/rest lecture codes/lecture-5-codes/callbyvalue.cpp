#include<iostream>
using namespace std;


void myswap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
    cout<<"In Swap Function ";
    cout<<x <<" "<<y<<endl;
return;
}
//Call By Value
void myswap1(int x,int y){
    int temp = x;
    x = y;
    y = temp;
    cout<<"In Swap Function ";
    cout<<x <<" "<<y<<endl;
return;
}



int main(){
    int a = 10;
    int b = 12;

    myswap(a,b);
    cout<<"In Main ";
    cout<<a <<" "<<b<<endl;

return 0;
}
