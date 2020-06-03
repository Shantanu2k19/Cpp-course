#include <iostream>
using namespace std;

bool canGiveScholarship(int n,int m,int x,int y,int mid){
    int couponsReq = (mid*x-m);
    if( (couponsReq - abs(n-mid)*y )>0 ) return false;
    else
        return true;
}

int main() {
    int n; //stud
    int m; //no of discount coupon available
    int x; //no of coupons to get 100% scholarship
    int y; //no of coupons to pay back 

    //INPUT
    cin>>n>>m>>x>>y;

    int s=0; 
    int e=n;
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if( canGiveScholarship(n,m,x,y,mid) ){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }
    cout<<ans;
}
/*
 n total students, 
 scholarship to be given of 100% 
 x coupons required to give scholarship to one students 
 m coupons allready available
 y coupons to be collected from stud who doesnt get scholarship

 maximise the numbver of students getting scholarship
*/
