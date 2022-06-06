#include<iostream>
#include<cstring>
#include<ctime>
#include<string>
#include<vector>
using namespace std;

string s[100]={" ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
vector<string>v;
void hack(char w[100],char ans[100],int i,int j)
{
    ///base case
    if(w[i]=='\0')
    {
        ans[j]='\0';
        string w(ans);
        v.push_back(w);
        return;
    }
    ///recursive case
    int c=w[i]-'0';
    for(int k=0;k<s[c].length();k++)
    {
        ans[j]=s[c][k];
        hack(w,ans,i+1,j+1);
    }

}
 vector<string> searchIn = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
int main()
{
    char ans[100];

    hack("123",ans,0,0);
    //for(int i=0;i<v.size();i++)
      //  cout<<v[i]<<" ";
      for(int i=0;i<searchIn.size();i++)
      {

      }
}
