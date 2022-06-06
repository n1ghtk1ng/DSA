#include<bits/stdc++.h>
using namespace std;

class el{
public:
    int a;
    int b;
    int c;
    int d;
    el(){}
    el(int A,int B,int C,int D){
        a=A;
        b=B;
        c=C;
        d=D;
    }
    bool operator<(const el &e)const{
        return a<e.a;
    } // required for map
    /*bool operator==(const el &e)const{
        return a<e.a;
    }*/ // require for unordered map

};
/*
class AlwaysZero {
    public:
    size_t operator()(el const& ) const {
        return 0;
    }
};// require for unordered map
*/
//unordered_map<el,bool,AlwaysZero>m;
map<el,bool>m;

bool fun(char* a,int i1,int j1,char* b,int i2,int j2){
//cout<<strlen(a)<<endl;
for(int i=i1;i<=j1;i++){
    cout<<a[i];
}
cout<<" ";

for(int i=i2;i<=j2;i++){
    cout<<b[i];
}
cout<<endl;
el x(i1,j1,i2,j2);

if(m.find(x)!=m.end())
    return m[x];

int n1=j1-i1+1;
int n2=j2-i2+1;

if(n1!=n2){
    return false;
}

if(n1==1){
    if(a[i1]==b[i2])
        return true;
    return false;
}
vector<int>arr(26,0);
//int arr[26]={0};
for(int i=i1;i<=j1;i++){
    arr[a[i]-'a']++;
}
for(int i=i2;i<=j2;i++){
    arr[b[i]-'a']--;
}
//for(int i=0;i<26;i++){
//    cout<<arr[i]<<" ";
//}
//cout<<endl;
for(int i=0;i<26;i++){
    if(arr[i]!=0)
        return false;
}
//cout<<"hi"<<endl;

for(int i=1;i<n1;i++){
    bool b1=fun(a,i1,i1+i-1,b,i2,i2+i-1) && fun(a,i1+i,j1,b,i2+i,j2);
    if(b1==true){
        m[x]=true;
        return true;
    }

    bool b2=fun(a,i1,i1+i-1,b,j2-i+1,j2) && fun(a,i1+i,j1,b,i2,j2-i);
    if(b2==true){
        m[x]=true;
        return true;
    }

}
m[x]=false;
return false;


}

int main(){

char* a="abcde",*b="dbace";

if(fun(a,0,4,b,0,4)){
    cout<<"yup!!"<<endl;
}
else{
    cout<<"naah!!"<<endl;
}


return 0;
}
