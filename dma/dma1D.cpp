#include <iostream>
using namespace std;
int main() 
{
    int *a= new int;
    int *b= new int(30);   //value initialized with 30
//type of memory we want to alocate , name of the pointer (stored in stack), type of memory allocated in heap
    
    int n;
    cin>>n;
    int *arr= new int[n];     //make array, continuous block
    for(int i=0;i<n;i++)
       arr[i]=i;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    cout<<endl<<*a<<endl<<*b<<endl;

    //using delete for array and int variablr
    delete a;
    delete b;
    delete []arr;
}

