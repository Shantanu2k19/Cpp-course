/*
check whether the number is prime

for sieve, 10^7 is the limit
for larger number 
we check if any divisor exist in range 2 to root(number)

caution : change int to long long, and the size of sieve
*/
#include <bits/stdc++.h> 
using namespace std; 

int Sieve(int *arr)  //returns size of array containing all the primes till 10,000
{//1 = prime
    //special cases
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    //mark all odd nos as prime
    for(int i=3; i<=10000; i += 2){
        arr[i]=1;
    }

    //sieve
    for (int i=3; i <=10000 ; i+=2){  //traverse odd nos (op1)
        if (arr[i] == 1){ //if prime
            //mark all multiples of prime as not prime
            for(int j=i*i; j<=10000; j=j+i){ 
                arr[j]=0;
            }
        }
    }
    
    int k=0;   
    for(int i=1;i<=10000 ;i++){
        if(arr[i] == 1) {
            arr[k]=i;
            k++;
        }
    }
    //now arr stores only prime mumbers, size of arr is returned
    return k;
} 

int main() { 
    int arr[10000] = {0};
    int size = Sieve(arr);
    int n;
    cin>>n;

    for(int i=0; arr[i] <= sqrt(n) ;i++){
        if(n % arr[i] == 0){
            cout<<"not prime";
            return 0;
        }
    }
    cout<<"prime"; 
}
