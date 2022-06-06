#include<iostream>
using namespace std;

void readLine(char input[],int max_size,char delim='\n'){

    int i=0;
    char ch= cin.get();

    while(ch!=delim){
        input[i] = ch;
        i++;
        if(i==max_size-1){
            break;
        }
        ch = cin.get();
    }

    input[i] = '\0';
}

int main(){

    int a[] = {1,2,3};
    char b[] = {'a','b','c','\0'};
    char c[] = "Welcome";

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<sizeof(c)<<endl;

    /*char a1[101],b1[101];
    cin>>a1>>b1;
    cout<<a1<<endl;
    cout<<b1<<endl;
    */
    char input[100];
    readLine(input,100,'$');
    cout<<input<<endl;



return 0;
}
