#include<iostream>
#include<queue>
#include<cstring>
#include<functional>
using namespace std;
class Person{
public:
    int age;
    int wt;
    char name[20];

    Person(int w,int a,char *n){
        strcpy(name,n);
        age = a;
        wt = w;
    }
    //friend operator<<(ostream &os,Person &p);  /// why friend function is not used here
    void print(){
    cout<<name<<endl;
    cout<<age <<endl;
    cout<<wt <<endl <<endl;
    }

};
ostream& operator<<(ostream &os,Person p){
    cout<< p.name<<endl;
    return os;
}


class myPerson{
public:
    bool operator()(Person &p1,Person &p2){   /// why passed by reference here
        //return p1.age > p2.age;
        if(strcmp(p1.name,p2.name)>0){
            return true;
        }
        else{
            return false;
        }
    }

};

class Compare{
public:
    bool operator()(int a,int b){
            return a>b;
    }
};



int main(){
    priority_queue<int> pq_max;
    priority_queue<int,vector<int>,greater<int> > pq;    ///how is this working
    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(2);
    pq.push(6);

    while(!pq.empty()){
        cout<< pq.top() <<endl;
        pq.pop();
    }

    Person p1(50,22,"Prateek");
    Person p2(40,18,"Vibhav");
    Person p3(45,21,"Samarth");

    priority_queue<Person,vector<Person>, myPerson > pp;
    pp.push(p1);
    pp.push(p2);
    pp.push(p3);

    while(!pp.empty()){
       Person t = pp.top();
       cout<<t<<endl;
      pp.pop();
    }


return 0;
}
