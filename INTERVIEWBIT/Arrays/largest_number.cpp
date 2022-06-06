#include<bits/stdc++.h>
using namespace std;

bool mycompare(string a,string b){
    string c=a.append(b);
    string d=b.append(a);

    if(d.compare(c)<0)
    return true;
    return false;
}

string largestNumber(const vector<int> &A) {

    vector<string>v;
    for(int i=0;i<A.size();i++){
        string temp="";
        for(int j=A[i];j>0;j/=10){
            temp+=char(48+(j%10));
        }
        reverse(temp.begin(),temp.end());
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),mycompare);

    string ans="";

    for(int i=0;i<v.size();i++){
        ans+=v[i];
    }
    return ans;

}


int main(){

vector<int>v={3, 30, 34, 5, 9};

cout<<largestNumber(v);

return 0;
}
