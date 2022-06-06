#include<iostream>
using namespace std;

int first7(int a[],int n,int i){

    if(i==n){
        return -1;
    }

    if(a[i]==7){
        return i;
    }

    int indexInRem= first7(a,n,i+1);

    return indexInRem;

}


int last7(int a[],int n,int i){

    if(i==n){
        return -1;
    }


    int indexInRem = last7(a,n,i+1);
    if(indexInRem==-1){
            if(a[i]==7){
                return i;
            }
            else{
                return -1;
            }

    }
    else{
        return indexInRem;
    }


}

int lastseven(int a[],int n){
if(n==0)
    return -1;
if(a[n-1]==7)
    return n-1;

   int ans=lastseven(a,n-1);
    return ans;
}

void allseven(int a[],int n){
if(n==0)
    return;
if(a[n-1]==7)
    cout<<n-1<<" ";

    allseven(a,n-1);

}

int main(){
    int a[] = {1,2,3,6,7,5,4,7,8};
    int ans = first7(a,9,0);
    if(ans!=-1){
        cout<<"Fount at index "<<ans<<endl;
    }
    else{
        cout<<"Not found !";
    }
    //allseven(a,9);
    cout<<lastseven(a,9);
    return 0;
}
