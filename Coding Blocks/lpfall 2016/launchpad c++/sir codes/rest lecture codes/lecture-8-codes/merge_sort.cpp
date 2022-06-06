#include<iostream>
using namespace std;

void mergeArrays(int x[],int y[],int a[]
                 ,int s,int e){
     int mid=(s+e)/2;
     int i=s,j=mid+1;
     int k = s;

     while(i<=mid&&j<=e){
        if(x[i]<y[j]){
            a[k] = x[i];
            k++;
            i++;
        }
        else{
            a[k] = y[j];
            k++;
            j++;
        }
     }
     while(j<=e){
        a[k] = y[j];
        j++;
        k++;
     }
     while(i<=mid){
        a[k] = x[i];
        i++;
        k++;
     }

    }


void mergeSort(int a[],int s,int e){
if(s>=e){
    return;
    }
    //1. Step Break into two parts
    int mid= (s+e)/2;
    int x[100],y[100];

    for(int i=0;i<=mid;i++){
        x[i] = a[i];
    }
    for(int i=mid+1;i<=e;i++){
        y[i] = a[i];
    }
    //2.Recursively Sort the two parts
    mergeSort(x,s,mid);
    mergeSort(y,mid+1,e);
    //3. Merge the two arrays x & y
    mergeArrays(x,y,a,s,e);
}



int main(){

int a[100],n;
cout<<"Enter N";
cin>>n;

for(int i=0;i<n;i++){
    cin>>a[i];
}

mergeSort(a,0,n-1);

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

return 0;
}
