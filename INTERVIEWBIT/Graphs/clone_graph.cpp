#include<bits/stdc++.h>
using namespace std;
//  Definition for undirected graph.
  struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

UndirectedGraphNode *fun(UndirectedGraphNode *node,unordered_map<int,UndirectedGraphNode *>&m){
    if(m[node->label]){
        return m[node->label];
    }

    UndirectedGraphNode* src=new UndirectedGraphNode(node->label);
    m[node->label]=src;

    for(int i=0;i<node->neighbors.size();i++)
    src->neighbors.push_back(fun(node->neighbors[i],m));

    return src;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int,UndirectedGraphNode *>m;
    return fun(node,m);
}

int main(){

UndirectedGraphNode*a=new UndirectedGraphNode(1);
UndirectedGraphNode*b=new UndirectedGraphNode(2);
UndirectedGraphNode*c=new UndirectedGraphNode(3);

a->neighbors.push_back(b);
a->neighbors.push_back(c);

UndirectedGraphNode*src=cloneGraph(a);



return 0;
}
