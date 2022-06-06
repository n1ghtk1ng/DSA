#include<bits/stdc++.h>
using namespace std;


void fun2(vector<int>&ans,int A, vector<int> &B){

int mini=INT_MAX;
for(int i=0;i<B.size();i++){
    mini=min(B[i],mini);
}

int anslength=A/mini;
int j=0;
int power=A;

for(int i=1;i<=anslength;i++){
//    cout<<"power = "<<power<<" j = "<<j<<" i = "<<i<<endl;
    power-=B[j];
//    cout<<"power = "<<power<<endl;


    if(power>=0 && (power/mini)+i==anslength){
        ans.push_back(j);
//        cout<<"powers = "<<power<<endl;
        if(power==0)
            break;
    }
    else{
        power+=B[j];
        j++;
        i--;
    }
    if(ans.size()==anslength)
        break;
}

}

vector<int>Solution::solve(int A, vector<int> &B){

vector<int>ans;
fun2(ans,A,B);

return ans;

}

int main(){

int A=32;
vector<int>B={6,8,5,4,7};

vector<int>ans=fun(A,B);

for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}


return 0;
}
