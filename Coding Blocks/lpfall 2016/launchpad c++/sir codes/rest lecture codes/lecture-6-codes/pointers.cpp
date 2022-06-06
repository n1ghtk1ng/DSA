#include<iostream>
using namespace std;

int main(){
    int x=10,y=20;
    int *ptr = &x;

    cout<< x <<endl;
    cout<< &x <<endl;
    cout<< ptr << endl;
    cout<< &ptr << endl;
    cout<< *(&ptr) <<endl;
    cout<< *(*(&ptr))<<endl;
    cout<< *ptr<<endl;

    ptr = &y;
    cout<< ptr<<endl;
    cout<< *ptr <<endl;
    //ptr = ptr + 1;
    *ptr = *ptr + 1;
    cout<<y;



return 0;
}
