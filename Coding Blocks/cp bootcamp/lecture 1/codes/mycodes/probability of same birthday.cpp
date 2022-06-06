#include<iostream>
using namespace std;
//Here prob defines the probability that two people will have different birthdays
#define days 365.0
#define prob (1.0 - 1/days)
int minPeople(){
//res is the prob that x number of pairs will have different birthdays
//cnt is the count of minimum pairs such that all ofthem have different birthdays with probabbility <= 0.5
double res = 1;
int cnt = 0;
while(res > 0.001){
res *= prob;
cnt++;
//Showing the probability of 'cnt' number of pairs having different birthdays.
cout<<cnt<<" "<<res<<endl;
}
//Chance that we have a matching pair = (1-res)
// if we have total pair count cnt then n*(n-1)/2 = cnt where n is total number of people in the room
for(int i = 1;i<cnt;i++){
//cout<<i<<endl;
if(i*(i-1)/2 >= cnt)
return i;
}
return 0;
}
int main(){
cout<<minPeople()<<endl;
return 0;
}
