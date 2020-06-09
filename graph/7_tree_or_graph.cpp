/*
is a graph tree or not detection
tree doesnt contain cycles, if cycle found, its graph
algo: dfs traversal
        if any note is visited twice and it's parent is not any of its neighbour
        then there is a cycle present in that tree
*/
#include <iostream>
#include<list>
#include<map>
#include<queue>
#include<limits.h>
using namespace std;

class graph{
    list<int> *adjlist;
    int v;

    public:
    graph(int v){
        this->v = v;
        adjlist = new list<int>[v];
    }

    void addEdge(int u,int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    bool is_tree(int src){   //detecting cycles
        bool *visited = new bool[v];  //track visited nodes  
        int *parent = new int[v];   //track parents of node
        queue<int> q;

        for(int i=0;i<v;i++){
            visited[i] = false;
            parent[i] = i;
        }

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            //iterate over neighbour of node
            for(int neighbour : adjlist[node]){
                if(visited[neighbour]==true && parent[node]!=neighbour) //if node allready visited and parent is not its neighbour, hence cycle
                { return false;}
                else if(! visited[neighbour]){        //not visited
                        visited[neighbour] = true;
                        parent[neighbour] = node;
                        q.push(neighbour);
                }
            }
        }
        
        return true;  //no cycle, hence tree
    }
};

int main()
{
    graph h(4);
    h.addEdge(0,1);
    h.addEdge(3,2);
    h.addEdge(1,2);
    h.addEdge(0,3);
    if(h.is_tree(0))
        cout<<"no cycles present! it's a tree";
    else
        cout<<"cycles present! uts a graph";
} 
/*
            1-----2
            |     |
            0     3
*/
