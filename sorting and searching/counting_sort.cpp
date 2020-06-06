/*
COUNTING SORT
when we have to sort data lying in a certain range
algo: traverse over all the data, maintain an array and 
store the frequency of data in that array
cout the array with index according to frequency

comp = O(N + range(a to b)) ~ O(N), when range is small

ex: 2 3 5 3 3 1 1 4

array = 1 2 3 4 5
freq =  2 1 3 1 1

op : 1 1 2 3 3 3 4 5

*/
#include <iostream>
using namespace std;

void counting_sort(int *arr, int n){
    int largest = -1;
    for(int i=0;i<n;i++)   largest = max(largest, arr[i]);

    int *freq = new int[largest+1]{0}; //create freq array

    for(int i=0;i<n;i++) freq[arr[i]]++;

    //put elements back in array according to frequency
    int j=0;
    for(int i=0; i<=largest; i++){
        while(freq[i]>0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)  cin>>arr[i];

    counting_sort(arr,n);
    for(int i=0;i<n;i++)  cout<<arr[i]<<" ";

}
