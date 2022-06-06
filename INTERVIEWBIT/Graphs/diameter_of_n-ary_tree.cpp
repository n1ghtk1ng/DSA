#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>


pii diameter(unordered_map<int,vector<int> >&tree,int root){

pii temp;
if(tree[root].size()==0){
    temp.first=0;  // diameter
    temp.second=0; // height
    return temp;
}

int height1=0;
int height2=0;

int dia=0;

for(int i=0;i<tree[root].size();i++){
    pii t=diameter(tree,tree[root][i]);
    if(height1<1+t.second){
        height2=height1;
        height1=1+t.second;
    }
    else if(height2<1+t.second){
        height2=1+t.second;
    }
    dia=max(dia,t.first);
}
//cout<<"node = "<<root<<" height1 = "<<height1<<" height2 = "<<height2<<endl;
temp.second=height1;
temp.first=max(dia,height1+height2);
return temp;

}


int solve(vector<int> &A) {

unordered_map<int,vector<int> >tree;
int root;
for(int i=0;i<A.size();i++){
    if(A[i]==-1){
        root=i;
    }
    else
    tree[A[i]].push_back(i);
}
return diameter(tree,root).first;

}



int main(){

vector<int>A={-1, 0, 0, 1, 2, 1, 5};
cout<<solve(A);

return 0;
}
