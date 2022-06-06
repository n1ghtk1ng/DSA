#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main(){
unsigned long long n,t,a;
vector<unsigned long long> v;
scanf("%llu",&n);
for(int i = 0;i<n;i++){
scanf("%llu",&a);
if(n < 130)
v.push_back(a);
}
if(n >= 130){
printf("Yes");
return 0;
}
for(int i = 0;i<n;i++){
for(int j = i+1;j<n;j++){
for (int k = j+1;k<n;k++){
for(int l = k+1;l<n;l++){
if((v[i] ^ v[j] ^ v[k]) == v[l]){
printf("Yes\n");
return 0;
}
}
}
}
}
printf("No");
return 0;
}
