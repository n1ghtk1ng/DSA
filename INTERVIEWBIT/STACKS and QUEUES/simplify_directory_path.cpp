#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string A) {
    stack<string>s;

    string ans="";
    for(int i=0;i<A.size();i++){
        string temp="";
        if(A[i]=='/'){
            continue;
        }
        if(A[i]=='.'){
            if(i+1<A.size() && A[i+1]=='.'){
                if(!s.empty())
                s.pop();
                i++;
            }
            continue;
        }
        while(i<A.size() && A[i]!='/'){
            temp+=A[i];
            i++;
        }
        cout<<"temp = "<<temp<<endl;
        s.push(temp);
    }
    if(s.empty()){
        return "/";
    }
    while(!s.empty()){
        string temp=s.top();
        reverse(temp.begin(),temp.end());
        ans+=temp;
        ans+='/';
        s.pop();

    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){

cout<<simplifyPath("/auc/././../zga/../oxk/./../yvm/./wxz/ngz/fri/adn/zym/rrb/wdb/gbp/msh/ujm/ygw/zac/rio/oye/wmg/oqp/../../.././kvo/./atn/./mky/xtf/xmw/zle/../wcm/ijz/xgb/txi/voa/kgt/rtn/../gqd/cuj/ejl/../../lwf/mhc/vpz/./ojl/oda/.././bsr/././jwd/ubt/ppn");

return 0;
}
