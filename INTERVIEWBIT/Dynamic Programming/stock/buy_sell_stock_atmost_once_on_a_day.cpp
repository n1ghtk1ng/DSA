#include<bits/stdc++.h>
using namespace std;

int maxProfit(const vector<int> &arr) {

    int n=arr.size();

    if(n==0)
        return 0;
    int ans=0;

    for(int i=0;i<n;i++){
//        cout<<"ans = "<<ans<<endl;
        while(i<n-1 && arr[i]>=arr[i+1]){ // here take care to include equality case as well
            i++;
        }
        if(i==n-1){
            return ans;
        }
        ans-=arr[i];
//        cout<<"ans = "<<ans<<endl;
        i++;
        while(i<n && arr[i]>=arr[i-1]){ // here take care to include equality case as well
            i++;
        }
        ans+=arr[i-1];
//        cout<<"ans = "<<ans<<endl;

        i-=2; // we can start another transaction on same day but only if we complete previous transaction
    }

    return ans;

}



int main(){

vector<int>v={100, 180, 260, 310, 40, 535, 695};

cout<<maxProfit(v);

return 0;
}
