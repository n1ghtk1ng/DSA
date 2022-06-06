#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

void printSubsequences(char a[],int i,char output[],int j,vector<string> &vs){
    if(a[i]=='\0'){
        output[j]='\0';
        string s(output);
        vs.push_back(s);
        //cout<<output<<endl;
        return;
    }
    //Two Cases.
    output[j] = a[i];
    //output[j+1] = '\0';
    printSubsequences(a,i+1,output,j+1,vs);

    //output[j] ='\0';
    printSubsequences(a,i+1,output,j,vs);
}


int main(){
    char a[]= "ABC";
    char out[100];
    vector<string> vs;
    //permute(a);
    printSubsequences(a,0,out,0,vs);

    sort(vs.begin(),vs.end());
    for(int i=0;i<vs.size();i++){
        cout<< vs[i] <<endl;
    }

    vector<int> v;

return 0;
}
