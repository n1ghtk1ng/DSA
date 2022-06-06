#include<bits/stdc++.h>
using namespace std;

class node{
public:
char data;
unordered_map<char,node*>mymap;
bool isterminal;
node(){

}
node(char c,bool t){
data=c;
isterminal=t;
}

};

class trie{
private:


public:
node*root;
trie(){
    root=new node();
}
void AddData(string s){
node*temp=root;
node*t=NULL;
for(int i=0;i<s.size();i++){

    if(temp->mymap[s[i]] !=NULL){
        temp=temp->mymap[s[i]];
    }
    else{

        t=new node(s[i],false);
        temp->mymap[s[i]]=t;
        temp=temp->mymap[s[i]];
    }
}
temp->isterminal=true;
}

bool searchData(string s){
node*temp=root;


for(int i=0;i<s.size();i++){
    if(temp->mymap[s[i]] !=NULL){
        temp=temp->mymap[s[i]];
        //cout<<temp->data<<endl;
    }
    else{
        return false;
    }
}

if(temp->isterminal==true)
    return true;
return false;
}
void fun2(node*temp,string s,int i=-1){
if(i!=-1)
s+=char(i);
if(temp->isterminal==true){
    cout<<s<<endl;
}

for(int i=97;i<=122;i++){
    if(temp->mymap[char(i)]){

        fun2(temp->mymap[char(i)],s,i);
    }
}


}

int fun1(string s){

node*temp=root;
for(int i=0;i<s.size();i++){
    if(temp->mymap[s[i]]!=NULL){
        temp=temp->mymap[s[i]];
    }
    else{
        return -1;
    }

}

fun2(temp,s);
}

};



int main(){

trie t;
int tests;
cin>>tests;

while(tests--){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
    if(s[i]>=65 && s[i]<=90){
        s[i]=s[i]+32;
    }
    }


    t.AddData(s);
}
int q;
cin>>q;
while(q--){
    string s;
    cin>>s;

    if(t.fun1(s)==-1){
        cout<<"No suggestions"<<endl;
        t.AddData(s);
    }
}
return 0;
}

