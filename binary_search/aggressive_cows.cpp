/*
problem: given n stalls, and c cows 
place cows in stalls in such a way, that the minimum distance between any two cow is maximised

algo : from start to end, 
mid = (s+e)/e
check whether mid is feasible, if yes store it in ans and s=mid+1
else
e=mid-1;
check till s<=e
return ans;
*/
#include <iostream>
using namespace std;

bool canPlaceCow(int stalls[], int cows, int n, int mid){  //to find whethrt the mid ans is feasible
    int recentCow = 0;
    int count = 1;
    for(int i=1;i<n;i++){
        if(stalls[i]-stalls[recentCow] >=mid ){
            recentCow = i;
            count++;
            if(count == cows) return true;
        }
    }
    return false;
}

int main() {
    int stalls[] = {1,2,4,8,9};
    int n=5;
    int cows = 3;

    //binary search
    int s=0;
    int ans=0;
    int e=stalls[n-1];  // - stalls[0];
    while(s<=e){
        int mid = (s+e)/2;
        bool cowRakhPaye = canPlaceCow(stalls,cows,n,mid);
        if(cowRakhPaye){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    cout<<"maximum minimum distance between cows "<<ans<<endl;     
}
