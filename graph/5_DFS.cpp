/*
DFS : deapth first search

ex:
                    2------1
                    |      |
                    |      |
                    3------0
                    |
                    |
                    4------5

starting from 0, it visits the unvisited neighbour then its neighbour
after the end node, it comes back from same path and visit any unvisited node

Pointer movement : 0->3->4->5->4->3->2->1->2->3->0

OUTPUT : 0->3->4->5->2->1   or other output depending on traversal
o/p here: 0->1->2->3->4->5

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
        adjlist[v].push_back(u); //consider bidirectional
    }

//dfs : depeth first search algorithm
    void dfsHelper(T node,map<T,bool> &visited ){
        cout<<node<<"->";
        visited[node]=true;  //mark it visited

        //try to find put not visited neighbour of node
        for(T neighbour: adjlist[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }

    void dfs(T src)
    {
        map <T,bool> visited;  //initially false, 
        //can also be initialsed with false using a loop here

        dfsHelper(src,visited);

        /*
        //below code for finding number of components in the graph (non conneted graphs)

        int comp=1;          //(maintaining count)
        for(auto i:adjlist) {
            T GivenNumber = i.first;
            if(!visited[GivenNumber]){  //if current node not visited
                dfsHelper(GivenNumber,visited);
                comp++;
            }
        }
        cout<<"\ncurrent graph had "<<comp<<" components !";
        */
    }
};

int main()
{
    graph<int> h;
    h.addEdge(0,1);
    h.addEdge(0,3);
    h.addEdge(1,2);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(4,5);
    h.dfs(0);
} 
