#include<iostream>
#include<stack>
using namespace std;

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}


int main(){

    stack<char> s;
    char a[] = "a+b*(c^d-e)^(f+g*h)-i";
    for(int i=0;a[i]!='\0';i++){

        if(a[i]>='a'&&a[i]<='z'){
            cout<<a[i];
        }
        else if(a[i]=='('){
            s.push('(');
        }
        else if(a[i]==')'){
                while(!s.empty()&&s.top()!='('){
                        cout<<s.top();
                        s.pop();
                      }
                      s.pop();
        }
        else{
            if(s.empty()||Prec(a[i])>=Prec(s.top())){
                s.push(a[i]);
            }
            else{
                while(!s.empty()&&Prec(s.top())>=Prec(a[i])){
                    cout<<s.top();
                    s.pop();
                }
                s.push(a[i]);
            }

        }



    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    return 0;
}
