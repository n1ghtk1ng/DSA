#include<bits/stdc++.h>
using namespace std;

class person{
public:
    int money;
    char name[20];

    person(char*n,int m){

        money=m;
        strcpy(name,n);

    }
};
ostream &operator<<(ostream &os,person&p){

    cout<<"name: "<<p.name<<" "<<endl;
    cout<<"money: "<<p.money<<" "<<endl;
    cout<<endl;
    return os;
}
class mycompare
{///object behaving as a function i.e. functor
public:
    bool operator()(person &a,person &b){
    return a.money>b.money;
    }
};

int main(){

int a[]={1,2,12,5,4,3,7};
///max heap;
priority_queue<int>pq;
for(int i=0;i<7;i++){
    pq.push(a[i]);
}

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    ///min heap
    priority_queue<int,vector<int>,greater<int> >pq1;
for(int i=0;i<7;i++){
    pq1.push(a[i]);
}

    while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
///n+klogn for top k customers-->using heap
///nlogn in case of array

    person p1("abc",100);
    person p2("abba",200);
    person p3("acb",150);
priority_queue<person,vector<person>,mycompare >pp;
pp.push(p1);
pp.push(p2);
pp.push(p3);

person x=pp.top();
cout<<x;

}
