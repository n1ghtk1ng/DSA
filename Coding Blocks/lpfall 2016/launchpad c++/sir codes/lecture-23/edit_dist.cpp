#include<iostream>
#include<cstring>
using namespace std;

int editDist(char *a,char *b,int i,int j){
    if(i==0){
        return j;
    }
    if(j==0){
        return i;
    }
    if(a[i-1]==b[j-1]){
        return editDist(a,b,i-1,j-1);
    }
    else{
        int ins = editDist(a,b,i,j-1) + 1;
        int del = editDist(a,b,i-1,j) + 1;
        int rep = editDist(a,b,i-1,j-1) +1;

        return min(min(ins,del),rep);
    }
}
int main(){
char a[] = "apple";
char b[] = "aamplek";

cout<<editDist(a,b,5,strlen(b));
return 0;
}
