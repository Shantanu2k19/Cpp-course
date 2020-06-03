#include <iostream> 
#include<string.h>
using namespace std; 
//complexity :: o(NloglogN)
  
void Sieve(int n) 
{ 
    bool prime[n+1]={0};   //mark all as prime
  
    for (int p=2; p*p<=n; p++) { 
        if (prime[p] == 0){ //if prime 
            for (int i=p*p; i<=n; i=i+p) //mark all multiples of prime as not prime
                prime[i] = 1;   //mark as not prime
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]==0)   cout << p << " "; 
} 

int main() 
{ 
    int n;
    cin>>n; 
    Sieve(n); 
    return 0; 
} 
