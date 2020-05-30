#include<iostream>
using namespace std;

int dp[100]={0};

int catalanNumber(int n){
    if(n==0) return 1;

    if(dp[n]!=0) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=catalanNumber(n-i)*catalanNumber(i-1);
    }
    dp[n]=ans;
    return ans;
}

//using formula 2nCn/(n+1);
int main(){
    for(int i=0;i<10;i++){  //finding for 0 to 10 number of nodes
        cout<<catalanNumber(i)<<", ";
    }
}
/* 
derivation of formula aka another way

1.....i-1, i, i+1......N
trees = sum(i=1 to N) [f(i-1).f(N-1)]
simply, add number of trees formed by right side + left side
*/
