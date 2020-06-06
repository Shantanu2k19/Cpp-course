/*
MERGE SORT also divide and conquer sort
comp : o(nLogn)
working : divide array into two : 2 4 21 56 3 43 6 53
sort both :     2 4 21 56                3 43 6 53
                2 4 21 56                3 6 43 53
no merge using 2 pointers approach
2 3 4 6 21 43 53 56        
*/

#include <iostream>
using namespace std;

void mergethem(int *a,int s,int e){ //for merging the sorted array
    int i=s,k=s;
    int mid=(s+e)/2;
    int j=mid+1;

    int temp[100];  //temporary array 

    while(i<=mid && j<=e){ //using 2 pointers to compare values in 2 arrays 
        if(a[i]<a[j]) 
        temp[k++] = a[i++];
        else
        temp[k++] = a[j++];
    }
    //putting remaining elements 
    while(i<=mid) temp[k++]=a[i++];
    while(j<=e) temp[k++]=a[j++];

    //copy from temp array to arr
    for(int p=s;p<=e;p++) a[p]=temp[p];
}

void mergesort(int a[],int s,int e){  //helper
    //base case
    if(s>=e) return;

    //recursive case
    int mid=(s+e)/2;

    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    //merge the arrays
    mergethem(a,s,e);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
