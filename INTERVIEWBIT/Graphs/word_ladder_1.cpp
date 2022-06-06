#include<bits/stdc++.h>
using namespace std;

#define pii pair<string,int>
int ladderLength(string start, string end, vector<string> &dictV) {
    unordered_map<string,bool>vis;

    unordered_map<string,bool>m;

    for(int i=0;i<dictV.size();i++){
        m[dictV[i]]=true;
    }
    queue<pii>q;
    q.push(make_pair(start,1));
    vis[start]=true;

    while(!q.empty()){
        string s=q.front().first;
        int steps=q.front().second;

        q.pop();

        if(s==end){
            return steps;
        }

        for(int i=0;i<s.size();i++){
            for(int j=0;j<26;j++){
                string temp=s;
                temp[i]=char('a'+(temp[i]+j-97)%26);

                if(m[temp] && !vis[temp]){
                    q.push(make_pair(temp,1+steps));
                    vis[temp]=true;
                }
            }
        }
    }
    return 0;

}


int main(){

string start="bb";
string destn="ab";

vector<string>dict={"bb","ab"};

cout<<ladderLength(start,destn,dict);

return 0;
}
