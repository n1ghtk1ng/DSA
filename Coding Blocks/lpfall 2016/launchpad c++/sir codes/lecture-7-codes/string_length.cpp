#include<iostream>
using namespace std;

int length(char input[]){
    int i;
    for(i=0;input[i]!='\0';i++){}

return i;
}

bool palidrome(char input[]){
    int i=0, j = length(input)-1;
    while(i<j){
        if(input[i]!=input[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
char input[100];
cin.getline(input,100);
cout<<length(input);

if(palidrome(input)){
    cout<<input<<" is a palindrome !";
}
else{
    cout<<input <<" is NOT a palindrome !";
}


return 0;
}
