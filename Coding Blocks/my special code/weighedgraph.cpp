#include<iostream>
#include<list>
#include<queue>
#include<map>

using namespace std;
template<typename T>

class graph{

private:
    int V;
    map<T,list< pair<T,int> > >mymap;

public:
    graph(int v)
    {
        V=v;
    }

    void addedge(T src,T destn,int w)
    {
        pair<T,int>p1(destn,w);
        pair<T,int>p2(src,w);
        mymap[src].push_back(p1);
        mymap[destn].push_back(p2);
    }
    void print()
    {
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            cout<<it->first<<"--->>>";
            for(auto i=it->second.begin();i!=it->second.end();i++)
            {
                cout<<i->first<<","<<i->second<<"--";
            }
            cout<<endl;
        }

    }

    void bfsprint(T src)
    {
        map<T,bool>boolmap;

        for(auto i=mymap.begin();i!=mymap.end();i++)
        {
           boolmap[i->first]=false;
        }

        queue<T>q;

        q.push(src);

        while(!q.empty())
        {
            T temp=q.front();
            q.pop();

            cout<<temp<<" ";
            for(auto it=mymap[temp].begin();it!=mymap[temp].end();it++)
            {

                if(!boolmap[it->first])
                {
                    q.push(it->first);
                    boolmap[it->first]=true;
                }
            }
        }

    }
void dfshelp(T data,map<T,bool>&visited)
{

        visited[data]=true;
        cout<<data<<" ";
    for(auto it=mymap[data].begin();it!=mymap[data].end();it++)
    {
        if(!visited[it->first])
            dfshelp(it->first,visited);
    }
return ;

}

void dfsprint()
{

    map<T,bool>visited;
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        visited[it->first]=false;
    }
    for(auto it=mymap.begin();it!=mymap.end();it++)
    {
        if(!visited[it->first])
        {
            dfshelp(it->first,visited);
        }
    }

}



};

int main()
{
    graph<string>g(5);
  //  g.addedge("Delhi","bahadurgarh");
    g.addedge("Delhi","bahadurgarh",100);
    g.addedge("Delhi","Sonepat",20);
    g.addedge("Delhi","Noida",30);
    g.addedge("Delhi","Jaipur",40);
    g.addedge("Delhi","Bhopal",50);

    g.addedge("Noida","bahadurgarh",60);
    g.addedge("Bhopal","bahadurgarh",70);
    g.addedge("Sonepat","Jaipur",80);

    g.print();
    cout<<endl;
    //g.bfsprint("Delhi");
    g.bfsprint("Delhi");
    cout<<endl;
    g.dfsprint();

vector<vector<int>>v;
}
