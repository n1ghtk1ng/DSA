#include<iostream>
using namespace std;

void printSoln(bool soln[][10],int m,int n){

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }


}
bool findSoln(char maze[][10],bool soln[][10],int i,int j,int m,int n){
    if(i==m-1&&j==n-1){
            //Print our solution
            soln[i][j] = 1;
            printSoln(soln,m,n);
        return true;
    }
    soln[i][j] = 1;

    if(j+1<n&&maze[i][j+1]!='X'){
        bool pathExists = findSoln(maze,soln,i,j+1,m,n);
        if(pathExists){
            return true;
        }
    }
    if(i+1<m&&maze[i+1][j]!='X'){
        bool pathExists = findSoln(maze,soln,i+1,j,m,n);
        if(pathExists){
            return true;
        }
    }
    soln[i][j]=0;
    return false;

}

int main(){
    char maze[10][10] = {{".X.XX"},{"....X"},{"..X.."},{"..X.X"},{"....."},
    {"X.X.."}
    };

    bool soln[10][10]={0};
    int m= 6,n=5;

    findSoln(maze,soln,0,0,m,n);




}
