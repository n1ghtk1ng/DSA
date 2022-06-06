#include<bits/stdc++.h>
#include<map>
using namespace std;

int power(int x,int n){

if(n==0)
return 1;

if(n & 1)//i.e. if b is odd
{
    int xsq=power(x,n/2);
    return x*xsq*xsq;
}
else{
    int xsq=power(x,n/2);
    return xsq*xsq;
}
}

int main(){

    cout<<power(4,5);

}
