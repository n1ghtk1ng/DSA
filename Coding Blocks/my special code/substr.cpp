#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
    for(int i=0;i<s.size();i++)
      {
        for(int j=1;j<=s.size()-i;j++)
        {

           string sub=s.substr(i,j);
          if(sub.compare("ABC")==0)
           {cout<<"YES";
           return 0;}

        }
      }
      cout<<"NO";
   }


