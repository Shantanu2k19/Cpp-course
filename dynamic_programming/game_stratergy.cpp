#include <iostream>
using namespace std;

int arr[1000];

int gameStratergy(int i,int j){
    //base case
    if(i>=j) return 0;

    int ans;
    ans = max((arr[i]+ min(gameStratergy(i+2,j), gameStratergy(i+1,j-1))),(arr[j]+min(gameStratergy(i,j-2), gameStratergy(i+1,j-1))));
    return ans;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<gameStratergy(0,n-1);
}
