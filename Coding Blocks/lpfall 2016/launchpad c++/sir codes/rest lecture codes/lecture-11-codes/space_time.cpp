#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

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
    cout<< clock();
    int a[100000];
    clock_t t1;
    clock_t t2;

    int tests;
    cin>>tests;
    int n;
    while(tests){
        cin>>n;

        for(int i=0;i<n;i++){
            a[i] = n-i;
        }
        t1 = clock();
        cout<< t1 <<endl;
        selectionSort(a,n);
        t1 = clock() - t1;


        for(int i=0;i<n;i++){
            a[i] = n-i;
        }
        t2 = clock();
        sort(a,a+n);
        t2 = clock() - t2 ;

        cout<<"Elements "<<n<<endl;
        cout<<"Selection Sort "<<t1 <<endl;
        cout<<"Merge Sort "<<t2 <<endl;

    tests = tests - 1;
    }
    cout<<clock();


}
