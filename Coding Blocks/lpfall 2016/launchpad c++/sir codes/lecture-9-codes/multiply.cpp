#include<iostream>
using namespace std;

int multiply(int x,int y){
    if(y==0){
        return 0;
    }
    return x + multiply(x,y-1);
}

int convertString(char a[],int n){
    if(n==0){
        return 0;
    }
    //Recursive Case.
    int chotaAns = convertString(a,n-1);
    int lastDigit = a[n-1] - '0';
    int ans = chotaAns*10 + lastDigit;
    return ans;
}

int findAll7(int a[],int n,int i,int output[],int j){
    if(i==n){
        return 0;
    }
    if(a[i]==7){
        output[j] = i;
        return 1 + findAll7(a,n,i+1,output,j+1);
    }
    else{
        return findAll7(a,n,i+1,output,j);
    }
}

int countWays(int n){
    if(n==0||n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main(){
//cout<<multiply(5,6);
char str[]="12456";
//cout<<convertString(str,5);

int a[] = {1,2,3,7,4,7,5,7,7};
int output[100];
int count7 = findAll7(a,9,0,output,0);
for(int i=0;i<count7;i++){
    cout<<output[i]<<" ";
}


cout<<"Steps :"<<countWays(7)<<endl;

return 0;
}
