#include <iostream>
using namespace std;

float square_binary(int n){
    int s=0;
    int e=n;

    float ans=-1;

    while(s<=e){
        int mid=(s+e)/2;  //(s+e)>>1:: right shift 1

        if(mid*mid == n) return mid;

        if(mid*mid <n){
            ans = mid;
            s=mid+1;
        }
        else  e = mid-1;
    }

    //floating part , brute force approach
    float inc=0.1;
    int order=3;   //precision after decimal
    for(int time=1; time<=order; time++){
        while(ans*ans <= n){
            ans = ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main() {
    int n;
    n=50;
    cout<<square_binary(n)<<endl;     
}
//comp: o(LogN + order)
