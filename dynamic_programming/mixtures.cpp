/*
mixtures
n coloured mixtures, colours numbered from 0 to 99
when midex with each other: resultant colour: (a+b)%100, a,b is colour of mixtures
smoke generated in process: a*b

mixing all the mixtures with minimum smoke

given n number of mixtures
only 2 consecutive mixtures can be combined

solution : a,b,c,d.... : dividing into 2 parts : a|bcd..
m 
*/
#include <bits/stdc++.h>
using namespace std;

int a[1000];
int dp[1000][1000];

int sum(int s,int e){  
    int ans=0;
    for(int i=s;i<=e;i++){
        ans+= a[i];
        ans %= 100;
    }
    return ans;
}

int mixtures(int i, int j){
    //base case
    if(i>=j) return 0;

    //check 
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++){
        dp[i][j] = min( dp[i][j], mixtures(i,k) + mixtures(k+1,j) + sum(i,k)*sum(k+1,j) );
                                 //from i to k   from k to j        from mixing the two (i2k & k2j)                    
    }
    return dp[i][j];
}

int main() {       
    int n;
    while((scanf("%d",&n)) != EOF){
        for(int i=0;i<n;i++){  //read n integers representing colour 
            cin>>a[i];
        }        

        for(int i=0;i<=n;i++){  //initialise dp array with -1
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        cout<<mixtures(0,n-1)<<endl;
    }
}
