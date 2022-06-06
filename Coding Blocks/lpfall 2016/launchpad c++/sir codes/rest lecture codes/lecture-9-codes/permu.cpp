#include<iostream>
using namespace std;

void permute(char a[],int i=0){
    if(a[i]=='\0'){
        cout<<a<<endl;
        return;
    }

    for(int j=i;a[j]!='\0';j++){
        swap(a[i],a[j]);
        permute(a,i+1);
        swap(a[i],a[j]);
    }
}

void printSubsequences(char a[],int i,char output[],int j){
    if(a[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }
    //Two Cases.
    output[j] = a[i];
    //output[j+1] = '\0';
    printSubsequences(a,i+1,output,j+1);

    //output[j] ='\0';
    printSubsequences(a,i+1,output,j);
}


int main(){
    char a[]= "ABC";
    char out[100];
    //permute(a);
    printSubsequences(a,0,out,0);

return 0;
}
