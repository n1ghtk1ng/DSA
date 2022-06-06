#include<iostream>
using namespace std;

int main(){
   int n,val,count;
   cin>>n;

   int i=1;
   while(i<=n){
        //Spaces
        int spaces_count =1;
        while(spaces_count<=n-i){
            cout<<"\t";
            spaces_count++;
        }
         val = i;
         count = 1;
        while(count<=i){
            cout<<val<<"\t";
            val++;
            count++;
        }

        val = 2*i - 2;
        count = 1;
        while(count<=i-1){
            cout<<val<<"\t";
            val--;
            count++;
        }

        cout<<endl;
    i++;
   }

return 0;
}
