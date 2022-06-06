#include<iostream>
using namespace std;

void printHello(int x){

    cout<<"Hello World !"<<x;

return;
}

int square(int x){
    int ans = x*x;
return ans;
}

int add(){
    int a,b;
    cin>>a;
    cin>>b;
return a+b;
}

int main(){
    int no;
    cin>>no;

    printHello(no);
    int ans = square(no);
    cout<<ans<<endl;
    cout<<"Adding two numbers ";
    cout<<add();

return 0;
}
