/*based on video lecture 2 
Minimum steps to 1 using operations : n-1,n/2,n/3
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;


//top down approach
int stepsToOne(int n,int dp[]){
    //base case
    if(n==1) return 0;

    if(dp[n] != 0) return dp[n];
    //for n - 1
    int a=stepsToOne(n-1,dp);
    //for n / 2
    int b=INT_MAX,c=INT_MAX; //or INT_MAX with header file <climits>
    if(n%2==0){
        b=stepsToOne(n/2,dp);
    }
    //for n / 3
    if(n%3==0){
        c=stepsToOne(n/3,dp);
    }

    int sum = min(min(a,b),c)+1;
    return dp[n]=sum;
}

//bottom up approach
int stepsToOneBU(int n){
    //base case 
    int dp[100]={0};

    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int a,b,c;
        a=b=c=INT_MAX;
        if(i%2==0){
            a=dp[i/2];
        }
        if(i%3==0){
            b=dp[i/3];
        }
        c=dp[i-1];

        dp[i] = min(min(a,b),c) + 1;
    }
    return dp[n];
}


int main() {
    int n=4;
    int dp[100]={0};
    //cout<<stepsToOne(n,dp);
    cout<<stepsToOneBU(n);
}
