#include <iostream>
#include<set>
using namespace std;

//multiset with pair first as a string, will be sorted lexiographically
//to sort according to second int, custom class can be build, and passed while defining the multiset object

class person_compare{
    public:
    bool operator()(pair<string,int> p1, pair<string,int> p2){
        return p1.second<p2.second;
    }
}; 

int main() {
    //pair with (name,salary)
    pair<string,int> p1 = make_pair("B",100);
    pair<string,int> p2 = make_pair("C",200);
    pair<string,int> p3 = make_pair("A",400);
    pair<string,int> p4 = make_pair("H",150);
    pair<string,int> p5 = make_pair("O",700);

    multiset< pair<string,int>, person_compare > m;  //person_compare for sorting acc to int value
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    m.insert(p5);

    for(auto it: m){
        cout<<it.first<<" - "<<it.second<<endl;
    }
}
