/*DP program 1
fibonacci using DP: 
Approaches for solving fibonacci, 
    1.recursive
    2.top down  or  recursion + memoisation
    3.bottom up
    4.space optimised bottom up
5.(not covered here) matrix exponentiation : time o(logN)
*/


#include <iostream>
using namespace std;

//2. top down
//complexity : space: o(n) , time o(n)
int fib(int n,int dp[])
{
    //base case 
    if(n==0 || n==1){
        return n;
    }

    if(dp[n]!=0)  //visited earlier
    { return dp[n]; }

    dp[n] = fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

//3. bottom up approach  //array is created
int fibBD(int n)
{
    int arr[100]={0};  //dynamic aray can also be made
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

//4. space optimised bottom down, storing just the previous two elements (n-1) and (n-2)
//o(n) time o(n)space 
int fibBDspaceop(int n)
{
    if(n==0 || n==1){
        return n;
    }
    int a=1,b=1,sum=0;
    for(int i=0;i<n-2;i++){
        sum=a+b;
        a=b;
        b=sum;
    }    
    return sum;
}

int main() {
    int n=6;
    int dp[100]={0};
    cout<<fib(n,dp)<<endl;
}
