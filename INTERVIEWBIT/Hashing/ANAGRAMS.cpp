#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<vector<int> > anagrams(const vector<string> &A) {
    vector<vector<int> >ans;
    int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
                    97, 101 };
    map<int,vector<int> >m;

    for(int i=0;i<A.size();i++){
        string s=A[i];
        ll x=1;
        for(int j=0;j<s.size();j++){
            x=x*(prime[s[j]-'a']);
        }
        m[x].push_back(i);
    }
    for(auto it=m.begin();it!=m.end();it++){
        vector<int>v=it->second;

        if(v.size()>0){
            ans.push_back(v);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;

}

int main(){

vector<string>v={"eat", "pots", "onset", "stone", "rail", "risen", "caret", "resin", "react", "siren", "sitar", "stair", "liar", "stop", "trace", "notes", "tea", "lair"};

vector<vector<int> >ans=anagrams(v);

for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
