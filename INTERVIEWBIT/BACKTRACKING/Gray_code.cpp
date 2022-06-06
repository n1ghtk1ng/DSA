#include<bits/stdc++.h>
using namespace std;

///backtracking approach-->
void fun(vector<int>&ans,int n,int i){

if(i==0){
    ans.push_back(n);
    return;
}
fun(ans,n,i-1);
n=n^(1<<(i-1));
fun(ans,n,i-1);

}


int main(){

int n=4;

//vector<int>ans((1<<n),0);
//
//int total_cnt=1<<n;
//
//for(int i=1;i<=n;i++){
//
//bool a=true,b=true;
//
//int cnt=0,j=0;
//
//while(cnt<total_cnt){
//    if(a==false){
//        for(j=0;j<(1<<(n-i));j++){
//            ans[cnt]=ans[cnt]^((1<<(n-i)));
//            cnt++;
//        }
//    }
//
//    else{
//        for(j=0;j<(1<<(n-i));j++){
//            ans[cnt]=ans[cnt]^0;
//            cnt++;
//        }
//    }
//    a=!a;
//
//    if(b==true){
//        for(j=0;j<(1<<(n-i));j++){
//            ans[cnt]=ans[cnt]^((1<<(n-i)));
//            cnt++;
//        }
//    }
//
//    else{
//        for(j=0;j<(1<<(n-i));j++){
//            ans[cnt]=ans[cnt]^0;
//            cnt++;
//        }
//    }
//    b=!b;
//}
//}
vector<int>ans;
fun(ans,0,n);
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
}


return 0;
}
