#include<iostream>
#include<stack>
using namespace std;

bool isBalancedParanthesis(char *a){

    stack<char> s;

    for(int i=0;a[i]!='\0';i++){
        char ch = a[i];
        switch(ch){
            case '[':
            case '(':
            case '{': s.push(ch);
                        break;
            case ']': if(!s.empty()&&s.top()=='['){
                        s.pop();
                      }
                      else{
                        return false;
                      }
                      break;
            case ')': if(!s.empty() && s.top()=='('){
                            s.pop();
                      }
                      else{
                        return false;
                      }
                      break;
            case '}' : if(!s.empty()&&s.top()=='{'){
                            s.pop();
                        }
                        else{
                            return false;
                        }
                        break;

        }

    }
       if(s.empty()){
            return true;

        }
        else{
            return false;
        }



}

int main(){

char a[100] = "{a+b+[c+d]-(e*f)}";
if(isBalancedParanthesis(a)){
    cout<<"YES its balanced";
}
else{
    cout<<"Not Balanced";
}
return 0;
}
