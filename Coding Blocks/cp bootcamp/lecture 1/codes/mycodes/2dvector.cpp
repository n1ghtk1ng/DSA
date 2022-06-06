#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r=3,c=4;
    vector< vector<int> >v(r);
    for(int i=0;i<r;i++){

        v[i].resize(c);
    }
    for(int i=0;i<r;i++){

        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    ///pair
    vector< pair<int,int> >v1;
    for(int i=1;i<=10;i++){

        v1.push_back(make_pair(i*i,i*i*i));
    }
    for(int i=0;i<v1.size();i++){

        cout<<v1[i].first<<" "<<v1[i].second<<endl;
    }
    ///set
    ///bar bar elemet ko search karna padh raha hai in that situation
    ///rb tree bst implemented
    ///no duplicate entries allowed
    ///finding elemet in logn time
    set<int>s;
    int arr[]={4,5,1,2,9,10,8,3,3,2};
    for(int i=0;i<10;i++)
        s.insert(arr[i]);
///set has to be only traversed using an iterator
for(set<int>::iterator it=s.begin();it!=s.end();it++)
{

    cout<<*it<<endl;
}
///searching zyada ho inserting kam ho
///ordered rhata hai and redundant elements khatam hote hain
///can be useful in cases we want number of non duplicare entries
///in order to allow duplicate entries use mutiset

///replace above set by multiset
auto it=s.find(9);
cout<<*it<<endl;
s.erase(9);
auto im=s.find(9);
if(im==s.end()){
    cout<<"not found";
}
else{
    ///cout<<it-s.begin()<<endl; ///it cant be used as there is no continous memory allocation
}
///here find uses logn time as it is bst
}

