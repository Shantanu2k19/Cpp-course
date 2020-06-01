#include<iostream>
using namespace std;

int dekh(int arr[],int key,int s,int e){
    int mid=(s+e)/2;
    if(s>e) return -1;
    if(arr[mid]==key)  return mid;
    //left half sorted
    if(arr[s]<=arr[mid]){
        //key in left half
        if(arr[s]<=key && arr[mid]>=key)    return dekh(arr,key,mid+1,e);
        //search for key in right half
        else   return dekh(arr,key,mid+1,e);
    }
    //if right half sorted
    else{
        //key present in right half
        if(arr[mid]<=key && arr[e]>=key)   return dekh(arr,key,mid+1,e);
        //search in left half
        else   return dekh(arr,key,s,mid-1);
    }
    //key not found
    return -1;
}


int main(){
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];
    cin>>key;
    cout<<dekh(arr,key,0,n-1);
}
