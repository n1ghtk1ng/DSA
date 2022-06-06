#include<iostream>
using namespace std;

//Arrays are always passed by reference automatically.
void selectionSort(int a[],int n){

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
}


int main(){
    int a[100],n;
    cout<<"Enter n ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    selectionSort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}
