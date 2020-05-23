#include <iostream>
using namespace std;

#define MOD 1000000007
int dp[100][100];

int numberOfWays(int r,int c){
    //base case, if cell blocked
    if(dp[r][c] == -1) return 0;

    //no of ways for first row
    for(int j=0;j<c;j++){
        if(dp[0][j] == -1) break; //if cell blocked
        
        dp[0][j]=1; //else 1 way
    }
    //for columns
    for(int j=0;j<r;j++){
        if(dp[j][0] == -1) break; //if cell blocked
        
        dp[j][0]=1; //else 1 way
    }
    
    //bottom up approach
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            //if cell blocked, leave it
            if(dp[i][j]== -1) continue;
          //  dp[i][j] = 0;

            if(dp[i][j-1] != -1){  //if left cell isn't blocked
                dp[i][j] = dp[i][j-1]%MOD;
            }
            if(dp[i-1][j] != -1){ //top cell
                dp[i][j] = (dp[i][j]+ dp[i-1][j])%MOD;
            }
        }
    }

    //check for final cells
    if(dp[r-1][c-1] == -1){
        return 0;
    }

    //print dp array
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    
    return dp[r-1][c-1];
}

int main() {
    memset(dp,0,sizeof dp);
    int m,n,p;  //m: rows, n:columns, p:number of cells blocked
    cin>>m>>n>>p;
    for(int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        //mark all blocked cells as -1
        dp[x-1][y-1] = -1;
    }
    cout<<numberOfWays(m,n)<<endl;
}
