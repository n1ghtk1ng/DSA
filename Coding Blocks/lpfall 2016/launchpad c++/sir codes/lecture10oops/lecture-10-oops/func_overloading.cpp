#include<iostream>
using namespace std;


void print(int a,int b){
    cout<<a<<b;
return;
}
void print(int a){
    cout<<a;
}

void print(char c){
    cout<<c;
}
void print(){
    cout<<"Hey";
}

int main(){
    print(5);
    print(5,6);
    print();

}
