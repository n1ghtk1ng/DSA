#include<bits/stdc++.h>
using namespace std;

int find_nearest(vector<int>&fibo,int sum){

int f=0,l=fibo.size()-1;
int ans;
while(f<=l){

    int mid=(f+l)/2;

    if(fibo[mid]<=sum){
        ans=fibo[mid];
        f=mid+1;
    }
    else{
        l=mid-1;
    }
}
return ans;

}

int fun(vector<int>&fibo,int sum){

if(sum==0)
    return 0;

int t=find_nearest(fibo,sum);
//cout<<"t = "<<t<<endl;
return 1+fun(fibo,sum-t);

}

int fibsum(int A) {
    if(A<=0)
    return 0;

    vector<int>fibo;
    fibo.push_back(1);
    fibo.push_back(1);


    while(fibo[fibo.size()-1]<A){
        fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
    }
    if(fibo[fibo.size()-1]>A)
        fibo.pop_back();

    for(int i=0;i<fibo.size();i++)
    cout<<fibo[i]<<" ";
    cout<<endl;
    return fun(fibo,A);

}

int main(){
int A=7;
cout<<fibsum(A);
return 0;
}
