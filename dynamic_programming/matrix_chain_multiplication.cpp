/* 
matrix chain multiplication
given matrix a[1 x 2] b[2 x 6] c[6 x 4] etc.
cost of multiplying => a[3 x 5]*b[5 x 4] = 3*5*4 = 60
find the minimum cost of multiplying matrices
a*(b*c) or (a*b)*c


*/
#include <bits/stdc++.h>
using namespace std;

int tdp[100][100];  //for dp

//using recursion then added minor changes 
int matrixChain(int m[],int i,int j){
    //base case
    if(i==j){
        tdp[i][j]=0;
        return 0; //single matrix
    }

    //check for overlapping subproblem
    if(tdp[i][j] != -1) return tdp[i][j];

    int ans=INT_MAX;
    for(int k=i; k<j; k++){    //dividing matrices A,B,C : A|BC, AB|C
        int temp = matrixChain(m,i,k) + matrixChain(m,k+1,j) + m[i-1]*m[k]*m[j];  //lets say A|BC
        //            for cost A            for B*C                 for cost A*(BC), i.e [1x2]*( [2x3]*[3x4] ) = [1x2]*[2x4] = 1*2*4
        ans = min(ans,temp);
    }
    tdp[i][j]=ans;
    return ans;
}

int main() {
    int matrices[] = {1, 2, 3,  4}; //3 matrices: 1x2, 2x3, 3x4
                   //    i..k...j(n-1)
    int n=sizeof(matrices)/sizeof(int);

    //initialise the array with -1
    memset(tdp,-1,sizeof tdp);
    cout<<matrixChain(matrices,1,n-1);
}

//incomplete : watch video from 21:04
