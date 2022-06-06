#include<bits/stdc++.h>
using namespace std;

int Solution::braces(string A) {
    stack<char>s;

    for(int i=0;i<A.size();i++){
        if(A[i]==')'){

            bool temp=false;
            char t;
            if(!s.empty())
                t=s.top();

            while(!s.empty() && t!='('){
                s.pop();
//                cout<<"t = "<<t<<" temp = "<<temp<<endl;
                if(t=='+' || t=='-' || t=='*' || t=='/'){
                    temp=true;
                }
                t=s.top();
            }
            if(!s.empty()){
                s.pop();
            }
            if(temp==false)
                return 1;
        }
        else{
            s.push(A[i]);
        }
    }return 0;

}


int main(){

cout<<braces("(a + b)");

return 0;
}
