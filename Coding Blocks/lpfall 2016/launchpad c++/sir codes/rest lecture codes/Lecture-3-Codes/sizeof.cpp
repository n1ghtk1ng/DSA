#include<iostream>
#define PI 3.143
#define HELLO "Hello Coding Blocks"
#define SEMICOLON ;
#define PRINT cout<<
#define AND &&
#define OR ||
using namespace std;

int main(){

    int a=1;
    if(5%2 || a++){
        cout<<"In If "<<endl;
        cout<<a<<endl;
    }
    else{
        cout<<"In else";
        cout<<a<<endl;
    }
    a=0;
    if(++a){
        cout<<"Hello";
    }
    else{
        cout<<"Bye";
    }


return 0;
}
