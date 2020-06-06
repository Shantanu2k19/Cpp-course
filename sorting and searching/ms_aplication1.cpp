/*
find all the pairs in arr[] such that
arr[i] > arr[j] provided i<j
ex : arr[] = {1,5,2,6,3,0};
(1,0) (5,2) (5,3) (5,0) etc.

algo: merge sort way, 
divided in 2 array, the array is sorted (no cross inversion pairs are lost in sorting divided array)

now, [1,2,5]  [0,3,6]
for i.th element to j.th element
if arr[i]>arr[j], arr[i] will make pair with all the j++ elements
else
if arr[i]<arr[j], arr[i] will not make pair with any of the remaining element
*/

#include <iostream>
using namespace std;

int mergeInversion(int *a, int s, int e){  //merge sort algo
    int mid=(s+e)/2;

    int i = s;
    int k = s;
    int j = mid+1;

    int temp[1000];
    int count = 0;
    while(i<=mid and j<=e){
        if(a[i]<=a[j]){ 
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
            count += mid-i+1;  //line 12 , remaining elements = mid-(i-1)
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }

    for(int i=s;i<=e;i++)
    a[i] = temp[i];

    return count;
}
int inversionCount(int *arr, int s, int e){
    //base case
    if(s>=e) return 0;

    //merge sort
    int mid = (s+e)/2;
    int x = inversionCount(arr,s,mid);  //left side sort
    int y = inversionCount(arr,mid+1,e);  //right side sort
    int z = mergeInversion(arr,s,e); //cross inversion pairs
    return x+y+z;
}

int main() {
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);

    cout<<inversionCount(arr,0,n-1)<<endl;
}
