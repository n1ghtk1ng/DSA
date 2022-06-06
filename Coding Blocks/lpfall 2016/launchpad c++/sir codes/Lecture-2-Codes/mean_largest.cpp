#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n,num,sum,largest,smallest;
    cin>>n;
    sum = 0;
    largest = INT_MIN;
    smallest = INT_MAX;

    int i = 1;
    while(i<=n){
        cin>>num;
        sum = sum + num;
        if(num>largest){
            largest = num;
        }
        if(num<smallest){
            smallest = num;
        }
        i = i + 1;
    }
    cout<<"Average is "<<sum/n<<endl;
    cout<<"Largest is "<<largest<<endl;
    cout<<"Smallest is "<<smallest<<endl;

return 0;
}
