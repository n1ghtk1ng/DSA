#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adjList;
public:
    Graph(int v){
        V=v;
        adjList = new list<int>[V];
    }
    void addEdge(int src,int dest,bool bidir=true){
        if(bidir){
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        else{
            adjList[src].push_back(dest);
        }
    }
    void DFSHelper(int src,bool *visited){

        visited[src]=true;
        cout<< src <<endl;

        for(auto it=adjList[src].begin();it!=adjList[src].end();it++){
            if(!visited[*it]){
                DFSHelper(*it,visited);
            }
        }
        return;
    }

    void DFS(){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]= false;
        }
        ///We need to call the helper function
        //DFSHelper(0,visited);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                cout<<"Component "<<endl;
                DFSHelper(i,visited);
            }

        }
    }

};



int main(){
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(6,7);

    g.DFS();




}
