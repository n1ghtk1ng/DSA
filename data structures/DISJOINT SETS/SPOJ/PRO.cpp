#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){


ll n,m,ans=0,num;
cin>>n;
multiset<ll>s;

for(int i=0;i<n;i++){
    cin>>m;
    for(int j=0;j<m;j++){
        cin>>num;
        s.insert(num);
    }
    ans+=*s.rbegin()-*s.begin();


    auto it=s.begin();
    s.erase(it);
    it=s.end();
    it--;
    s.erase(it);

}
cout<<ans;
return 0;
}
