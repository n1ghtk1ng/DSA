#include<iostream>
using namespace std;

bool isSorted(int a[],int n){
    //Base Case
    if(n==1||n==0){
        return true;
    }
    //Made a chota Array
    int chotaArray[100];
    for(int i=1;i<n;i++){
        chotaArray[i-1] = a[i];
    }

    if(a[0]<a[1]&&isSorted(chotaArray,n-1)){
        return true;
    }
    else{
        return false;
    }

}

int main(){

//cout<<fact(5)<<endl;
int a[100] = {1,2,6,4,5};
if(isSorted(a,5)){
    cout<<"Array is Sorted";
}
else{
    cout<<"Array is NOT sorted !";
}

return 0;
}
