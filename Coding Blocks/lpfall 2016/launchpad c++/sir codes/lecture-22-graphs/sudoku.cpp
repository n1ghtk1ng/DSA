#include<iostream>
using namespace std;

bool canPlace(int mat[][9],int x,int y,int val){
    ///Check in the Row
        for(int i=0;i<9;i++){
            if(mat[x][i]==val){
                return false;
            }
        }

    ///Check in the Col
        for(int i=0;i<9;i++){
            if(mat[i][y]==val){
                return false;
            }
        }

    ///Check in the Subgrid
        int sx = (x/3)*3;
        int sy = (y/3)*3;
        for(int i=sx;i<sx+3;i++){
            for(int j=sy;j<sy+3;j++){
                if(mat[i][j]==val){
                    return false;
                }
            }
        }
        return true;
}

bool solveSudoku(int mat[][9],int i,int j,bool marked[][9]){
    if(i==9){
        return true;
    }
    if(j==9){
        return solveSudoku(mat,i+1,0,marked);
    }
    ///Now we are on the current cell i,j
    if(marked[i][j]==false){
            ///It means we can place some number
            for(int no=1;no<=9;no++){
                if(canPlace(mat,i,j,no)==true){
                    mat[i][j] = no;
                    bool canISolve = solveSudoku(mat,i,j+1,marked);
                    if(canISolve==true){
                        return true;
                    }

                }

            }
            ///Backtracking
            mat[i][j]=0;
            return false;
    }
    else{
        return solveSudoku(mat,i,j+1,marked);
    }
}
void print(int mat[][9]){

     for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


}

int main(){

int mat[9][9] = {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
    bool marked[9][9];


    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(mat[i][j]!=0){
                marked[i][j]=true;
            }
            else{
                marked[i][j]=false;
            }
        }
    }
    print(mat);
    solveSudoku(mat,0,0,marked);
    print(mat);

    return 0;
}
