#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){

    int a[] = {5,4,3,1,2};
    string s[] = {"Apple","Ape","Aloo","Aam","aam"};
    vector<int> v;
    vector<string> vs;

    for(int i=0;i<5;i++){
        //cout<<a[i]<<" ";
        v.push_back(a[i]);
        vs.push_back(s[i]);
        //vs.push_back(s[i]);
    }

    sort(v.begin(),v.end());
    sort(vs.begin(),vs.end());

    for(int i=0;i<5;i++){
        //cout<<v[i]<<" ";
        cout<< vs[i] <<endl;
    }




return 0;
}
