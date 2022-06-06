#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
vector<int>twoSum(const vector<int> &a, int B) {

    unordered_map<int,pii>m;
    pii ans=make_pair(a.size(),a.size());
    for(int i=0;i<a.size();i++){
        m[a[i]]=make_pair(-1,0);
    }
    for(int i=0;i<a.size();i++){
        if(m[a[i]].first==-1)
        m[a[i]]=make_pair(i,1);
        else{
            m[a[i]]=make_pair(m[a[i]].first,1+m[a[i]].second);
        }
    }
    for(int i=0;i<a.size();i++){
        int q=a[i];

        int req=B-q;
        pii temp=make_pair(-1,-1);
        pii temp1=make_pair(-1,-1);
//        cout<<"req = "<<req<<endl;
        if(req==q){
            if(m[req].second>=2){
                int c=min(i,m[req].first);
                int d=max(i,m[req].first);
                if(c==d)
                    continue;
                temp=make_pair(c,d);
//                cout<<"temp = "<<temp.first<<" "<<temp.second<<endl;
            }
        }
        else{
            if(m[req].second>=1){
                int c=min(i,m[req].first);
                int d=max(i,m[req].first);
                temp=make_pair(c,d);
//                cout<<"temp = "<<temp.first<<" "<<temp.second<<endl;
            }
        }
        if(temp!=temp1){
            if(ans.second>temp.second){
            ans=temp;
        }
        else if(ans.second==temp.second){
            if(ans.first>temp.first){
                ans=temp;
            }
        }
        }

//        cout<<"ans = "<<ans.first<<" "<<ans.second<<endl;
    }
    vector<int>qw;
    if(ans.first==ans.second && ans.first==a.size())
    return qw;

    qw.push_back(ans.first);
    qw.push_back(ans.second);
    return qw;

}

///solution 2
/*
vector<int> twoSum(const vector<int> &num, int target) {

            // map to store the mapping from number to its index.
                        map<int, int> M;
            vector<int> ans;

            for (int i = 0; i < num.size(); i++) {
                int required = target - num[i];
                if (M.find(required) != M.end()) {
                    // We have our solution. index1 = M[required], index2 = i + 1 ( 1 based ).
                    ans.push_back(M[required]);
                    ans.push_back(i + 1);
                    return ans;
                }
                if (M.find(num[i]) == M.end()) {
                    // We want to maintain the minimum index at M[num[i]]. i + 1 will
                    // obviously be greater than whats already present.
                    M[num[i]] = i + 1;
                }
            }
            return ans;
        }
*/

int main(){

vector<int>v={-10,-10,-10};
int sum=5;

vector<int>ans=twoSum(v,sum);
cout<<ans[0]<<" "<<ans[1]<<endl;

return 0;
}
