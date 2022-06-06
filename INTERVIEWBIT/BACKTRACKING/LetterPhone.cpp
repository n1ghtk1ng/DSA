#include<bits/stdc++.h>
using namespace std;

vector<string>letters={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;

void fun(string arr,int j,string &temp,int idx){

if(j==arr.size()){
    ans.push_back(temp);
    return;
}

int character=arr[j]-'0';
for(int i=0;i<letters[character].size();i++){

    temp[idx]=letters[character][i];
    fun(arr,j+1,temp,idx+1);
}


}


int main(){

string s="4";
string temp="";
for(int i=0;i<s.size();i++){
        temp+=" ";
    }
fun(s,0,temp,0);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j];
    }
    cout<<endl;
}


return 0;
}
