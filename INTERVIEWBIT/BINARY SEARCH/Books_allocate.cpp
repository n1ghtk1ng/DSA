#include<bits/stdc++.h>
using namespace std;

int check(vector<int>&arr,int n,int upperlimit,int k){

    int cnt=1;
    int currsum=0;
    for(int i=0;i<n;i++){
        if(currsum+arr[i]>upperlimit){
            currsum=arr[i];
            cnt++;
//        cout<<"upperlimit = "<<upperlimit<<" cnt = "<<cnt<<endl;
            if(cnt>k){
                return 0;
            }
        }
        else{
            currsum+=arr[i];
        }
    }
    return 1;
}

int fun(vector<int>&arr,int n,int k){

int f=INT_MIN;
int l=0;

for(int i=0;i<n;i++){
    f=max(f,arr[i]);
    l+=arr[i];
}
int ans;
while(f<=l){
    int mid=(f+l)/2;
//    cout<<"mid = "<<mid<<" f = "<<f<<" l = "<<l<<endl;
    if(check(arr,n,mid,k)){
        ans=mid;
        l=mid-1;
    }
    else{

        f=mid+1;
    }
}
return ans;

}


int main(){

int arr[]={10,20,30,40};
int n=sizeof(arr)/sizeof(int);
int k=2;

cout<<fun(arr,n,k);

return 0;
}
