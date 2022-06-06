#include<bits/stdc++.h>
using namespace std;

vector<int>lis(vector<int>&A){

vector<int>a(A.size(),1);

for(int i=0;i<A.size();i++){
    for(int j=0;j<i;j++){
        if(A[i]>A[j] && a[i]<1+a[j]){
            a[i]=1+a[j];
        }
    }
}
return a;
}

vector<int>lis_reverse(vector<int>&A){

vector<int>a(A.size(),1);

for(int i=A.size()-1;i>=0;i--){
    for(int j=A.size()-1;j>i;j--){
        if(A[i]>A[j] && a[i]<1+a[j]){
            a[i]=1+a[j];
        }
    }
}
return a;
}


int fun(vector<int>&A){

vector<int>a=lis(A);
vector<int>b=lis_reverse(A);
int ans=1;
for(int i=0;i<A.size();i++){
    ans=max(ans,a[i]+b[i]-1);
}
return ans;

}

int main(){
vector<int>v={1,11,2,10,4,5,2,1};
cout<<fun(v);

return 0;
}
