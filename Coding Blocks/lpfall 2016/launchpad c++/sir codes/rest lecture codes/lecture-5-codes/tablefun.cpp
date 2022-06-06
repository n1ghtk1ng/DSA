#include<iostream>
using namespace std;


void printTable(int init_val,int final_val,int step){

    int f,c;
    f = init_val;
    while(f<=final_val){
    c = (5*(f-32))/9;
    cout<<f<<" "<<c<<endl;
    f = f + step;
    }

return;
}
int main(){
int init_val, final_val,step;
cin>>init_val>>final_val>>step;
printTable(init_val,final_val,step);

return 0;
}
