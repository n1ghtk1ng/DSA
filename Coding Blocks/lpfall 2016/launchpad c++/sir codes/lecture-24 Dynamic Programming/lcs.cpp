#include<iostream>
#include<cstring>
using namespace std;

int lcs(char s1[],char s2[],int i,int j){

    if(i==strlen(s1)||j==strlen(s2)){
        return 0;
    }
    ///Match
    if(s1[i]==s2[j]){
        return 1 + lcs(s1,s2,i+1,j+1);
    }
    ///Mismatch
    else{
        return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
}

int lcsDp(char s1[],char s2[],int m,int n){
    int dp[100][100];

    for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                    if(i==0||j==0){
                        dp[i][j]=0;
                    }
                    else{
                        if(s1[i]==s2[j]){
                            dp[i][j]= 1 + dp[i-1][j-1];
                        }
                        else{
                            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                        }


                    }


            }
    }
    return dp[m][n];

}


int main(){

cout<< lcs("apple","ample",0,0)<<endl;
cout<< lcsDp("apple","ample",5,5);


}
