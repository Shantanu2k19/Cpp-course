/*
a instack and visited array is used
traversing from root node to neighbour, to their neighbour using recursion
if the neighbour allready present in stack, cycle detected
if not present, check if neighbour visited earlier
  if not, check for its neighbour using recursion
  
*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>

class graph{
    list<int> *adjlist;
    int v;

    public:
    graph(int v){
        this->v = v;
        adjlist = new list<int>[v];

     }

    void addEdge(T u,T v){
        adjlist[u].push_back(v);
     //   adjlist[v].push_back(u);  //IMPORTANT : IT'S NOT A DIRECTED GRAPH BITCH
    }

    bool isCyclicHelper(T node,bool *visited, bool *instack){
        //processing the current node being visited
        visited[node]=true;
        instack[node]=true;
        
        //explore the neighbours of node
        for( T neighbour: adjlist[node]) {
            if(instack[neighbour]== true) return true;//if neighbour allready in stack, cycle present
              
            else if(visited[neighbour] == false){       //if neighbour not present in stack, check for its other neighbour
                bool cycle_mila = isCyclicHelper(neighbour, visited, instack);  //recursive call
                if(cycle_mila == true) return true;   //cycle detected in any of the neighbours
            }
        }
        //no cycle detected
        instack[node]=false;
        return false;
    }

    bool contain_Cycle(){
        bool *visited = new bool[v];
        bool *instack = new bool[v];

        for(int i=0; i<v; i++){
            visited[i] = instack[i] = false;
        }
        return isCyclicHelper(0, visited, instack);
    }
};

int main()
{
    graph<int> h(7);
    h.addEdge(0,1);
    h.addEdge(1,2);
    h.addEdge(2,3);
    h.addEdge(3,4);
    h.addEdge(4,5);
    h.addEdge(1,5);
    h.addEdge(5,6);
   // h.addEdge(4,2);
    if(h.contain_Cycle())
        cout<<"cyclic present";
    else
        cout<<"no cycle detected";
} 
/*                  
                |-------|
                🠗       |
        0-->1-->2-->3-->4-->5-->6
            |               🠕
            |---------------|

    🠗

*/
