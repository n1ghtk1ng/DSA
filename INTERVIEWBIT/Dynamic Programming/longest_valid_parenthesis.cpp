#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string A) {

    stack<int>s;

    vector<bool>dp(A.size(),false);

    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            s.push(i);
        }
        else{
            if(!s.empty()){
                int t=s.top();
                s.pop();
                dp[t]=true;
                dp[i]=true;
            }
        }
    }
    int ans=0;
    for(int i=0;i<A.size();i++){
        if(dp[i]==true){
            int temp=0;
            while(i<A.size() && dp[i]==true){
                temp++;
                i++;
            }
            ans=max(ans,temp);
        }
    }
    return ans;
}


int longestValidParentheses_without_array(string A){

    stack<int>s;
    int ans=0;
    s.push(-1);

    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            s.push(i);
        }
        else{
            s.pop();
            if(!s.empty()){

                ans=max(ans,i-s.top());
            }
            else{
                s.push(i);
            }
        }
    }
return ans;

}

int main(){

cout<<longestValidParentheses(")()())");
cout<<longestValidParentheses_without_array(")()())");

}
