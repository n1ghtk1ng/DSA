#include<bits/stdc++.h>
using namespace std;


int fun(int a[],int b[],int n1,int n2,int k){

if(k<1 || k>n1+n2) return -1;

if(n1>n2) return fun(b,a,n2,n1,k);

if(n1==0) return b[k-1];

if(k==1) return min(a[0],b[0]);

int i=min(n1,k/2),j=min(n2,k/2);

if(a[i-1]>b[j-1]){
    return fun(a,b+j,n1,n2-j,k-j);
}
else{
    return fun(a+i,b,n1-i,n2,k-i);
}
}

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{

    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];

    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;

    if (mid1 + mid2 < k)
    {

        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int main(){

int a[]={1,4,7,9};
int b[]={2,5,6,10};

for(int i=1;i<=8;i++){
    cout<<fun(a,b,4,4,i)<<" "<<kth(a,b,a+4,b+4,i-1)<<endl;
}


return 0;
}
