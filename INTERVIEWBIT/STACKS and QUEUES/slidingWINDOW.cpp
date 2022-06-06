#include<bits/stdc++.h>
using namespace std;

vector<int>slidingMaximum(const vector<int> &A, int B) {
vector<int>v;
deque<int>q;
    int i;
    for(i=0;i<B;i++){
        while(!q.empty() && A[i]>=A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }

    for(;i<A.size();i++){
        v.push_back(A[q.front()]);
        while(!q.empty() && q.front()<=i-B){
            q.pop_front();
        }
        while(!q.empty() && A[i]>=A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    v.push_back(A[q.front()]);
    return v;

}


int main(){

vector<int>v={1, 3 ,-1 ,-3 ,5 ,3 ,6 ,7};
int window=9;

vector<int>ans=slidingMaximum(v,window);

for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}

return 0;
}
