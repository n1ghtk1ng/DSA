#include<bits/stdc++.h>
using namespace std;



int main()
{
list<int>l;
l.push_back(2);
l.push_back(4);
l.push_back(1);
l.push_back(5);
l.push_back(3);
l.push_back(8);
l.push_back(6);
l.sort();
l.reverse();

list<int>l1;

l1.push_back(11);
l1.push_back(13);
l1.push_back(30);
l1.push_back(15);
l1.push_back(31);
l1.push_back(81);
l1.push_back(61);
l1.sort();
l.merge(l1);
l.sort();
for(list<int>::iterator it=l.begin();it!=l.end();it++)
{
    cout<<*it<<"-->";
}
}
