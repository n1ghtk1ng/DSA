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

    cout<<"Enter the Key";
    cin>>key;

    //Searching
    int i;
    for(i=0;i<n;i++){
        if(key==a[i]){
            cout<<"Found at index "<<i<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"Not Found Key"<<endl;
    }
return 0;
}
