#include<bits/stdc++.h>
using namespace std;

bool mycomp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

class trienode{
public:

unordered_map<char,trienode*>m;
char ch;
bool isterminal;

trienode(){
    isterminal=false;
}

trienode(char c){
    ch=c;
    isterminal=false;
}

};

void addwords(string w,trienode *root){

for(int i=0;i<w.size();i++){
    if(root->m[w[i]]!=NULL){
        root=root->m[w[i]];
    }
    else{
        trienode*temp=new trienode(w[i]);
        root->m[w[i]]=temp;
        root=root->m[w[i]];
    }
}
root->isterminal=true;
}

bool searchwords(string w,trienode*root){

for(int i=0;i<w.size();i++){
    if(root->m[w[i]]==NULL){
        return false;
    }
    root=root->m[w[i]];

}
if(root->isterminal==true){
    return true;
}
return false;

}

vector<int> fun(string A, vector<string> &B){

trienode*root=new trienode();
vector<pair<int,int> >arr;
string temp="";
for(int i=0;i<A.size();i++){
    if(A[i]=='_'){
        addwords(temp,root);
        temp="";
    }
    else
        temp+=A[i];
}
addwords(temp,root);

for(int i=0;i<B.size();i++){
    string s=B[i];
    string temp="";
    arr.push_back(make_pair(0,i));
    for(int j=0;j<s.size();j++){
        if(s[j]=='_'){
//            cout<<"temp = "<<temp<<endl;
            if(searchwords(temp,root)){
                arr[i].first++;
            }
            temp="";
        }
        else
            temp+=s[j];
    }
    if(searchwords(temp,root)){
        arr[i].first++;
    }
}
//for(int i=0;i<B.size();i++){
//    cout<<arr[i].first<<" "<<arr[i].second<<endl;}

sort(arr.begin(),arr.end(),mycomp);
vector<int>ans;
for(int i=0;i<B.size();i++){
//    cout<<arr[i].first<<" "<<arr[i].second<<endl;
    ans.push_back(arr[i].second);
}

return ans;
}

int main(){

trienode*root=new trienode();
string A="cool_ice_wifi";
vector<string>B={"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};

vector<int>x=fun(A,B);

for(int i=0;i<x.size();i++){
    cout<<x[i]<<" ";
}

return 0;
}
