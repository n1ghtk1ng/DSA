#include<iostream>
using namespace std;

int main(){
    int n,i,range;

    cin>>range;
    n=2;
    while(n<=range){
        i=2;
        while(i<=n-1){
            if(n%i==0){
                //cout<<"Not a Prime"<<endl;
                break;
            }

            i = i + 1;
        }
        if(i==n){
            cout<<n<<" ";
        }
    n = n + 1;
    }

return 0;
}
