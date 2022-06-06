#include<iostream>
using namespace std;

int main(){
    //Initialisation
    int a[100],n,key;

    cout<<"Enter N";
    cin>>n;
    cout<<"Enter Numbers ";

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //Sorting.
    int i=1;
    while(i<=n-1){
        for(int j=0;j<=n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    i++;
    }

    //Output
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
