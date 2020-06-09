/*
just like the code of whether tree or graph but recursion used this time
visit node->visit its neighbour
if allready visited : -> if its neighbour is not its parent, cycle present
                      -> else, give a recursive call on its other neighbours

*/
#include <bits/stdc++.h>
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
        adjlist[v].push_back(u);  //non directed graph, bidr = true
    }

    bool cycle_helper(int src,bool *visited, int parent){   //detecting cycles
        
        visited[src] = true;
        for(auto neighbour : adjlist[src]){
            //two cases
            if(!visited[neighbour]){ //neighbour earlier not visited
                //recursive calls
                bool cycle_mila = cycle_helper(neighbour, visited, src);
                if(cycle_mila) return true;  //cycle found
            }
            else if(neighbour!=parent) //allready visited but its neighbour is not its parent
                return true;  //cycle found
        }
        return false; //no cycle found
    }

    bool find_cycle(){
        bool *visited = new bool[v];

        for(int i=0;i<v;i++) visited[i]=false;

        return cycle_helper(0, visited, -1);
    }
};

int main()
{
    graph h(5);
    h.addEdge(0,1);
    h.addEdge(1,2);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(4,0);
    if(h.find_cycle())
        cout<<"YES, the undirected graph contain cycles";
    else
        cout<<"NO, the undirected graph does not contain cycles";
} 
/*
            1-----2
            |     |
            0     3
            |     |
            |-----4
*/
