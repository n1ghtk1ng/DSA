#include<iostream>
using namespace std;
int main(){

int a,b,no,sum;

cout<<"Hello Coding Blocks ";
cout<<'\n';
a = 10;
b = 5;

cout<<a+b<<endl;

cout<<"Enter a Number ";
cin>>no;
cout<<"You entered"<<no;
sum = (a + b)%no;

if(sum%2==0){
    cout<<"Even Sum"<<endl;
}
else{
    cout<<"Odd Sum "<<endl;
}


return 0;
}
