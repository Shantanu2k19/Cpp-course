/*
unordered map and ordered map STL
ordered map store in  lexiographically order
O(1) for every operation

*/



//for UNORDERED MAP
#include <iostream>
#include<unordered_map>
#include<cstring>
//for ORDERED map, include<map> and change declaration with map<_____>;
using namespace std;
int main() 
{
    //DECLARATION 
    unordered_map<string,int> m;   //can be anything, pair of string and int here
    
    //INSERTION
    m["mango"]=100;                      //way 1 of inserting
    m.insert(make_pair("apple",120));    //way 2 of inserting
    pair<string,int> p;                  //way 3 of inserting
    p.first = "lemon";  p.second = 200;
    m.insert(p);

    //UPDATE
    m["guava"]=m["apple"]+10;
    m["mango"]=200; //older will be updated

    //SEARCHING 
    if( m.count("apple")==1 )               //return 1 if element is present 
        cout<<"price of apple is "<<m["apple"];
    else
        cout<<"apple not found";

    //DELETION
    m.erase("guava");
    
    auto f=m.find("mango");
    if(f!=m.end())
        cout<<"\nmango found , price is "<<f->second;
    else
        cout<<"\nmango doesnt exist!";

    //ITERATE
    cout<<endl;
    for(auto it = m.begin(); it!=m.end(); it++ ){
        cout<<it->first<<" ,price : "<<it->second<<endl;
    }
    //unordered map, so will not be sorted lexiographically
}
