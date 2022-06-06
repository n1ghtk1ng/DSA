#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >ans;

void fun(int n,vector<int>&v){

if(n<0)
    return;
if(n==0){
    ans.push_back(v);
    return;
}
v.push_back(1);
fun(n-1,v);
v.pop_back();
v.push_back(2);
fun(n-2,v);
v.pop_back();

}

int main(){
vector<int>v;
v.clear();
ans.clear();

fun(3,v);

for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}


return 0;
}
