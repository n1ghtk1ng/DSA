#include<bits/stdc++.h>
using namespace std;

int n;

int fun(vector<int>&v){
n=v.size();

stack<int>s;


int i,t;
int maxarea=INT_MIN;
for(i=0;i<n;i++){
    if(s.empty()){
        s.push(i);
    }
    else{
        t=s.top();
        if(v[i]>=v[t]){
            s.push(i);
        }
        else{
            while(!s.empty() && v[s.top()]>v[i]){
                t=s.top();
                s.pop();
//                cout<<"v[t] = "<<v[t]<<" ";
                if(s.empty()){
                    maxarea=max(maxarea,v[t]*(i));
                }
                else{
                    maxarea=max(maxarea,v[t]*(i-s.top()-1));
                }
            }
            s.push(i);
        }
    }
//    cout<<"maxarea = "<<maxarea<<endl;
}
            while(!s.empty()){
                t=s.top();
                s.pop();
//                cout<<"t = "<<t<<endl;
                if(s.empty()){
                    maxarea=max(maxarea,v[t]*(i));
                }
                else{
                    maxarea=max(maxarea,v[t]*(i-s.top()-1));
                }
//                cout<<"maxarea = "<<maxarea<<endl;

            }



return maxarea;
}



int main(){

vector<int>v={2,1,2,3,1};

cout<<fun(v);




return 0;
}

