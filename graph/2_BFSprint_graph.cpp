/*
bfs traversal : iterative way
just like bfs in tree

maintain a queue
insert element

loop
    pop the element
    insert the neighbors in queue(only if not visited)
        and mark them visited

get nodes at different level :
ex:
                    2------1
                    |      |
                    |      |
                    3------0
                    |
                    |
                    4------5
            
            output : 0, 1, 3, 2, 4, 5
            level  : 1  2  2  3  3  4
dfs : recursive way
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

    void bfs(T src){
        map<T, int> visited;  //using a map to track whether visited or not
        queue<T> q;

        q.push(src);    //maintain queue
        visited[src] = true;

        while(!q.empty() ){   
            T node = q.front();
            q.pop();

            cout<<node<<" -> ";
            for(int neighbor : adjlist[node]){  //traverse neighbour
                if(!visited[neighbor]){  
                    q.push(neighbor);
                    visited[neighbor] = true; //mark neighbour as visited
                }
            }
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
    h.bfs(0);
}
