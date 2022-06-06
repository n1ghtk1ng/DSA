#include<iostream>
using namespace std;

int * makeArray(){
    int a[] = {1,2,3,4};
    for(int i=0;i<4;i++){
        cout<<*(a+i)<<endl;
    }
    cout<<"Addres of array is "<<a<<endl;
    return a;
}
int main(){
int *a = makeArray();

cout<<"IN Main ";
cout<<a<<endl;

for(int i=0;i<4;i++){
    cout<<*(a+i)<<endl;
}
return 0;
}
