#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void fun(vector<ll>&sieve){
ll n=100001;
bool b[n+1];
for(int i=0;i<=100001;i++)
    b[i]=true;

for(int i=2;i*i<=n;i++){
    if(b[i]==true){
        for(int j=i*i;j<=n;j+=i){
            b[j]=false;
        }
    }
}
b[0]=b[1]=false;

for(int i=0;i<=n;i++){
    if(b[i]==true)
        sieve.push_back(i);
}
}



int main(){
vector<ll>sieve;
fun(sieve);

ll t;
cin>>t;

while(t--){
    ll a,b;
    cin>>a>>b;


    bool prime[b-a+2];
    memset(prime,true,sizeof(prime));

    for(ll i=0;i<sieve.size()&& sieve[i]*sieve[i]<=b;i++){
        ll start=(a/sieve[i])*sieve[i];
           if(start < a)
            start+=sieve[i];
        //cout<<"start = "<<start<<endl;

        for(ll j=start;j<=b;j+=sieve[i]){
            //cout<<j-start<<endl;
            if(j==sieve[i])
                continue;

            if(j%sieve[i]==0){
                prime[j-a]=false;///subtract from starting element of range i.e. a
            }
        }

    }
    for(ll i=a; i<=b;i++){
        if(i==1)
            continue;
        if(prime[i-a]==true)
            cout<<i<<endl;
    }

}
return 0;
}
