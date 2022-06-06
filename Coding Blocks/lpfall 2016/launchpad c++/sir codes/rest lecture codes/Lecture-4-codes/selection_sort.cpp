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
    for(int i=0;i<n-1;i++){
        int smallest = i;
        //Finding the min element in remaining part.
        for(int j=i+1;j<=n-1;j++){
            if(a[j]< a[smallest]){
                smallest = j;
            }
        }
        //Swapping.
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
    }

    //Output
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
