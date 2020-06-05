#include <iostream> 
#include<string.h>
using namespace std; 
//complexity :: o(NloglogN)
  
void Sieve(int *arr) //gives an array with index is prime if value is 1, CORRECT
{//1 = prime
    //special cases
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    //mark all odd nos as prime
    for(int i=3; i<=1000; i += 2){
        arr[i]=1;
    }

    //sieve
    for (int i=3; i <=1000 ; i+=2){  //traverse odd nos (op1)
        if (arr[i] == 1){ //if prime
            //mark all multiples of prime as not prime
            for(int j=i*i; j<=1000; j=j+i){ 
                arr[j]=0;
            }
        }
    }
} 

/* here, all allready marked as prime(0), only odds are checked
while finding answers, all the even indices are skipped : for(int i=1; i<=n; i+=2)   if(p[i]==0) cout<<i; (2 not included)
*/
void Sieve2(int *prime)  //consideration should be kept in mind
{ // 0=prime
    prime[0] = prime[1] = 1; //not prime
    prime[2] = 0; //prime
    for (int p=3; p*p<=1000 ; p+=2) { 
        if (prime[p] == 0){ //if prime 
            for (int i=p*p; i<=1000; i=i+p) //mark all multiples of prime as not prime
                prime[i] = 1;   //mark as not prime
        } 
    } 
}

int main() 
{ 
    int n;
    cin>>n;

    int p[1000] = {0}; 
    Sieve(p);
    //way 1
    for(int i=0; i<=n; i++)   if(p[i] == 1) cout<<i<<", ";

    //second way
    int lmao[1000] = {0};
    Sieve2(lmao);
    cout<<endl<<"2, ";
    for(int i=1; i<=n; i+=2)   if(lmao[i]==0) cout<<i<<", ";
} 
