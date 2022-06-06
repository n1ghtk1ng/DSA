#include<bits/stdc++.h>
using namespace std;
long long int z[10000]={0};
void getarray(string s){
long long int l=0,r=0;
long long int n=s.size();

for(long long int i=0;i<s.size();i++){
    if(i>r){
        l=r=i;
        while(r<n && s[r-l]==s[r]){
            r++;
        }
        z[i]=r-l;
        r--;
    }
    else{
        long long int k=i-l;
        if(z[k]<r-i+1)
            z[i]=z[k];
        else{
            l=i;
            while(r<n && s[r-l]==s[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
    }
}

}

int main(){
string s;
cin>>s;
long long int n=s.size();
///longest palindromic prefix
long long int i=0,j=n-1;
long long int sj=n-1;
long long int lpp=0;

while(i<j){

    if(s[i]!=s[j]){
        i=0;
        if(sj==j){
            j--;
        }
        sj=j;
        lpp=0;
    }
    else{
        lpp+=2;
        i++;
        j--;

    }
}
if(i==j){
    lpp+=1;
}
///longest palindromic suffix
i=0,j=n-1;
long long int si=0;
long long int lps=0;

while(i<j){

    if(s[i]!=s[j]){
        j=n-1;
        if(si==i){
            i++;
        }
        si=i;
        lps=0;
    }
    else{
        lps+=2;
        i++;
        j--;
    }
}
if(i==j)
    lps+=1;

string ans="";
for(long long int i=n-lps;i<n;i++){
    ans+=s[i];
}
for(long long int i=0;i<lpp;i++){
    ans+=s[i];
}

cout<<ans<<endl;
string x=ans;
getarray(x);
int mp[10000];
for(long int i=0;i<=10000;i++){
    mp[i]=0;
}
for(int i=0;i<ans.size();i++){
    mp[z[i]]++;
}
for(long long int i=10000;i>0;i--){
    mp[i-1]+=mp[i];
}

for(long long int i=0;i<ans.length();i++){
    cout<<1+mp[i+1]<<" ";
}

return 0;
}
