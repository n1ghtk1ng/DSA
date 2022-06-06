#include<iostream>
using namespace std;

int lazy[1000] = {0};

int query(int *tree,int ss,int se,int qs,int qe,int index){
    ///Complete Overlap
    if( ss>=qs && se<= qe){
        return tree[index];
    }
    ///No Overlap
    if( qe < ss || qs > se){
        return INT_MAX;
    }
    ///Partial Overlap
    int mid = (ss+se)/2;
    int leftAns = query(tree,ss,mid,qs,qe,2*index);
    int rightAns = query(tree,mid+1,se,qs,qe,2*index+1);

    return min(leftAns,rightAns);
}
void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index){
    ///First Task - To Make Pending Updates
    if(lazy[index]!=0){
            tree[index] += lazy[index];

            if(ss!=se){
                lazy[2*index] += lazy[index];
                lazy[2*index+1] += lazy[index];

            }
            lazy[index] = 0;
    }
    ///No Overlap
    if(r<ss || l>se){
        return;
    }
    ///Complete OverLap
    if(ss>=l && se<=r){
        tree[index] += inc;
        if(ss!=se){
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return;
    }
    ///Partial Overlap
    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

int queryLazy(int tree[],int ss,int se,int qs,int qe,int index){
    if(lazy[index]!=0){
            tree[index] += lazy[index];

            if(ss!=se){
                lazy[2*index] += lazy[index];
                lazy[2*index+1] += lazy[index];

            }
            lazy[index]=0;
    }
    ///No Overlap
    if(ss>qe || se<qs){
        return INT_MAX;
    }
    ///Complete Overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    ///Partial Overlap
    int mid = (ss+se)/2;
    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}



int buildTreeHelper(int a[],int s,int e,int *tree,int index){
    ///Base Case
    if(s==e){
            tree[index] = a[s];
            return a[s];
    }
    ///Rec Case
    int mid = (s+e)/2;
    int left = buildTreeHelper(a,s,mid,tree,2*index);
    int right = buildTreeHelper(a,mid+1,e,tree,2*index+1);

    tree[index] = min(left,right);
    return tree[index];
}
void updateNode(int tree[],int ss,int se,int i,int inc,int index){
    /// No Overlap
    if(i>se || i<ss){
        return;
    }
    ///Leaf Node
    if(ss==se){
        tree[index] += inc;
        return;
    }
    ///Otherwise
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,inc,2*index);
    updateNode(tree,mid+1,se,i,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}
void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){
    ///No Overlap
    if(l>se || r<ss){
        return;
    }
    ///Leaf Node
    if(ss==se){
        tree[index] += inc;
        return;
    }
    ///Partial Overlap
    int mid = (ss+se)/2;
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index+1],tree[2*index]);
    return;
}

int* buildTree(int a[],int n){
    int *segmentTree = new int[4*n+1];
    buildTreeHelper(a,0,n-1,segmentTree,1);

    return segmentTree;

}

int main(){
    int a[] = {1,2,0,4,3,5};

    int t,qs,qe,i,inc;
    char ch;
    cin>>t;

    int*tree = buildTree(a,6);
    int l,r;
    while(t--){
        cin>>ch;
        if(ch=='Q'){
            cin>>qs>>qe;
            cout<<"Ans is "<<queryLazy(tree,0,5,qs,qe,1);
            cout<<endl;
        }
        else{
            cin>>l>>r>>inc;
            updateRangeLazy(tree,0,5,l,r,inc,1);
        }
    }
return 0;
}
