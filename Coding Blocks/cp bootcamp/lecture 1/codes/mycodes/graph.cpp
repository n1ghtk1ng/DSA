#include<bits/stdc++.h>
#include<map>
using namespace std;

class graph
{

    int v;
    unordered_map<string,vector<string> >adjlist;
    public:
    graph(int V){
        v=V;
    }
    void addedge(string s1,string s2){
        adjlist[s1].push_back(s2);
        adjlist[s2].push_back(s1);
    }
    void dfshelper(string city,map<string,bool>&m){
        cout<<city<<" ";
        m[city]=true;
        for(auto it=adjlist[city].begin();it!=adjlist[city].end();it++){
            if(!m[*it]){
                dfshelper(*it,m);
            }
        }
    }
    void dfs(string startcity){
        map<string,bool>m;
        for(auto it=adjlist.begin();it!=adjlist.end();it++){

            m[it->first]=false;
        }
        dfshelper(startcity,m);

    }
    void print(){
        for(auto it=adjlist.begin();it!=adjlist.end();it++){
            cout<<it->first<<"--> ";
            for(auto i=it->second.begin();i!=it->second.end();i++){

                cout<<*i<<",";
            }
            cout<<endl;
        }
    }
};

int main(){

graph g(4);
g.addedge("kohat","pitampura");
g.addedge("kohat","dwarka");
g.addedge("rohini","pitampura");
g.addedge("dwarka","pitampura");
g.print();
cout<<endl;
cout<<"DFS is"<<endl;
g.dfs("kohat");
}


/*int main()
{
    map<string,int>m;
    m["apple"]=100;
    m["mango"]=80;
    m["pear"]=60;

    char fruit[100];
    cin>>fruit;

    ///cout<<"price of fruit is "<<m[fruit]<<endl;
///searching in logn time for map and o(1) for unordered map
if(m.count(fruit)>0){
    cout<<"price of fruit is"<<m[fruit]<<endl;
}
else
{
    cout<<"no such fruit"<<endl;
}
///one key cant have two values here

}

*/
