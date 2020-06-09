/*
vector is a dynamic array which grows or shrinks accordingly
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() 
{
    //create and initialise vector
    vector<int> v;
    vector<int> v2(5,7);    // containers of vector, value of each container
    vector<int> v3(v2.begin(),v2.begin());
    vector<int> v4{99,88,77};  //vector initialised with value

    //ITERATING
    for(int i=0; i<v4.size(); i++){
        cout<<v4[i]<<" ";
    }
    cout<<endl;

    for(auto it=v4.begin(); it!=v4.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto it : v4){
        cout<<it<<" ";
    }
    cout<<"\n\n";
    
    //INSERTION
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        v.push_back(no);//element at last
    }
    v.pop_back();  //deletes element from last 
    
    //insert element in middle of vector o(n)
    v.insert( v.begin()+3,4,1000);  //(index,no of element,element)
    //at index 3, 1000 have been added 4 times

    v.erase(v.begin()+3,v.begin()+6);  //erase from to 
    for(auto it : v){
            cout<<it<<" ";
    }
    cout<<endl;
        
    v.resize(18);
    if(v.empty()) cout<<"empty vector";
    cout<<"size: "<<v.size()<<", capacity: "<<v.capacity()<<endl;

    cout<<"front element : "<<v.front()<<endl;
    //size doubles when filled, expesive operation, creates new array, inserts old, deletes old
    //size as data is inserted : 1,2,4,8,16..
    //doubling is expensive operation so reserve memory befor inserting elements
    vector<int> d;
    d.reserve(1000);
}
