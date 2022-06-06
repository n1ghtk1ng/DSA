#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    int a[] = {1,3,4,7,2};
    int b[] = {2,4,6,13,1};

    unordered_map<int,bool> myMap;
    ///Intersection of Two Arrays
    for(int i=0;i<5;i++){
        myMap[a[i]] = true;
    }
    for(int i=0;i<5;i++){
        if(myMap.count(b[i])){
            cout<<b[i]<<endl;
        }
    }
///remove the duplicates
int c[]={5,1,1,2,3,3,3,3,4,100,100,111};
unordered_map<int ,bool>x;
for(int i=0;i<12;i++){

        x[c[i]]=true;

}
for(auto i=x.begin();i!=x.end();i++){
    if(i->second)
    cout<<i->first<<" ";
}

}
