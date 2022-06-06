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

int main(){
    int a[] = {1,2,3,6,7,5,4,7,8};
    int ans = first7(a,9,0);
    if(ans!=-1){
        cout<<"Fount at index "<<ans;
    }
    else{
        cout<<"Not found !";
    }
    return 0;
}
