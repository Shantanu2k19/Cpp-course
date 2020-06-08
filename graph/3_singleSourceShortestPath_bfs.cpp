/*
single source shortest path using BFS

EX: 
                    2------1
                    |      |
                    |      |
                    3------0
                    |
                    |
                    4------5
for 0 to 5, shotest path from single source(0) = 0->3->4->5

algo: for source node 0, 
bfs will travel node wise

    1
   / \
0-|   2
   \ /
    3-->4-->5
the very first time node is discovered, that is the shortest path for node
or level of that particular node is distance
shortest : 0->3->4->5  , distance : 3 unit

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

    void addEdge(T u,T v,bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adjlist){
            cout<<i.first<<"->";  //iterate over map
            for(auto entry:i.second){  //iterating over linked list 
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }


    //Single Source Shortest Path bfs
    void bfs_distance(T src){   //source node from which traversal starts 
        queue<T> q;  
        map<T, int> dist; //to track distance

        for(auto i:adjlist){  //adjlist is actually a map of < T,list<T> >
            dist[i.first]=INT_MAX; //all distances are infinity in beginning
        } 

        q.push(src);   //first node
        dist[src]=0;


        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int neighbour : adjlist[node]){
                if(dist[neighbour]==INT_MAX){   //if it has not been visited yet, i.e distance is infinite 
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    
                }
            }
        }
        //print distances to all nodes
        for( auto i:adjlist){
            T node =i.first;
            cout<<"dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }
    }

};

int main(){
    graph<int> h;
    h.addEdge(0,1);
    h.addEdge(0,3);
    h.addEdge(1,2);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(4,5);
    h.bfs_distance(0);
} 
