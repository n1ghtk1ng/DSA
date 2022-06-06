#include<iostream>
#include<list>
#include<queue>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
public:
    Graph(int v){
        V = v;
        adjList = new list<int>[V];
    }
    void addEdge(int x,int y,bool bidir = true){
        if(bidir){
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        else{
            adjList[x].push_back(y);
        }
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
           cout<<"Vertex "<<i<<" ->";
           for(list<int>::iterator it=adjList[i].begin();it!=adjList[i].end();it++){
                cout<< *it <<",";
           }
           cout<<endl;
        }
    }
    void BFSPrint(int src){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<< f <<" ";

            for(list<int>::iterator it=adjList[f].begin();it!=adjList[f].end();it++){
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it] = true;
                }
            }
        }
    }
    void shortestPath(int src,int dest){

        int *dist = new int[V];
        int *parent = new int[V];

        for(int i=0;i<V;i++){
            dist[i] = INT_MAX;
            parent[i] = -1;
        }

        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int f = q.front();
            q.pop();
            //cout<< f <<" ";

            for(list<int>::iterator it=adjList[f].begin();it!=adjList[f].end();it++){
                if(dist[*it]==INT_MAX){
                    q.push(*it);
                    dist[*it] = dist[f]+1;
                    parent[*it] = f;
                }
            }
        }
        cout<<"Distance btw "<<src<<" and "<<dest<<" is "<<dist[dest]<<endl;
        cout<<endl;
        int start = dest;
        cout<<dest<<"<--";
        while(start!=src){
            cout<<parent[start]<<"<--";
            start = parent[start];
        }
    }
    /*void topologicalSort(){
        int *indegree = new int[V];
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }
        for(int i=0;i<V;i++){
            for(auto it=adjList[i].begin();it!=adjList[i].end();it++){
                indegree[*it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for(auto it=adjList[f].begin();it!=adjList[f].end();it++){
                indegree[*it]--;
                if(indegree[*it]==0){
                    q.push(*it);
                }
            }
        }

    }
*/
};


int main(){
    Graph  g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,0);
    g.addEdge(4,5);
    g.addEdge(2,5);
    g.printAdjList();
    g.BFSPrint(0);
    g.shortestPath(0,5);
    g.shortestPath(4,1);

    ///Dag
    /*Graph dg(6);
    dg.addEdge(0,2,false);
    dg.addEdge(0,3,false);
    dg.addEdge(1,5,false);
    dg.addEdge(2,4,false);
    dg.addEdge(3,4,false);
    dg.addEdge(1,3,false);
    dg.addEdge(1,2,false);

  //  dg.topologicalSort();
*/


}
