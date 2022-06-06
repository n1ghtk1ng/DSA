#include<iostream>
using namespace std;

int fact(int n){
    //Base Case
    if(n==0){
        return 1;
    }
    //Recursive Case.
    int chotaFact = fact(n-1);
    return n*chotaFact;
}

int fib(int n){
//Base Case
    if(n==0||n==1){
        return n;
    }
//Recursive Case.
    int f1 = fib(n-1);
    int f2 = fib(n-2);
    return f1 + f2;
}


int main(){

//cout<<fact(5)<<endl;
cout<<fib(6);
return 0;
}
