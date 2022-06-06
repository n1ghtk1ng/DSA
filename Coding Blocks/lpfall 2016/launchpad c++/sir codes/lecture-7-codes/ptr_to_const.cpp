#include<iostream>
using namespace std;

int main(){
    //String stored in a char arrray
    char ptr1[] = "Abcdef";
    cout<<sizeof(ptr1)<<endl;

    //Pointer to a string constant
    char *ptr = "Abcdef";
    cout<<sizeof(ptr)<<endl;

}
