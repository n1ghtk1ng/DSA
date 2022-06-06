#include<iostream>
using namespace std;

int main(){

char ch;
cin>>ch;

switch(ch){
    case 'm':
    case 'M': cout<<"Monday"<<endl;
              break;
    case 'T': cout<<"Tuesday";
    case 't' : cout<<"tuesday";
                break;
    default: cout<<"Enter M or T or t ";
}
int no;
cout<<"Enter a no";
cin>>no;

no%2==0? cout<<"Even":cout<<"Odd";




return 0;
}
