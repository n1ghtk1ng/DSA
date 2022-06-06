#include<bits/stdc++.h>
using namespace std;
#define N 10000
vector<int>v;
void sieve(){

int arr[N]={0};

for(int i=2;i<=N;i++){
        if(arr[i]==0)
    for(int j=2*i;j<=N;j+=i){
        arr[j]--;
        if(arr[j]==-3)
            v.push_back(j);
    }

}
sort(v.begin(),v.end());
}


int main(){
sieve();
//cout<<v.size()<<endl;
int t;
cin>>t;

while(t--){
        int n;
    cin>>n;
    cout<<v[n-1]<<endl;
}

return 0;
}
