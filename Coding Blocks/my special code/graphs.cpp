#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<climits>
using namespace std;
template<typename T>

class graph{
private:

    int V;
   map<T, list< pair<T,int> > >mymap;

public:
    graph(int v)
    {
        V=v;
        //mylist=new list<T>[V];
    }

    void addedge(T x,T y,int w,bool b)
    {
        if(b==true)
      {
        pair<T,int> p1(x,w);
        pair<T,int> p2(y,w);
        mymap[x].push_back(p2);
        mymap[y].push_back(p1);
      }
      else
      {

        pair<T,int> p2(y,w);
        mymap[x].push_back(p2);
      }

    }
    void print()
    {
        for(auto i=mymap.begin();i!=mymap.end();i++)
        {
            cout<<i->first<<"-->";
            for(auto it=i->second.begin();it!=i->second.end();it++)
           {
            cout<<it->first<<" with weight "<<it->second<<"   ";
           }
           cout<<endl;
        }
    }
void bfsprint(T src,T destn)
{
    queue<T>q;
    map<T,bool>visited;
    map<T,int>distance;
    map<T,T>parent;
    T t;
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        visited[it->first]=false;
        distance[it->first]=INT_MAX;
        parent[it->first]=t;
    }
    q.push(src);
    visited[src]=true;
    distance[src]=0;

    while(!q.empty())
    {
        T temp=q.front();
        q.pop();
        cout<<temp<<" ";

        for(auto it=mymap[temp].begin();it!=mymap[temp].end();it++)
        {
            if(!visited[it->first])
            {
                q.push(it->first);
                visited[it->first]=true;
                distance[it->first]=1+distance[temp];
                parent[it->first]=temp;
               // distance[it->first]+=1;
            }
        }
    }
    cout<<"distance of the following from "<<src<<endl;
    for(auto it=distance.begin();it!=distance.end();it++)
    {
        cout<<it->first<<"-->"<<it->second<<endl;
    }
    cout<<"min distance from "<<src<<"to "<<destn<<" is"<<distance[destn]<<endl;
    cout<<"Path is  ";
    T temp=destn;
    while(temp!=src)
    {
        cout<<parent[temp]<<"-->";
        temp=parent[temp];
    }

}

void dfshelper(map<T,bool>&visited,T src )
{
    cout<<src<<" ";
    visited[src]=true;

    for(auto it=mymap[src].begin();it!=mymap[src].end();it++)
    {
        if(!visited[it->first])
        {
          dfshelper(visited,it->first);
        }
    }
}

void dfsprint(T src)
{
    map<T, bool>visited;
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        visited[it->first]=false;
    }

    for(auto it=mymap[src].begin();it!=mymap[src].end();it++)
    {
        if(!visited[it->first])
        {
            dfshelper(visited,src);
            //visited[*it]=true;
        }
    }
}

void topologicalorder()
{
    map<T,int>x;
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        x[it->first]=0;
    }
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        for(auto i=it->second.begin();i!=it->second.end();i++)
        {
            x[i->first]++;
        }
    }
    queue<T>q;
    for( auto it=mymap.begin();it!=mymap.end();it++)
    {
        if(x[it->first]==0)
        {
            q.push(it->first);
        }
    }

    while(!q.empty())
    {
        T temp=q.front();
        cout<<temp<<" ";
        q.pop();

        for(auto it=mymap[temp].begin();it!=mymap[temp].end();it++)
        {
            x[it->first]--;
            if(x[it->first]==0)
            {
                q.push(it->first);
            }
        }
    }
}

};

int main()
{
    graph<int> g(5);
    g.addedge(1,2,100,false);
    g.addedge(1,3,90,false);
    g.addedge(2,4,80,false);
    g.addedge(2,0,70,false);
    g.addedge(3,4,60,false);
    g.addedge(3,0,50,false);
    //g.addedge(3,9,10,false);
   // g.addedge(9,10,10,false);
  //  g.print();
    //g.bfsprint(2,10);
    //cout<<endl;
//    g.dfsprint(1);

g.topologicalorder();
}
