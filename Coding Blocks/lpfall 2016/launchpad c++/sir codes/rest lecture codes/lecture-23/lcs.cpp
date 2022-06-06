#include<iostream>
#include<cstring>
using namespace std;

int lcs(char s1[],char s2[],int i,int j){

    if(i==strlen(s1)||j==strlen(s2)){
        return 0;
    }
    ///Match
    if(s1[i]==s2[j]){
        return 1 + lcs(s1,s2,i+1,j+1);
    }
    ///Mismatch
    else{
        return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
}

int main(){

cout<< lcs("apple","mangoe",0,0);

}
