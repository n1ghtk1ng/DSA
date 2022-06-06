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
    void dijkstra(int vtx){
        int dist[V+1];
        int parent[V+1];

        for(int i=1;i<=V;i++){
            dist[i]=INT_MAX;
            parent[i]=-1;
        }
        dist[vtx]=0;


        priority_queue<Pair,vector<Pair>,mycompare>pq;
        Pair p(vtx,0);
        pq.push(p);

        while(!pq.empty()){
            Pair temp=pq.top();
            pq.pop();
            int w=temp.wt;
            int n=temp.node;
            if(dist[n]<w){
                continue;
            }
//                        cout<<"weight = "<<w<<" node = "<<n<<" dist = "<<dist[n]<<endl;

            vector<Pair>v=mymap[n];
            for(int i=0;i<v.size();i++){
                int weight=v[i].wt;
                int node=v[i].node;
                if(dist[node]>weight+w){
                    dist[node]=weight+w;
                    Pair po(node,dist[node]);
                    parent[node]=n;
                    pq.push(po);
                }
            }
        }
        for(int i=1;i<=V;i++){
                if(i==vtx)
                continue;
                if(dist[i]==INT_MAX)
                    cout<<-1<<" ";
                else
            cout<<dist[i]<<" ";
        }
//        cout<<"path from 8 to 0 is "<<endl;
//        cout<<4<<"<--";
//        int i=4;
//        while(parent[i]!=-1){
//            cout<<parent[i]<<"<--";
//            i=parent[i];
//        }
    }
};

int main(){
/*
int tests;
cin>>tests;
while(tests--){
int m,n;
    cin>>m>>n;
    graph g(m);
    while(n--){
        int a,b,w;
        cin>>a>>b>>w;
        g.addedge(a,b,w);
    }
    int start;
    cin>>start;
    g.dijkstra(start);
    cout<<endl;


}
*/

graph g(9);
g.addedge(0,1,4);
g.addedge(0,7,8);
g.addedge(1,2,8);
g.addedge(1,7,11);
g.addedge(2,3,7);
g.addedge(2,8,2);
g.addedge(2,5,4);
g.addedge(3,4,9);
g.addedge(3,5,14);
g.addedge(4,5,10);
g.addedge(5,6,2);
g.addedge(6,7,1);
g.addedge(6,8,6);
g.addedge(7,8,7);
g.dijkstra(0);

return 0;
}
