#include<bits/stdc++.h>
using namespace std;



int num(string s){
  int ans=0;
  for(int i=0;i<s.size();i++){
      ans=(ans*10)+(s[i]-'0');
  }
  return ans;
}
string fun(int num){
    string s="";
    for(int i=num;i>0;i/=10){
        int temp=i%10;
        s+=char(temp+48);
    }
    reverse(s.begin(),s.end());
    return s;
}

int evalRPN(vector<string> &A) {

    stack<string>s;
    int ans;
    for(int i=0;i<A.size();i++){
        string st=A[i];
//        cout<<"st = "<<st<<endl;
        if(st=="+"){
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();

                ans=num(s2)+num(s1);
//                cout<<"ans = "<<ans<<endl;
                s.push(fun(ans));
//                cout<<"hello "<<s.top()<<endl;

        }
        else if(st=="-"){
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();

                ans=num(s2)-num(s1);
//                                cout<<"ans = "<<ans<<endl;
                s.push(fun(ans));

        }
        else if(st=="*"){
               string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();
//                cout<<s1<<" "<<s2<<endl;

                 ans=num(s2)*num(s1);
//                                cout<<"ans = "<<ans<<endl;
                s.push(fun(ans));

        }
        else if(st=="/"){
                string s1=s.top();
                s.pop();
                string s2=s.top();
                s.pop();

                 ans=num(s2)/num(s1);
//                                cout<<"ansi = "<<ans<<endl;
                s.push(fun(ans));

        }
        else{
             s.push(st);
        }
//                cout<<"s.top = "<<s.top()<<endl;

    cout<<"ans = "<<ans<<endl;
    }
    return ans;
}

int main(){

vector<string>v={"-1", "-1", "1", "-2", "+", "*", "+", "-1", "2", "+", "-2", "-1", "*", "-1", "1", "-", "2", "-", "-1", "*", "-1", "1", "-2", "1", "1", "-2", "2", "2", "*", "*", "2", "+", "-2", "-2", "-", "*", "+", "1", "-", "1", "1", "-", "-2", "-1", "*", "*", "-", "*", "-", "*", "-", "-", "+", "-", "-"};
cout<<evalRPN(v);

return 0;
}
