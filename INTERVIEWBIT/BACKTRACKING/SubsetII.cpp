#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >ans;
void fun(vector<int>&arr,int j,vector<int>&temp){

    ans.push_back(temp);

for(int i=j;i<arr.size();i++){
    if(i!=j && arr[i]==arr[i-1])
    continue;
    temp.push_back(arr[i]);
    fun(arr,i+1,temp);
    temp.pop_back();
}

}


int main(){

vector<int>v={1,2,2};
vector<int>temp;
fun(v,0,temp);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}


return 0;
}
