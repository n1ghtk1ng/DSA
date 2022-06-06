#include<iostream>
#include<map>
using namespace std;

int main(){
    int a[] = {1,3,4,7,2};
    int b[] = {2,4,6,13,1};

    map<int,bool> myMap;
    ///Intersection of Two Arrays
    for(int i=0;i<5;i++){
        myMap[a[i]] = true;
        myMap[b[i]] = true;
    }
    for(auto it = myMap.begin();it!=myMap.end();it++){
        cout<< it->first <<endl;
    }



}
