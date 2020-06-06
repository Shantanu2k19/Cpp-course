/*
QUICK SORT
divide and conquer algo
comp : avg, NlogN
       worst : n^2 (can be improved using randomization)
    
less space comp than merge sort, as no additional temp array is created

*/
#include <iostream>
using namespace std;

int partition(int *arr,int s,int e) {
    int i=s-1,j=s;
    int pivot=arr[e];
    for(;j<e;j++){   //traverse whole array
        if(arr[j]<pivot) {  //placing elements around pivot
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[e],arr[i+1]);
    return i+1;
}

int quicksort(int *arr,int s,int e){
    if(s>=e) return 0;  //bc

    int p=partition(arr,s,e);
    
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
    
    return 0;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];

    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)  cout<<arr[i]<<" ";
}
