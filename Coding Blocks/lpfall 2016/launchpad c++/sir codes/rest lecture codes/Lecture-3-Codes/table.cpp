#include<iostream>
using namespace std;

int main(){
int init_val, final_val,step;
int f,c;
cin>>init_val>>final_val>>step;
f = init_val;

while(f<=final_val){
    c = (5*(f-32))/9;
    cout<<f<<" "<<c<<endl;
    f = f + step;
}

return 0;
}
