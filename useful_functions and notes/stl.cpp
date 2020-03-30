#include <iostream>
#include<vector>

#include<algorithm>

using namespace std;

bool comparator(int a,int b)
{
    return a>b; //for decreasing order
}

int main() 
{
    /*
    int arr[]={10,20,30,40,40,40,50};
    int n=sizeof(arr)/sizeof(int);
    int key=30;

    //#1 find function : find index of element
    auto ptr=find(arr,arr+n,key);
    (ptr-arr)==n ? cout<<"ele not found!" : cout<<"index of ele : "<<(ptr-arr); 
   
    //#2 binary search in sorted array, gives if element present or not
    bool present = binary_search(arr,arr+n,key);
    present ? cout<<"\npresent" : cout<<"\nabsent"; 

    if(present) //then find index of it
    {
        auto lb = lower_bound(arr,arr+n,key); //element equal to or bigger
        cout<<"\nlower bound : "<<(lb-arr);

        auto ub = upper_bound(arr,arr+n,key); //element bigger
        cout<<"\nupper bound : "<<(ub-arr);

        (ub-lb)==1 ? cout<<"\nindex is "<<(lb-arr) : cout<<"\nfrequency of ele is : "<<(ub-lb);    
    }

    cout<<endl<<"sorted array : ";
    //#3 inbuild sort
    sort(arr,arr+n,comparator);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    //comparator can also be used in lower bound(gives no>=key) such that return a<=b\

    cout<<endl<<"rotated array : ";
    //#4 rotate : can rotate array or vector
    int lol[]={0,1,2,3,4,5,6,7,8,9}; 
    int s=sizeof(lol)/sizeof(int); 
    rotate(lol,lol+4,lol+s);
    for(int i=0;i<s;i++) cout<<lol[i]<<" ";

    cout<<"\nfor vector : ";
    vector<int> lel{0,1,2,3,4,5,6,7,8,9};
    rotate(lel.begin(),lel.begin()+4,lel.end());
    for(int i=0;i<lel.size();i++) cout<<lel[i]<<" ";

    cout<<endl<<"permutation : ";
    //#5 next permutation, in 123 gives 132 i.e next bigger number using only vector elements
    vector<int> kk{1,2,3,4};
    next_permutation(kk.begin(),kk.end());

    for(int x:kk) //substitute for 'for' loop
    {
        cout<<x<<" ";
    }
    */
    //#6 swap min() max()
    int a=1,b=100;
    swap(a,b);
    cout<<endl<<a<<" "<<b<<endl; 

    //#7 reverse() array
    int ary[]={1,2,3,4,5};
    reverse(ary,ary+3); //reverse first 4 elements of array
    for(int i=0;i<5;i++) cout<<ary[i]<<" ";
}
