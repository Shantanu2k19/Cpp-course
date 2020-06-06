/*
WAVE SORT
comp O(N)
sort array in way such as elements : smaller larger smaller ...
{1,3,4,2,7,4}
ans : 2 1 4 3 7 5 
waveform : \/\/\/\/\/\... 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,3,4,2,7,8};  //ans : 3 1 4 2 8 7 
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i+=2){
        if(i!=0 and arr[i]<arr[i-1])   swap(arr[i], arr[i-1]);  //the current element should be smaller than previous
        if(i!=n-1 and arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);  //larger than next element
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
