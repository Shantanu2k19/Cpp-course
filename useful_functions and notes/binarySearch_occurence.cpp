//binary search, first and last occurrence of element in a sorted array
#include <iostream>
using namespace std;

int occurrence(int arr[], int n,int key){
    int s=0;
    int e=n-1;
    int ans=-1;

    while(s<=e){
        int mid=(s+e)/2;

        if(arr[mid] == key){
            ans = mid;
          //  e = mid-1;  //first occurrence of element 
            s = mid+1;  //last occurrence of element
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
void binary_search_recursion(int arr[],int key,int s,int e){
    //base case
    if(s>e){
        //cout<<"not found";
        return;
    }

    //recursive case
    int mid=(s+e)/2;

    if(arr[mid]<key) binary_search_recursion(arr,key,mid+1,e);
    else
    if(arr[mid]>key) binary_search_recursion(arr,key,s,mid-1);
    else
    if(arr[mid]==key){
        cout<<"found at index : "<<mid<<endl;
        binary_search_recursion(arr,key,mid+1,e);
        binary_search_recursion(arr,key,s,mid-1);
    }
}

int main() {
    int arr[]={1,21,32,43,52,61,61,61,61,72,94,130}; 
    int s=0,key;
    int e = sizeof(arr)/sizeof(int)-1;
    //cout<<e;
    key = 61;
    binary_search_recursion(arr,key,s,e);
    cout<<endl<<"occurrence of element "<<occurrence(arr,e+1,key);
}
