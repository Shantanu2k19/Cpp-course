/*
for divisors: 
60 prime factors = 2^(2) X 3^(1) X 5^(1) 
divisors = 1,2,3,4,5,6,10,12,15,20,30,60
these devisores can be made using permutations of prime factors
2^0 + 3^0 + 5^0 = 3
2^1 + 3^0 + 5^0 = 4
2^1 + 3^1 + 5^0 = 6
2^1 + 3^1 + 5^1 = 10
ans so on
so 60 :  prime^p1 X prime^(p2)...
ans => (p1 + 1)*(p2 + 1)*....
for 60, (2+1)*(1+1)*(1+1) = 12

few changes ADDED in prime factor code 

for sum of factors, permute and add 
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
            count=0;  //IMPORTANT
        }
    }
    if(n!=1){
        //if a number is resulted which is not further divisible 
        //its prime number itself
        factors.push_back(make_pair(n,1));
    }
    int ans=1;   //ADDED---------------------------
    //print the factors
    for( auto f: factors){
        //cout<< f.first <<" "<< f.second<<endl;
        ans *= f.second+1;    //ADDED---------------------------
    }
    cout<<"factors : "<<ans;  //ADDED---------------------------
    return;
}


int main() { 
    int n;
    cin>>n;
    printFactors(n);
} 
