#include<iostream>
using namespace std;

int x=10;
int main(){
x = 12;

int x = 10;
int i;
    for( i=0;i<5;i++){
         x = i;
        cout<<x <<" -- "<<::x<<endl;
    }
    cout<<"Value of x is "<<x <<endl;
    ::x = ::x + 2;
    cout<<"Value of Global x is "<< ::x <<endl;
    cout<<i <<endl;


return 0;
}
