#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >ans;

//void print(vector<int>&v){
//
//for(int i=0;i<v.size();i++){
//    cout<<v[i]<<" ";
//}
//cout<<endl;
//}

bool check(vector<int>&v,int i,int j,int val){

for(int k=i;k<=j;k++){
    if(v[k]==val){
        return false;
    }
}
return true;

}

void fun(vector<int>&v,int i){

if(i==v.size()){
    ans.push_back(v);
    return;
}

for(int j=i;j<v.size();j++){
    if(!check(v,i,j-1,v[j])){
        continue;
    }
    swap(v[i],v[j]);
    fun(v,i+1);
    swap(v[i],v[j]);
}

}

int main(){

vector<int>v={0,1,1};

fun(v,0);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
cout<<ans.size()<<endl;

return 0;
}
