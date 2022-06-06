#include<bits/stdc++.h>
using namespace std;

bool mycompare(pair<int,int>p1,pair<int,int>p2){
return (p1.first/p1.second)<(p2.first/p2.second);
}

int main(){
int W=50;
vector<pair<int,int> >v;

v.push_back(make_pair(60,10)); //60 is the cost and 20 is the weight;
v.push_back(make_pair(100,20));
v.push_back(make_pair(120,30));


sort(v.begin(),v.end(),mycompare);
int ans=0;
while(W>0 && v.size()>0){
if(W>=v[v.size()-1].second){
ans+=v[v.size()-1].first;
W-=v[v.size()-1].second;
v.pop_back();
}

else{
    ans+=(v[v.size()-1].first/(v[v.size()-1].second))*(W);
    break;
}

}
cout<<ans;
return 0;
}
