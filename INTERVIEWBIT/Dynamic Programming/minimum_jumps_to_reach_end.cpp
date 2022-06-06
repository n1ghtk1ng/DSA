//Variables to be used:

//1.maxReach :- The variable maxReach stores at all time the maximal reachable index in the array.
//2.step :- The variable step stores the amount of steps we can still take(and is initialized with value at index 0,
//i.e. initial number of steps)
//3.jump :- jump stores the amount of jumps necessary to reach that maximal reachable position.
#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n){

if(n==1)
    return 0;
if(arr[0]==0)
    return -1;

int ladder=arr[0];
int stairs=arr[0];
int jump=1;


for(int i=1;i<n;i++){
        //we are on i th index currently
//    cout<<"maxReach = "<<maxReach<<" step = "<<step<<" jump = "<<jump<<endl;
    if(i==n-1)
        return jump;

    ladder=max(ladder,i+arr[i]);
    stairs--;

    if(stairs==0){
        jump++;
        if(i>=ladder){ // we are currently on i th index
            return -1;
        }
        stairs=ladder-i;

    }

}
return -1;
}

int main(){

int arr[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
int n = sizeof(arr)/sizeof(int);

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

cout<<minJumps(arr,n);


return 0;
}
