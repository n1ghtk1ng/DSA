#include<iostream>
using namespace std;

void printArray(int *a,int n){

     cout<<sizeof(a)<<endl;

     for(int i=0;i<n;i++){
        cout<< *(a+i)<<endl;
    }
}



int main(){
    int x = 10;
    int *ptr = &x;

    cout<<sizeof(ptr)<<endl;

    int a[] = {1,2,3,4};
    int *ptr2 = a;

    cout<<sizeof(a)<<endl;
    cout<<a <<endl;

    cout<<sizeof(ptr2)<<endl;
    cout<<ptr2<<endl;

    cout<< a - ptr <<endl;

    printArray(a,4);

    for(int i=0;i<4;i++){
        cout<< *(a+i)<<endl;
    }

return 0;
}
