/*
prime factroization of a number
2 methods used, 
24 = 2*2*2*3
N = a*b
atleast one of the factor of N lies between 2 and root-N
factors exist in pairs : 
         .___________.
36 : 2 , 3, 4, 6, 9, 12, 18
     |____________________|

if not able to find factor that is less than root-N that means it itself is prime number

METHOD 2, using sieve O(LogN) ignoring the precomputation time for sieve
when the number of queries a large
using sieve, the division check only goes through prime numbers and not composite number (not done here)
*/
#include <bits/stdc++.h> 
using namespace std; 

//METHOD 1
void printFactors(int n){   

    vector< pair<int,int> > factors;
    int count = 0;

    for(int i=2; i*i <= n ; i++){ //line 12
        if(n%i == 0){ //if divisible by i,reduce it till its not divisible anymore
            while( n%i == 0){
                n /= i;
                count++;  //count carries info about how many times to multiply(raise power of i)
            }
            factors.push_back(make_pair(i,count)); //store the divisor and count(power) of it
            count = 0;  //IMPORTANT
        }
    }
    if(n!=1){
        //if a number is resulted which is not further divisible 
        //its prime number itself
        factors.push_back(make_pair(n,1));
    }
    //print the factors
    for( auto f: factors){
        cout<< f.first <<" "<< f.second<<endl;
    }
    return;
}


int main() { 
    int n;
    cin>>n;
    printFactors(n);
} 
