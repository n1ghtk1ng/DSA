#include<iostream>
using namespace std;


int main(){

int alpha =0;
int digits = 0;
int spaces =0;
int others =0 ;
char ch;

ch = cin.get();
while(ch!='$'){


    if(ch>='0'&&ch<='9'){
        digits++;
    }
    else if(ch>='a'&&ch<='z'){
        alpha++;
    }
    else if(ch==' '){
        spaces++;
    }
    else{
        others++;
    }
    ch = cin.get();
}
cout<<"Aphabets : "<<alpha<<endl;
cout<<"digits : "<<digits<<endl;
cout<<"spaces : "<<spaces<<endl;
cout<<"others : "<<others<<endl;
return 0;
}
