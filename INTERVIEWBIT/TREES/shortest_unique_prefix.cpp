#include<bits/stdc++.h>
using namespace std;

class trienode{
public:

unordered_map<char,trienode*>m;
char ch;
bool isterminal;
int cnt;

trienode(){
    isterminal=false;
}

trienode(char c){
    ch=c;
    isterminal=false;
    cnt=1;
}

};

void addwords(string w,trienode *root){

for(int i=0;i<w.size();i++){
    if(root->m[w[i]]!=NULL){
        root=root->m[w[i]];
        root->cnt+=1;
    }
    else{
        trienode*temp=new trienode(w[i]);
        root->m[w[i]]=temp;
        root=root->m[w[i]];
    }
}
root->isterminal=true;
}

string searchwords(string w,trienode*root){
string temp="";
for(int i=0;i<w.size();i++){
    root=root->m[w[i]];
    temp+=w[i];
    if(root->cnt==1){
        return temp;
    }
}


}

vector<string>fun(vector<string> &A) {
    trienode*root=new trienode();
    for(int i=0;i<A.size();i++){
        addwords(A[i],root);
    }
    vector<string>ans;
    for(int i=0;i<A.size();i++){
        ans.push_back(searchwords(A[i],root));
    }
    return ans;
}


int main(){

trienode*root=new trienode();
vector<string>B={"zebra", "dog", "duck", "dove"};

vector<string>x=fun(B);

for(int i=0;i<x.size();i++){
    cout<<x[i]<<" ";
}

return 0;
}
