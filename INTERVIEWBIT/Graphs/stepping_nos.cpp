#include<bits/stdc++.h>
using namespace std;

vector<int>stepnum(int A, int B) {

priority_queue<int,vector<int>,greater<int> >pq;

for(int i=1;i<=9;i++){
    pq.push(i);
}
vector<int>ans;
if(A==0)
    ans.push_back(0);

while(!pq.empty()){
    int t=pq.top();
    pq.pop();

    if(t>=A){
        ans.push_back(t);
    }
    int lastdigit=t%10;

    int n1=t*10 + lastdigit-1;
    int n2=t*10 + lastdigit+1;

//    cout<<"t = "<<t<<" n1 = "<<n1<<" n2 = "<<n2<<endl;

    if(n1<=B && lastdigit!=0)
    pq.push(n1);

    if(lastdigit!=9 && n2<=B){
        pq.push(n2);
    }
}
return ans;
}


int main(){

vector<int>v=stepnum(15,99);

for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}


return 0;
}
