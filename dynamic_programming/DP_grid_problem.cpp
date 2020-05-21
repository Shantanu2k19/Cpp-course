/*
grid based DP

1. given grid(2d array), each cell has certain cost to travel
find minimum cost to reach cretain cell
*/
#include <iostream>
using namespace std;

int arr[][10]={{1,2},{3,4},{5,6}};  //3 rown, 2 columns; cost array 
int dp[10][10];  //dp here stores lowest cost forreaching certain cell

void printt(int r,int c,int a[][10]){
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int min_cost(int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){

            //base case
            if(i==0 and j==0) dp[i][j] = arr[i][j];             //cell (0,0)
            else if(i==0) dp[i][j] = dp[0][j-1] + arr[0][j];    //column 1
            else if(j==0) dp[i][j] = dp[i-1][0] + arr[i][0];    //row 1
            else{
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + arr[i][j];
            }
        }
    }
    printt(r,c,dp);
    return dp[r-1][c-1];
}

int ratGrid(int r,int c){
    //base case
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 || j==0) dp[i][j]=1; //for 1st row and 1st column, only one way to reach
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    printt(r,c,dp);
    return dp[r-1][c-1];
}

int elephantGrid(int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 and j==0) dp[i][j]=1;
            else{
                int Xans=0,Yans=0;
                for(int k=0;k<i;k++) Yans += dp[k][j];  //for column 
                for(int m=0;m<j;m++) Xans += dp[i][m];  //for row

                dp[i][j] = Xans+Yans;
            }
        }
    }
    printt(r,c,dp);
    return dp[r-1][c-1];
}

int main() {
    cout<<min_cost(3,2)<<" : cost \n\n";
    cout<<ratGrid(3,2)<<" : number of paths to reach certain cell \n\n";
    cout<<elephantGrid(3,2)<<" : paths by elephant";
}
