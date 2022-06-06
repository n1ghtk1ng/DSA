#include<iostream>
using namespace std;

void print(char a[],int i){
    if(a[i]=='\0'){
        return;
    }

    print(a,i+1);
    cout<<a[i];


}

int main(){
char a[] = "Hello World";
print(a,0);
return 0;
}
