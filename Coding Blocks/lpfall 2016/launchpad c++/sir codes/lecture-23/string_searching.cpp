#include<iostream>
#include<cstring>
using namespace std;


int stringSearch(char *t,char *s){
    int m = strlen(t);
    int n= strlen(s);

    for(int i=0;i<=m-n;i++){

        int j=0;
        while(j<n){
            if(t[i+j]!=s[j]){
                break;
            }
            j++;
        }
        if(j==n){
            return i;
        }
    }
    return -1;
}

int main(){

    char text[200] = "Today we are having a class on strings and data structures";
    char searchText[100];

    cin.getline(searchText,100);

    cout<<stringSearch(text,searchText);

}
