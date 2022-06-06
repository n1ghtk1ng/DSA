#include<bits/stdc++.h>
using namespace std;


void fun(int *arr,string s){
    int i=1,j=0;
    arr[0]=0;

    while(i<s.size()){
        if(s[j]==s[i]){
            j++;
            arr[i]=j;
            i++;
        }
        else{
            if(j-1>=0){
                j=arr[j-1];
            }
            else{
                arr[i]=0;
                i++;
            }
        }
    }
}

int main(){
int t;
cin>>t;

while(t--){
    string a,b;
    cin>>a>>b;
    string temp=b;
    b+=temp;

    int idx[a.size()+1];
    fun(idx,a);

    int cnt=0,i=0,j=0;
    while(i<b.size()-1){
        if(b[i]==a[j]){
            i++;
            j++;
        }
        if(j==a.size()){
            cnt++;
            j=idx[j-1];
        }
        if(b[i]!=a[j]){
            if(j!=0){
                j=idx[j-1];
            }
            else{
                i++;
            }
        }
    }

cout<<cnt<<endl;


}

return 0;
}
