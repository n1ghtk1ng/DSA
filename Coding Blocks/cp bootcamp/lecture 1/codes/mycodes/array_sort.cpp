#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

bool compare(int a,int b){
  return a>b;

}

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
bool personcompare(const person&a,const person&b){
    //return a.money<b.money;
    return strcmp(a.name,b.name)<=0?true:false;
}

int main(){

    int a[]={5,4,3,2,1};
    sort(a,a+5,compare);///compare function ka address bheja hai humne,, sort function apne aap compare karega (if(compare(a[0],a[1])))
    for(int i=0;i<5;i++){

        cout<<a[i]<<" ";
    }
    cout<<endl;
    sort(a,a+3,compare);
    sort(a+3,a+5);

    for(int i=0;i<5;i++){

        cout<<a[i]<<" ";
    }
cout<<endl;
    person p1("abc",100);
    person p2("abba",200);
    person p3("acb",150);

    vector<person>vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    cout<<p1<<p2<<p3;
    sort(vp.begin(),vp.end(),personcompare);

    for(int i=0;i<vp.size();i++)
    {
        cout<<vp[i]<<endl;
    }
}
///use above to sort pairs of x,y coordinates
