#include<iostream>
#include<list>
#include<queue>
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
           for(auto it=adjList[i].begin();it!=adjList[i].end();it++){
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


};


int main(){
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    Graph g(50);
    for(int i=1;i<36;i++){

        for(int move=1;move<=6;move++){
            int dest = i+move+ board[i+move];
            if(dest<=36){
                g.addEdge(i,dest,false);
            }
        }
    }
    g.shortestPath(1,36);



return 0;
}
