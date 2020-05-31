#include <iostream>
#include<set>
using namespace std;

typedef multiset<int>::iterator lmao;  //for 31 line, new datatype

int main() {
    int arr[] = {10,20,30,10,10,10,17,50};
    int n=sizeof(arr)/sizeof(int);

    multiset<int> m(arr,arr+n);

    //erase
    m.erase(20);

    //insert
    m.insert(17);

    //iterate 
    for(int x:m){
        cout<<x<<" ";    //PRINT multiset method 1
    }

    //count
    cout<<"\n10 occurence : "<<m.count(10);     //PRINT number of occurence of an element

    cout<<endl;
    //find to get an iterator
    auto it = m.find(17);                //gives first element with value 17, PRINT
    cout<< *(it) <<endl;

    //get all elements equal to 10 and   PRINT them
    pair<lmao,lmao> range = m.equal_range(10);

    for(auto lmao = range.first; lmao!=range.second; lmao++)
        cout<< *lmao <<" - ";

    cout<<endl;


    //lower bound >= and uper bound >
    //means: iterate from it>=17 till it<40
    for(auto it=m.lower_bound(17); it!=m.upper_bound(40) ;it++){
        cout<< *it <<", ";
    }
}
/*
multiset - store multiple elements that have same value (unlike set)
stored in sorted order according to internal comparison object
values inserted cannot be modified
usses BST data structure
*/
