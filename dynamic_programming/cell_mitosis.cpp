/*
cell mitosis

one container, with single cell
can perform 3 operaton on container
1. double number of cells
2. inc cell no by 1
3. dec cell no by 1
cost : x,y,z resp
all operations has different cost
aim : to produce n number of cells with minimum cost

solutions :
case 1: n is odd ex 7, can be reached 6+1      or         8-1
                        min of    (dp[n-1]+y)   ( dp[(i+1)/2)] + z)

case 2: n is even, ex 6, can be reached by 3*2     or  5+1
                            min of       (dp[i/2]+x)   (dp[i-1]+y)
*/

#include <iostream>
using namespace std;

int long long cellMitosis(int n,int x,int y,int z){ //bottom up approach

    long long *dp = new long long[n+1];
    //base
    dp[0] = 0; //to construct 0 cells, cost =0
    dp[1] = 0; //to construct 1 cell, allready present, so 0

    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        }
        else{
            dp[i] = min(dp[i-1]+y, dp[(i+1)/2]+x+z);
        }
    }
    return dp[n];
}

int main() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cellMitosis(n,x,y,z);
}
