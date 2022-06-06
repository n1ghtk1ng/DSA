#include<iostream>
using namespace std;

int main(){
    int init,finalv,step;
    int f,c;

    cin>>init>>finalv>>step;
    f = init;
    while(f<=finalv){
        c = 5*(f-32)/9;

        cout<< f <<"  " <<c <<endl;

        f = f + step;
    }

return 0;
}
