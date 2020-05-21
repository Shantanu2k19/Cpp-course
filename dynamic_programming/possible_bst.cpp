/*
aim: count number of BST that can be formed using n nodes from 1 to n

use a dp, summation(i=0 to i=N)[f(i-1).f(N-1)]
or
shortcut : 2nCn/(n+1)   : CATALANS NUMBER

unlabelled binary trees: number of structures (remove numbers, just the nodes)
equal to bst or catalans number

binary trees:  all the permutations : n!*catalans number
*/

#include <iostream>
using namespace std;

int dp[100]={0};

int catalanNumber(int n)
{
    //bottom up approach, storing no of BSTs in dp for all numbers 1 to n
    if(n==0) return 1;
    if(dp[n]!=0) return dp[n];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=catalanNumber(n-i)*catalanNumber(i-1);
    }
    dp[n]=ans;
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<catalanNumber(n);
}
