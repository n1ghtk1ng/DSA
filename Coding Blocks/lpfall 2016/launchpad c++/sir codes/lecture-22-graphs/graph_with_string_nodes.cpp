#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    int V;
    map<T, list<T> > adjList;

public:
    Graph(int v){
        V = v;
    }
    void addEdge(T src,T dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void print(){
        for(auto it=adjList.begin();it!=adjList.end();it++){
            cout<< it->first <<"-->";
            for(auto itl = (it->second).begin();itl!= (it->second).end();itl++){
                cout<< *itl <<" , ";
            }
            cout<<endl;
        }
    }

    void BFS(T src){
        map<T,bool> visited;
        map<T,int> dist;
        for(auto it=adjList.begin();it!=adjList.end();it++){
                visited[it->first] = false;
                dist[it->first] = INT_MAX;
        }
        queue<T> q;
        q.push(src);
        dist[src]=0;
        visited[src] = true;

        while(!q.empty()){
            T f = q.front();
            q.pop();
            cout<<f <<" ";

            for( auto it=adjList[f].begin();it!=adjList[f].end();it++){
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                    dist[*it] = dist[f] + 1;
                }
            }
        }
        ///Print the Distance
        cout<<"Distance of following Cities from "<<src<<" is "<<endl;
        for(auto it = dist.begin();it!=dist.end();it++){
            cout<<it->first<<" - " <<it->second<<endl;

        }


    }

};


int main(){

    Graph<string> g(5);
    g.addEdge("Delhi","Gurgaon");
    g.addEdge("Delhi","Sonepat");
    g.addEdge("Delhi","Noida");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Delhi","Bhopal");

    g.addEdge("Noida","Gurgaon");
    g.addEdge("Bhopal","Gurgaon");
    g.addEdge("Sonepat","Jaipur");
    //g.print();
    cout<<"BFS of Cities "<<endl;
    g.BFS("Sonepat");

    Graph<int> gi(3);
    gi.addEdge(1,100);
    gi.addEdge(100,1000);

   // gi.print();

return 0;
}
