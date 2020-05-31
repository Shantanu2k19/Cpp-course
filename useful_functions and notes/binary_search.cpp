//binary search is only for sorted array
#include <iostream>
using namespace std;

void binary_search(int arr[],int key,int s,int e)
{
    //base case
    if(s>e) { 
        cout<<"not found";
        return;
    }
    //recursive case
    int mid=(s+e)/2;
    if(arr[mid]==key) { cout<<"found at index : "<<mid; return; }
    else
    if(arr[mid]<key) binary_search(arr,key,mid+1,e);
    else
    if(arr[mid]>key) binary_search(arr,key,s,mid-1);
}

int main() 
{
    int arr[9]={1,21,32,43,52,61,72,94,130}; //for(int i=0;i<9;i++) cout<<arr[i]<<endl;
    int s=0,e=8,key;
    key = 32;
    binary_search(arr,key,s,e);
}
