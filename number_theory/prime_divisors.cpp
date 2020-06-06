/*

problem : all numbers less than n which are divisible by prime numbers less than 20

THEORY :

inclusion exclusion principle
set a and set b
a^b = a + b - a^b
a llersection b
ex : till 100, multiples of 2 = 100/2 = 50
multiples of 3 = 100/3 = 33

multiples of both a and b, i.e a^b = a + b + 6(a^b) => 50+33-16 => 67
multiples of 6 = 100/6 = 16

for 3 sets,
aUbUc = a+b+c -a^b -b^c -c^a
       odd terms,added   even terms, subtracted
    
problem : number divisible by 2,3 and 5 from 1 to 1000
same approach as above
2 : 999/2 = 499
3 : 999/3 = 333
5 : 999/5 = 199

2^3^5 = 2 + 3 + 5 -2*3 -3*5 -5*2 + 2*3*5

6 : 999/6 = 
10: 999/10 = 99
15 : 999/15 = 

30 : 999/15 = 

total: 733 llegers

problem : all numbers less than n which are divisible by prime numbers less than 20
*/
#include <iostream>
using namespace std;
#define ll long long 

int main() {
    ll t; //testcases
    cin>>t;
    ll primes[] = {2,3,5,7,11,13,17,19};  //8 primes

    while(t--){
        ll n;
        cin>>n;

        ll ans = 0;
        //create subsets, 2^8 -1
        ll subsets = (1<<8) -1;   //generating subsets using bitset 
        //for 8, from each binary number(0 to 8) take out permutations

        //iterate from 1 to (2^8 -1)
        for(ll i=1; i<=subsets; i++){  
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);  //stl to find number of set bits

            for(ll j=0;j<=7;j++){  //i will contain 8 bits, each bit representing one prime number from array
                if(i&(1<<j))   denom = denom*primes[j];   //denominator will be the chosen prime no
                //^ iterating over 8 bits & checking whether the bit is set or not, refer line 69
            }
            if(setBits&1)       ans += n/denom;  //no if bits (total no of primes taken) odd, then add(line 14) 
            else                ans -= n/denom;   //if even , subtract
        }
        cout<<ans<<endl;
    }
    return 0; 
}
/*
created a mask, 1<<j, left shift 1 to the position 
and with i, if i=1, 1&1 = 1 else 0
if i, i.e set, then multiply all the primes to be considered (line 22), and further finding divisors with it
*/
