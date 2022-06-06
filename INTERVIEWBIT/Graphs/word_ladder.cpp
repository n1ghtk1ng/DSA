#include<bits/stdc++.h>
using namespace std;

#define pii pair<string,int>
int ladderLength(string start, string end, unordered_map<string,bool>&m) {
    unordered_map<string,bool>vis;
    queue<pii>q;
    q.push(make_pair(start,1));
    vis[start]=true;


    while(!q.empty()){
        string s=q.front().first;
        int steps=q.front().second;
//        cout<<"s = "<<s<<endl;
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
//                    parent[temp].push_back(s);
                }
            }
        }
    }
    return 0;
}

void fun(int steps,vector<vector<string> >&ans,vector<string>&temp,string end,string s,unordered_map<string,bool>&m,unordered_map<string,bool>&vis){
//cout<<"s = "<<s<<endl;
if(steps==1){
    if(end==s){
        ans.push_back(temp);
    }
    return;
}

vis[s]=true;

for(int i=0;i<s.size();i++){
    for(int j=0;j<26;j++){
        string tempi=s;
        tempi[i]=char('a'+(tempi[i]+j-97)%26);
//        cout<<"tempi = "<<tempi<<endl;

        if(m[tempi] && !vis[tempi]){
            temp.push_back(tempi);
            fun(steps-1,ans,temp,end,tempi,m,vis);
            temp.pop_back();
        }
    }
}
vis[s]=false;

}

vector<vector<string> >findLadders(string start, string end, vector<string> &dict) {
    vector<vector<string> >ans;
    vector<string>temp;
    unordered_map<string,bool>m;
    unordered_map<string,bool>vis;
//    unordered_map<string,vector<string> >parent;

    for(int i=0;i<dict.size();i++){
        m[dict[i]]=true;
    }
    m[end]=true;

    int steps=ladderLength(start,end,m);
    if(steps==0)
        return ans;

    temp.push_back(start);
    fun(steps,ans,temp,end,start,m,vis);




    return ans;
}



int main(){

string start="hit";
string destn="hot";

vector<string>dict={"hot","dot","dog","lot","log"};

vector<vector<string> >v=findLadders(start,destn,dict);

for(int i=0;i<v.size();i++){
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<" ";
    }
    cout<<endl;
}

return 0;
}
