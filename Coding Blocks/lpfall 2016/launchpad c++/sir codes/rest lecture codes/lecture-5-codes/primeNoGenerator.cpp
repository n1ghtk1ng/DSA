#include<iostream>
using namespace std;

//Forward Declaration
void fun();
bool isPrime(int n);

void generatePrimes(int range){

    for(int i=2;i<=range;i++){
        if(isPrime(i)==true){
            cout<<i<<" ";
        }
    }
return;
}

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    int range;
    cin>>range;
    fun();
    generatePrimes(range);
    return 0;
}

void fun(){
    cout<<"Having Fun !";
}
