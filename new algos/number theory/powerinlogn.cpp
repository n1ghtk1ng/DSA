#include<bits/stdc++.h>
#include<map>
using namespace std;

int power(int x,int n){

if(n==0)
return 1;

if(n & 1)//i.e. if b is odd
{
    return x*power(x,n-1);
}
else{
    int xsq=power(x,n/2);
    return xsq*xsq;
}
}

int main(){

    cout<<power(2,5);

}

/* Extended version of power function that can work
 for float x and negative y*/
#include<stdio.h>

float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

/* Program to test function power */
//int main()
//{
//    float x = 2;
//    int y = -3;
//    printf("%f", power(x, y));
//    return 0;
//}
///* Function to calculate x raised to the power y in O(logn)*/
//int power(int x, unsigned int y)
//{
//    int temp;
//    if( y == 0)
//        return 1;
//    temp = power(x, y/2);
//    if (y%2 == 0)
//        return temp*temp;
//    else
//        return x*temp*temp;
//}
