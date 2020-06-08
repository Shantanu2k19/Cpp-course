/*
graph with weighted vertices, string on the edges:

        A--20--B
        | \    |
        10 50  30
        |    \ |
        C--40--D         (a-->d) directed

 A   ->  (B,20)
string  list< pair<string,int> >
*/  

#include<bits/stdc++.h>
using namespace std;

class graph{
    //adj list
    unordered_map<string, list< pair<string,int> > > l;  //hashmap used instead of array of lists

    public:
    void addEdge(string x, string y, bool bidr, int wt){  //a, b, bidirectional, weight
        l[x].push_back(make_pair(y,wt));
        if(bidr){  //other way around
            l[y].push_back(make_pair(x,wt));
        }
    }

    /* PRINTING
    data in form : A -> [(b,20),(c,10)] 
    p is of type : |__________________|
    city = p.first = A
    p.secong = list< <pair<string,int> >  = neighbours    //(b,20)
    now iterating in ^ to obtain elements [(b,20),(c,10)]
    nbr is iterator for neighbour, iterating
        nbr.first = string = dest(ination) = b
        nbr.second = int = distance = 20 
    */
     void printAdjList(){
        for(auto p : l){   
                string city = p.first;
                list< pair<string, int> > neighbour = p.second; 

                cout<<city<<" -> ";
                for(auto nbr : neighbour){
                    string dest = nbr.first;
                    int distance = nbr.second;

                    cout<<dest<<" "<<distance<<", ";
                } 
                cout<<endl;
        }
    }


    
   
};
int main() {
    graph g;
    g.addEdge("a","b",true,20);
    g.addEdge("b","d",true,40);
    g.addEdge("a","c",true,10);
    g.addEdge("c","d",true,40);
    g.addEdge("a","d",false,50);

    g.printAdjList();

}
