#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdio>
using namespace std;


int main(){

    int n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        a[i] = n - i;
    }
    clock_t t1;
    t1 = clock();
    sort(a,a+n);
    t1 = clock() -t1;

   printf("%.16f",t1);



}
