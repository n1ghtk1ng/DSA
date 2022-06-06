#include<iostream>
using namespace std;

int main(){
    int n,i,cnt,val;
    cin>>n;
    val =1;
    i = 1;
    while(i<=n){
        cnt =1;
        while(cnt<=i){
            cout<<val<<" ";
            cnt = cnt + 1;
            val = val + 1;
        }
        cout<<endl;
    i = i + 1;
    }
return 0;
}
