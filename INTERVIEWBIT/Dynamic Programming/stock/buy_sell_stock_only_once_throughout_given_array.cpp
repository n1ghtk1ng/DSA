int Solution::maxProfit(const vector<int> &A) {

    int n=A.size();

    if(n==0)
        return 0;

    int gmax=0;
    int gmin=0;

    int ans=0;

    for(int i=1;i<n;i++){
        if(A[i]>A[gmax]){
            gmax=i;
        }
        if(A[i]<A[gmin]){
            gmin=i;
        }
        if(gmin>gmax){
            gmax=gmin;
        }
        ans=max(ans,A[gmax]-A[gmin]);
    }

    return ans;

}

