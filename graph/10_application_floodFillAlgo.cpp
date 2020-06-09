/*
application of graphs
flood fill algorithm
input : 1st line: 2d matrix size
then the matrix element : ".","#"
using #, a closed shape is made ,fill it with some character
*/
#include <iostream>
using namespace std;

int R,C;

void printMatrix(char input[][50]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
};

//         W,N,E,S  ,coordinates(i,j)
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//ch is the character to be replaced
//colour is character to be added 
void floodFill(char mat[][50], int i, int j, char ch, char colour){
    //base case - matrix bounds
    if(i<0||j<0 || i>R||j>C)
        return;

    //figure boundary conditions
    if(mat[i][j]!=ch)
        return;

    mat[i][j]=colour;  //colour the present cell
    
    //Recursive call
    for(int k=0;k<4;k++){  //for 4 directions
        floodFill(mat,i+dx[k],j+dy[k],ch,colour);
    }
};

int main() {
    cin>>R>>C;

    char input[15][50];

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }

    floodFill(input,2,2,'#','@');

    printMatrix(input); 
}
/*
INPUT :
            5
            5
            #####
            #aaa#
            #a#a#
            #aaa#
            #####

OUTPUT : 
            #####
            #aaa#
            #a@a#
            #aaa#
            #####
*/
