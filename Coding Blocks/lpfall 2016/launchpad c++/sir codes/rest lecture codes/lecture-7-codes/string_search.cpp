#include<iostream>
#include<cstring>
using namespace std;
bool myCompare(char p1[],char p2[]){



}
int main(){
int n;
char string_list[100][30];
char key[30];
cout<<"Enter no of strings";
cin>>n;

cin.get();

for(int i=0;i<n;i++){
    cin.getline(string_list[i],30);
}
cout<<"Enter the string to be search ";
cin.getline(key,30);

int i;
for(i=0;i<n;i++){
    if(strcmp(key,string_list[i])==0){
        cout<<"Found at index "<<i<<endl;
        break;
    }
}
if(i==n){
    cout<<key<<" not found !";
}


return 0;
}
