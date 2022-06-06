#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    vector<int>v;
    for(int i=1;i<10;i++)
    {
        v.push_back(i);
    }
    v.pop_back();
    v.pop_back();

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
  //  string s("hello");
    ///s object banaya hai and value passed to the constructor is hello
    //cout<<s<<endl;

    char sa[100];

    cin.getline(sa,100);//\n tak read aur \0 laga dena
    cout<<sa<<endl;

    string s1;//will store one string only
    //cin>>s1;
    //cout<<s1;

    getline(cin,s1);///input buffer se cin data uthake s1 object mein store karega
    cout<<s1;

    ///array of strings
    string s[10]={"apple","mang","guava"};
    for(int i=3;i<=6;i++)
    {
        getline(cin,s[i]);
    }
    for(int i=0;i<6;i++)
    {
        cout<<s[i]<<endl;
    }
    vector<string>vs;
    for(int i=0;i<6;i++){

        vs.push_back(s[i]);
    }
    sort(vs.begin(),vs.end());

    int a[]={1,2,3,4,5};
    vector<int>vi(a,a+5);

    for(int i=0;i<vi.size();i++){

        cout<<vi[i]<<endl;
    }
}
