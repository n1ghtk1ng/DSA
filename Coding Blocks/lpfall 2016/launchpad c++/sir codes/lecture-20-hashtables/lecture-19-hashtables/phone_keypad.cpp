#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

string  s[100] = { ".+@","abc","def","ghi" };
vector<string> v;

void generateStrings(char input[],int i,char output[],int j){
    if(input[i]=='\0'){
        output[j]='\0';
        string s(output);
        v.push_back(s);
        return;
    }
    int current_digit = input[i]-'0';

    for(int k=0;k<s[current_digit].length();k++){
            output[j] = s[current_digit][k];
            generateStrings(input,i+1,output,j+1);
    }
}

int main(){


    char input[10] ;
    cin>>input;
    char temp[10];
    generateStrings(input,0,temp,0);
    for(int i=0;i<v.size();i++){

        cout<< v[i] <<" ";
    }
return 0;
}
