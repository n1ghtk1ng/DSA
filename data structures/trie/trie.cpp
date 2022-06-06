#include<bits/stdc++.h>
using namespace std;

class node{
public:
char data;
unordered_map<char,node*>mymap;
bool isterminal;
int cnt;
node(){

}
node(char c,bool t){
data=c;
isterminal=t;
cnt=1;
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
        temp->cnt++;
    }
    else{

        t=new node(s[i],false);
        temp->mymap[s[i]]=t;
        temp=temp->mymap[s[i]];
    }
}
temp->isterminal=true;
}
int cntprefixes(string s){

node*temp=root;

for(int i=0;i<s.size();i++){
    temp=temp->mymap[s[i]];
    if(temp->isterminal)
    return temp->cnt;
}

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
int isitfreenode(node*temp){
for(int i=97;i<=123;i++){
    if(temp->mymap[char(i)])
        return 0;
}
return 1;

}
int leafnode(node*root){
    if(root->isterminal)
        return true;
    return false;
}
bool deleteword(node*root,string s,int curr_idx){

if(root){
    //base case
    if(curr_idx==s.size()){
        if(root->isterminal==true){
            root->isterminal=false;
            if(isitfreenode(root))
                return true;
            return false;
        }
    }
    //recursive case
    else{

        if(deleteword(root->mymap[s[curr_idx]],s,curr_idx+1)){
            delete root->mymap[s[curr_idx]];
            return (isitfreenode(root) && !leafnode(root));
        }
    }
}


}

};



int main(){

//int tests;
//cin>>tests;
//
//while(tests--){
//
//trie t;
//int n;
//cin>>n;
//bool ans=true;
//int flag=0;
//for(int i=0;i<n;i++){
//    string s;
//    cin>>s;
//    if(t.searchData(s)==true)
//        continue;
//    if(flag==0){
//        t.AddData(s);
//        //cout<<"prefixes of "<<s<<" are "<<t.cntprefixes(s)<<endl;
//        if(t.cntprefixes(s)>1){
//        ans=false;
//        flag=1;
//        }
//    }
//}
//if(ans==true)
//    cout<<"YES"<<endl;
//else
//    cout<<"NO"<<endl;
//}
trie t;
t.AddData("amana");
t.AddData("aman");
t.AddData("ama");
t.AddData("a");

if(t.deleteword(t.root,"amana",0))
cout<<"yo"<<endl;

if(t.searchData("amana"))
    cout<<"yes"<<endl;
else
    cout<<"no"<<endl;

return 0;
}
