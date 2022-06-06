#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

class mycompare{
public:
    bool operator()(pii p1,pii p2){
        return p1.second>p2.second;
    }
};

int prims(int nodes, int **adj){

int src=1;
//int parent[nodes+1];
int value[nodes+1];
bool vis[nodes+1];

for(int i=1;i<=nodes;i++){
//    parent[i]=-1;
    value[i]=INT_MAX;
    vis[i]=false;
}
//parent[1]=0;
value[1]=0;

priority_queue<pii,vector<pii>,mycompare>q;
q.push(make_pair(src,0));
//cout<<"hi "<<endl;
while(!q.empty()){
    pii p=q.top();
    q.pop();

    int node=p.first;
    int val=p.second;

    if(value[node]<val){
        continue;
    }
    vis[node]=true;
//    cout<<"node = "<<node<<endl;

    for(int i=1;i<=nodes;i++){
        if(adj[node][i] && value[i]>adj[node][i] && !vis[i]){
//            parent[i]=node;
            value[i]=adj[node][i];
            q.push(make_pair(i,value[i]));
        }
    }
}
int ans=0;
for(int i=1;i<=nodes;i++){
//    cout<<i<<" --- "<<parent[i]<<" "<<value[i]<<endl;
ans+=value[i];
}

return ans;
}


int solve(int A, vector<vector<int> > &B) {
    int n=A;
    int **arr=new int*[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=new int[n+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<B.size();i++){
        int a=B[i][0];
        int b=B[i][1];
        int c=B[i][2];
        arr[a][b]=arr[b][a]=c;
    }

    return prims(A,arr);
}


int main(){

int A=4;
vector<vector<int> >B={
{
    1,2,1
},
{
    2,3,4
},
{
    1,4,3
},
{
    4,3,2
},
{
    1,3,10
}
};

cout<<solve(A,B);

return 0;
}
