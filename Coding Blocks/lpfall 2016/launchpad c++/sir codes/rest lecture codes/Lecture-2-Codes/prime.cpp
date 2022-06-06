#include<iostream>
using namespace std;

int main(){
    int n,i;

    cin>>n;
    i=2;
    while(i<=n-1){
        if(n%i==0){
            cout<<"Not a Prime"<<endl;
            break;
        }

        i = i + 1;
    }
    if(i==n){
        cout<<"Prime No"<<endl;
    }


return 0;
}
