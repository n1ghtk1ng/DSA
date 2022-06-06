#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){

int price[] = { 10, 7, 19 };
int n = sizeof(price)/sizeof(price[0]);
int k = 45;

vector<pii>ans;

for(int i=0;i<n;i++){
    ans.push_back(make_pair(price[i],i+1));
}

sort(ans.begin(),ans.end());

int temp=k;
int answ=0;
for(int i=0;i<n;i++){
    answ+=min(ans[i].second,k/ans[i].first);  //(allowed vs max possible)
    k-=ans[i].first*(min(ans[i].second,k/ans[i].first));

}
cout<<"answer = "<<answ<<endl;
return 0;
}
