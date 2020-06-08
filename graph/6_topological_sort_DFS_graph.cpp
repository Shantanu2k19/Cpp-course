/*
TOPOLOGOCAL SORT : for acyclic directed graphs 
to resolve dependencies,not for cyclic graphs 

for every directed edge UV, U comes befor V 

directed graph : 
    ---->2---->
    |         |
    1         4
    |         |
    --->3----->
output : 1,2,3,4  or 1,3,2,4
explaination : 2,3 will always come after 1 in output
and 4 will always come after 2,3 in output

algo : 
from source visit neighbour if not visited (like dfs)
when came till end, then reverse back and store the node in list
watch for unvisited node while returning and keep adding current nodes in list
print list (ordering)
*/

#include <iostream>
#include<list>
#include<map>
#include<queue>
#include<limits.h>
using namespace std;

template<typename T>

class graph
{
    map< T,list<T> > adjlist;

    public:
    graph() 
    { }

    void addEdge(T u,T v){
        adjlist[u].push_back(v);
        //adjlist[v].push_back(u);  //no need since directed edge
    }

//dfs : depeth first search algorithm
    void dfsHelper(T node,map<T,bool> &visited ,list<T> &ordering){ //orgering for topo algo
        //whenever come to a node,mark it visited
        visited[node]=true;
       // cout<<node<<", ";

        //try to find not visited neighbour of node
        for(T neighbour: adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited,ordering);
            }
        }
        //untill now,simple dfs algo
        //1 line for topological sort
        //all children of current node visited
        ordering.push_front(node);
    }

    void dfs(T src){
        map <T,bool> visited; //to track visited nodes 
        dfsHelper(src,visited);
    }
    
    void dfsTopoligicalSort(){
        map<T,bool> visited;  
        list<T> ordering;   //track order

        for(auto i:adjlist){  //i is a pair (node,list of nodes), adjlist is list of neighbours
            T node=i.first;
            if(!visited[node]){
                dfsHelper(node,visited,ordering);  
            }
        }
        //print elements after ordering
        for(T element: ordering){
            cout<<element<<"-->";
        }
    }
};

int main()
{
    graph<int> h;
    h.addEdge(0,1);
    h.addEdge(1,2);
    h.addEdge(0,4);
    h.addEdge(2,4);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(3,5);
   // h.addEdge(6,7);
   // h.addEdge(7,8);
   // h.addEdge(8,6);
    h.dfsTopoligicalSort();
} 

/*
current graph :
        --->1-->2---->3---->5
        |       |     |
        0       |     |
        |      \|/    |
        ------->4<-----

output : 0-->1-->2-->3-->5-->4-->
*/
