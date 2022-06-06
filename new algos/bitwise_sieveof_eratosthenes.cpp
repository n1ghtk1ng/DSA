#include<bits/stdc++.h>
using namespace std;

#define MAX 100000000
#define LIM 10000
int arr[MAX>>6];
#define ifComp(x) (arr[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (arr[x>>6]|=(1<<((x>>1)&31)))

//Now,
//
//(x>>1)&31)
//is used to divide the number by 2 and then take its mod with 32 (for any power of 2, x mod Number(where Number is a power of two) is equal to x&(Number-1)), this gives the required bit number.
//Furthermore,
//
//(1<<((x>>1)&31))
//we use this to make the given bit/obtained bit in previous step 1.


void BitSeive()
{
       register int i,j,k;
       for(i=3;i<LIM;i+=2)
       {
              if(!ifComp(i))
              {
                     for(j=i*i,k=i<<1;j<MAX;j+=k)
                            isComp(j);
              }
       }
       printf("2 ");
       for(i=3;i<MAX;i+=2)
       {
              if(!ifComp(i))
              {
                     printf("%d ",i);
              }
       }
}
int main() {
       BitSeive();
       return 0;
}
