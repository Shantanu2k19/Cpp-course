/* subarrays divisible by n(i.e size of array) 
example : 3, 4, 6, 2, 8, 1, 9, 3, 6, 7
a---------------------|
b---------------|
sum arr:0  3  7  13 15 23 24 33 36 42 49 
arr%10 : 0 3  7  3  5  3  4  3  6  2  9
           |_____|_____|_____|
            (any two subtraction)%10 == 0
            (13-3) =10 % 10 ==0

now, ramainders possible : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
frequenct in line 4      : 1, 0, 1, 4, 1, 1, 1, 1, 0, 1
for answer, iterate over array 12, wherever value>=2, ans+=(freq)C2  (pnc)
in above case, only 3 has a frequency of 4, so ans = 4c2, 4*(4-1)/2 == 6 subarrays

pigeonhole principle :  if there are n holes, and n+1 pigeons,
if we put pigeons in hole, there must be one hole with more than one pigeon

from 8, buckets = 10,
from 9, pigeons(sum of all) = 11
atleast one bucket will have 2 same values

(b-a)%n ==0

*/
#include <iostream>
using namespace std;


int arr[1000], freq[1000];

int main() {
    int n;
    cin>>n;
    memset(freq, 0, sizeof(freq));
    freq[0]=1;

    int sum=0;
    //read input
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
       // sum %= n;
        sum = (sum+n) % n;//if sum became negative
        freq[sum]++; //for that remainder, increase the frequency count 
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int m = freq[i];
        ans += m*(m-1)/2;     //mc2
    }
    cout<<ans<<endl;
    return 0;
}
