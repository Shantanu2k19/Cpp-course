/*
euclids algo : GCD greatest common divisor
a=12, b=20
GCD = HCF = 4, no other greater number than 4 which can divide both a&b

gcd(a,b) = gcd(b,a%b)
 b  __a__
12 | 20 | 1
     12
    ----_____
      8|  12 |
      ^    ^
till  | or | becomes zero

GCD * LCM = a * b
LCM = (a*b)/GCD
*/ 
#include <iostream>
using namespace std;

int GCD(int a,int b){
    return b==0? a : GCD(b, a%b);
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<"GCD : "<<GCD(a,b)<<endl;
    cout<<"LCM : "<<(a*b)/GCD(a,b);
}
