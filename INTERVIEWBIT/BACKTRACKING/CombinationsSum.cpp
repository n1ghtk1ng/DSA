#include<bits/stdc++.h>
using namespace std;

/// Here an element can be used infinite amount of times

vector<vector<int> >ans;
void fun(vector<int>&arr,int i,vector<int>&temp,int sum){

if(sum<0){
    return;
}
if(sum==0){
    ans.push_back(temp);
    return;
}

for(int j=i;j<arr.size();j++){
    temp.push_back(arr[j]);
    fun(arr,j,temp,sum-arr[j]);
    temp.pop_back();
}

}


int main(){

vector<int>v={2,3,6,7};
int sum=7;
vector<int>temp;
fun(v,0,temp,sum);
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
//cout<<ans.size()<<endl;

return 0;
}


