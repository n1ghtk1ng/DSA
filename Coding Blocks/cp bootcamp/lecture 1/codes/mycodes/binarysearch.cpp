#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[]={1,2,3,4,4,4,5,6,7};
    vector<int>v(arr,arr+9);

    vector<int>::iterator iv;
    for(iv=v.begin();iv!=v.end();iv++){

      //  cout<<*iv<<endl;
    }

   /// using binary search stl iterator to that element is returned ... in order to find the index of the element ,, subtract it from v.begin()

bool is_present=binary_search(v.begin(),v.end(),5);
cout<<is_present;

vector<int>::iterator it=find(v.begin(),v.end(),4);///vector has its own iterator class ,, linked list has its own
cout<<it-v.begin()<<endl;///index
cout<<*it<<endl;///value

///for multiple occurrences 2 more functions
auto firstocc=lower_bound(v.begin(),v.end(),4);
auto lastocc=upper_bound(v.begin(),v.end(),4);///it will return iterator of nex element to it
cout<<"index of first occurrence "<<firstocc-v.begin()<<endl;
cout<<"index of last occurrence "<<lastocc-v.begin()-1<<endl;
///find ,upperbound ,lowerbound etc.. all are working in log n steps
}
///find function --o(n) time rest others inlogn time
///find function works for unsorted array also
