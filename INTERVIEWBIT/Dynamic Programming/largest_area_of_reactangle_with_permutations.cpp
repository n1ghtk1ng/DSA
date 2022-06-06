#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >sort_mat(vector<vector<int> >&v){

for(int i=0;i<v.size();i++){

    int arr[v[i].size()+1]={0};

    for(int j=0;j<v[i].size();j++){
        arr[ v[i][j] ]++;
    }
    int k=0;
    for(int j=v[i].size();j>=0;j--){
        if(arr[j]==0)
            continue;
        v[i][k++]=j;
        arr[j]--;
        j++;
    }

}
return v;

}
void print_vector(vector<vector<int> >&a){

    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}

int fun(vector<vector<int> >&v){
    vector<vector<int> >dp(1+v.size(),vector<int>(1+v[0].size(),0));
//    print_vector(v);
//    cout<<endl;

    for(int i=1;i<=v.size();i++){
        for(int j=1;j<=v[i-1].size();j++){
//            cout<<v[i-1][j-1]<<endl;
            if(v[i-1][j-1]==1){
                dp[i][j]=1+dp[i-1][j];
            }
            else{
                dp[i][j]=0;
            }
        }
    }

//    print_vector(dp);
//    cout<<endl;
    dp=sort_mat(dp);
//    print_vector(dp);

    int ans=INT_MIN;

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            ans=max(ans,(j+1)*dp[i][j]);
        }
    }

return ans;

}

int main(){

vector<vector<int> >a={{}};

cout<<fun(a);

//a=sort_mat(a);



return 0;
}
