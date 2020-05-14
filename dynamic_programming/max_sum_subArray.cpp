//max subarray sum 

#include <iostream>
using namespace std;

int maxSum(int a[],int n){
    int dp[100]={0};

    dp[0] = a[0]>0 ? a[0]:0;

    int maxSoFar=dp[0];
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1]+a[i];
        if(dp[1]<0) dp[i]=0;
        maxSoFar = max(maxSoFar,dp[i]);
    }
    return maxSoFar;
}

//space optimised code : just take the previous element not the entire array,i.e kadanes algo
int kadanes(int a[],int n){
    int maxSum=0;
    int currentSum=0;

    for(int i=0;i<n;i++){
        currentSum=currentSum+a[i];

        if(currentSum<0) currentSum=0;

        maxSum = max(currentSum,maxSum);
    }
    return maxSum;
}

int main() {
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(arr)/sizeof(int);
    //cout<<maxSum(arr,n);
    cout<<kadanes(arr,n);
}
