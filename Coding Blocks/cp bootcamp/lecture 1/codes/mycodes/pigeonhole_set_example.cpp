#include<bits/stdc++.h>
using namespace std;
#define N (1e6+10)
vector<int> pos(N, -1);
vector<int> v;
vector<int> pre;
int main(){
int t,n,x,l = 0,r = 0;
scanf("%d",&t);
while(t--){
scanf("%d",&n);
for(int i = 0;i<n;i++){
scanf("%d",&x);
v.push_back(x % n);
}
//Pre vector denotes the prefix sum bi
pre.push_back(0);
for(int i = 0;i<n;i++)
pre.push_back((pre[i] + v[i]) % n);
//Position vector denotes the index of
//each segment sum
for(int i = 0;i<n+1;i++){
//If this segement sum is encountered first time
if(pos[pre[i]] == -1){
pos[pre[i]] = i;
}
//If this segment sum has already been encountered
//we have our answer.
//L will be its previous index and R current index
else{
//pos[pre[i]] will give L-1
l = pos[pre[i]] + 1;
r = i;
break;
}
}
//Number of elements in the segment
//is (R-L+1)
printf("%d\n",r - l + 1);
//Print the index between l and r
for(int i = l;i<=r;i++)
printf("%d ",i);printf("\n");
v.clear();
pre.clear();
for(int i = 0;i<=n;i++)pos[i] = -1;
}
return 0;
}
