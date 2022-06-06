#include<bits/stdc++.h>
using namespace std;

vector<vector<string> >ans;

bool ispalindrome(string s){

int i=0,j=s.size()-1;
while(i<j){
    if(s[i]!=s[j]){
        return false;
    }
    i++;
    j--;
}
return true;
}

void fun(string s,vector<string>&v,int i){
//cout<<"i = "<<i<<endl;
if(i==s.size()){
    ans.push_back(v);
    return;
}

string temp="";
for(int j=i;j<s.size();j++){
    temp+=s[j];
//    cout<<"temp = "<<temp<<endl;
    if(ispalindrome(temp)){
//        cout<<"temp = "<<temp<<endl;
        v.push_back(temp);
        fun(s,v,j+1);
        v.pop_back();
    }


}

}

int main(){

string s="aab";
vector<string>v;
fun(s,v,0);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}


return 0;
}

