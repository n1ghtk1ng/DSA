#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
int wt;
int node;
    Pair(int n,int w){
        wt=w;
        node=n;
    }
};
class mycompare{
public:
bool operator()(Pair p1,Pair p2){
return p1.wt>p2.wt;
}

};

class graph{
private:
    int V;
public:
    map<int,vector<Pair> >mymap;
    graph(int v){
        V=v;
    }
    void addedge(int a,int b,int w){
        Pair p(b,w);
        mymap[a].push_back(p);
        Pair p1(a,w);
        mymap[b].push_back(p1);
    }
    void prims(int vtx){
        int parent[V+1];
        int value[V+1];
        bool isincluded[V+1];

        for(int i=1;i<=V;i++){
            isincluded[i]=false;
            value[i]=INT_MAX;
        }
        isincluded[vtx]=1;
        Pair p(vtx,0);

        parent[vtx]=-1;
        value[vtx]=0;

        priority_queue<Pair,vector<Pair>,mycompare>pq;
        pq.push(p);

        while(!pq.empty()){
            Pair p=pq.top();
            pq.pop();
            int node=p.node;
            int wt=p.wt;
                        //cout<<"node = "<<node<<" wt = "<<wt<<" "<<value[node]<<endl;
            if(wt>value[node]){
                    //cout<<"hi"<<endl;
                continue;
            }
            isincluded[node]=true;


            vector<Pair>v=mymap[node];
            //cout<<"size = "<<v.size()<<endl;
            for(auto i=0;i<v.size();i++){
                Pair p=v[i];
                int weight=p.wt;
                int no=p.node;
                if(!isincluded[no] && value[no]>weight){

                    Pair p(no,weight);
                    parent[no]=node;
                    value[no]=weight;
                    //cout<<"weight = "<<weight<<" node = "<<no<<" "<<value[no]<<endl;

                    pq.push(p);
                }
            }
        }
        int ans=0;
        //cout<<"mst is "<<endl;
        for(int i=1;i<=V;i++){
            if(isincluded[i]){
                //cout<<i<<" -- "<<parent[i]<<"    "<<value[i]<<endl;
                ans+=value[i];
            }
        }
        cout<<ans;
    }

};

int main(){
int m,n,start;
cin>>n>>m;
graph g(n);
for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    g.addedge(a,b,w);
}
cin>>start;
g.prims(start);
//g.addedge(0,1,4);
//g.addedge(0,7,8);
//g.addedge(1,2,8);
//g.addedge(1,7,11);
//g.addedge(2,3,7);
//g.addedge(2,8,2);
//g.addedge(2,5,4);
//g.addedge(3,4,9);
//g.addedge(3,5,14);
//g.addedge(4,5,10);
//g.addedge(5,6,2);
//g.addedge(6,7,1);
//g.addedge(6,8,6);
//g.addedge(7,8,7);
//g.prims(0);

return 0;
}

