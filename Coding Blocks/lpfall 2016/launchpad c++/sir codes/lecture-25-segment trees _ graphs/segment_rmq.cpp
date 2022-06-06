#include<iostream>
#include<climits>
using namespace std;

int query(int *stree,int ss,int se,int qs,int qe,int index){

///Complete Overlap
    if(ss>=qs && se<=qe){
        return stree[index];
    }
    ///No Overlap
    if(se<qs || ss>qe){
        return INT_MAX;
    }
    int mid = (ss+se)/2;
    int left_ans = query(stree,ss,mid,qs,qe,2*index+1);
    int right_ans = query(stree,mid+1,se,qs,qe,2*index+2);
    return min(left_ans,right_ans);
}

int buildTreeHelper(int *arr,int *stree,int start,int end,int index){
    ///Base Case
        if(start==end){
            stree[index] = arr[start];
            return arr[start];
        }

    ///Recursive Case
    int mid = (start+end)/2;
    int left_value = buildTreeHelper(arr,stree,start,mid,index*2+1);
    int right_value = buildTreeHelper(arr,stree,mid+1,end,index*2+2);
    stree[index]= min(left_value,right_value);
    return stree[index];


}

int*buildTree(int *arr,int n){

    int *stree = new int[4*n+1];
    buildTreeHelper(arr,stree,0,n-1,0);

    return stree;

}

int main(){

    int a[]  = {4,3,6,5,1,7};
    int *stree = buildTree(a,6);

    int q = 5;
    while(q--){
        int qs,qe;
        cin>>qs>>qe;
        cout<<query(stree,0,5,qs,qe,0)<<endl;
    }

return 0;
}
