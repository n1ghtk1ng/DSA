#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
public:
    Graph(int v){
        V=v;
        adjList = new list<int>[v];
    }
    void addEdge(int u,int v,bool bidir=true){
        if(bidir){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }
    ///Breadth First Search/ Traversal
    void bfs(int src){
        bool *visited  = new bool[V];

        for(int i=0;i<V;i++){
            visited[i] = false;
        }

        queue<int> q;

        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int f = q.front();
            cout<< f<<" " ;
            q.pop();

            for(auto it=adjList[f].begin();it!=adjList[f].end();it++){
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }

    }
    void bfs_dist(int src,int dest){
        int *dist  = new int[V];
        int *parent = new int[V];

        for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
            parent[i] = -1;
        }

        queue<int> q;

        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            int f = q.front();
            //cout<< f<<" " ;
            q.pop();

            for(auto it=adjList[f].begin();it!=adjList[f].end();it++){
                if(dist[*it]==INT_MAX){
                    dist[*it] = dist[f] + 1;
                    parent[*it] = f;
                    q.push(*it);
                }
            }

        }
          /*Shortest distances
            for(int i=0;i<V;i++){
                cout<<"Node "<<i<<" Dist " <<dist[i]<<endl;
            }
        */
         int st = dest;
         while(parent[st]!=-1){
            cout<<st<<" <-- ";
            st = parent[st];
         }
         cout<<src<<endl;

    }


    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            /// auto OR list<int>::iterator
            for(auto it=adjList[i].begin();it!=adjList[i].end();it++){
                cout<< *it <<",";
            }

            cout<<endl;
        }
    }
};


int main(){
Graph g(5);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(1,2);
g.addEdge(3,2);
g.addEdge(2,4);

g.printAdjList();
g.bfs_dist(0,4);
return 0;
}
