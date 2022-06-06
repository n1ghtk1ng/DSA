#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >ans;
void fun(int N,int i,vector<int>&temp){

if(temp.size()==2){
    ans.push_back(temp);
    return;
}

for(int j=i;j<=N;j++){
    temp.push_back(j);
    fun(N,j+1,temp);
    temp.pop_back();
}

}


int main(){

//vector<int>v={1,2,3};
int n=10;
vector<int>temp;
fun(n,1,temp);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
//cout<<ans.size()<<endl;

return 0;
}

