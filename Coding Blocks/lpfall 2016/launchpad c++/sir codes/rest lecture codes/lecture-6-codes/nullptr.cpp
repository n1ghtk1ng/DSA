#include<iostream>
using namespace std;


int main(){
    int *ptr=NULL;
    //ptr = &x;
    int x = 5;

    *ptr = *ptr + 6;

    cout<<ptr;


return 0;
}
