#include <iostream>
#include<set>
using namespace std;
/*
    set stores elements in sorted array 
    no repetitive elements are stored
    values in a set cannot be updated 
    operation takes O(logN) time
*/
int main() {
    int arr[] = {10,20,32,43,21,20,10};
    int n = sizeof(arr)/sizeof(int);

    set<int> lol;
    for(int i=0;i<n;i++){
            lol.insert(arr[i]);
        }

    cout<<lol.size()<<endl;


    //for accessing elements : way 1
    for(set<int>::iterator it=lol.begin(); it != lol.end(); it++)
        cout<< *it <<", ";


    cout<<"\n\nFinding element\n";

    set<int, int>::iterator gg = lol.find(21); //returns iterator 
    if(gg!=lol.end()){
        cout<<"found\n";
        cout<<*gg<<endl;
    }
    else cout<<"not found\n";


    lol.erase(20);  //to delete element
    cout<<endl;

    //another way to access elements
    for(int x:lol) cout<<x<<", ";
    cout<<endl<<endl;




    //set of pairs
    set<pair<int,int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(30,4));
    s.insert(make_pair(50,6));
    s.insert(make_pair(30,9));
    s.insert(make_pair(73,8));

    s.erase(make_pair(73,8));

    auto it = s.lower_bound(make_pair(20,1));  //greater or equal to, upper_bound: strictly greater
    cout<<it->first<<" "<<it->second<<endl;

    for(auto p:s){
        cout<<p.first<<" and "<<p.second<<endl;
    }
}
