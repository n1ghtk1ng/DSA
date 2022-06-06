#include<iostream>
using namespace std;

int main(){

    int no,prec;
    float i,ans,inc = 1;

    cin>>no>>prec;

    int current_p = 0;
    i = 0;

    while(current_p<=prec){

        while(i*i<=no){
            i = i + inc;
        }
        i = i - inc;
        inc = inc/10;

    current_p++;
    }
    cout<<i<<endl;

return 0;
}
