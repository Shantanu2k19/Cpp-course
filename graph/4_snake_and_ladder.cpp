/*
snake and ladder problem
find minimum dice throws to end the game
36 total cells in game
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
        //adjlist[v].push_back(u); not bi-directional
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
    void bfs(T src,T dest)   //source node from which traversal starts 
    {
        queue<T> q;  
        map<T, int> dist; //to track distance

        map<T,T> parent;  //only to print the path, no need in bfs

        for(auto i:adjlist){  //adjlist is actually a map of < T,list<T> >
            dist[i.first]=INT_MAX; //all distances are infinity in beginning
        } 

        q.push(src);  
        dist[src]=0;

        parent[src] = src; //to print the path, storing the parents

        parent[src]=src;
        while(!q.empty()){
            T node = q.front();
            q.pop();

            for(int neighbour : adjlist[node]){
                if(dist[neighbour]==INT_MAX){   //if it has not been visited yet, i.e distance is infinite 
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node; //for printing path
                }
            }
        }
        //print distances to all  nodes
        for( auto i:adjlist){
            T node =i.first;
            cout<<"dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
        }

        cout<<"\nthrows to reach 36 : "<<dist[dest]<<endl;

        //printing the path
        T temp = dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
    }
};

int main()
{
    //input : board array
    int board[50] = {0};
    board[2] = 13;  //lader from 2 to 13
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;  //snake from 17 to 13
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //add edges to graph
    graph<int> g;
    for(int i=0;i<=36;i++){
        for(int dice=1; dice<=6 ;dice++){ //connecting graph,
            int j= i+dice;
            j += board[j]; //considers for snakes and ladder there

            if(j<=36){
                g.addEdge(i,j);
            }             
        }
    }
    g.addEdge(36,36);  //above will never add 36 to graph
    g.bfs(0,36);//shortest path to destination node
} 
//shows infinite distace to some places where snakes/ladder exist

/* OUTPUT :

dist of 0 from 0 is 0
dist of 1 from 0 is 1
dist of 2 from 0 is 2147483647
dist of 3 from 0 is 1
dist of 4 from 0 is 1
dist of 5 from 0 is 2147483647
dist of 6 from 0 is 1
dist of 7 from 0 is 1
dist of 8 from 0 is 2
dist of 9 from 0 is 2147483647
dist of 10 from 0 is 2
dist of 11 from 0 is 2
dist of 12 from 0 is 2
dist of 13 from 0 is 2
dist of 14 from 0 is 3
dist of 15 from 0 is 1
dist of 16 from 0 is 2
dist of 17 from 0 is 2147483647
dist of 18 from 0 is 2147483647
dist of 19 from 0 is 2
dist of 20 from 0 is 2147483647
dist of 21 from 0 is 2
dist of 22 from 0 is 3
dist of 23 from 0 is 3
dist of 24 from 0 is 2147483647
dist of 25 from 0 is 2147483647
dist of 26 from 0 is 3
dist of 27 from 0 is 2
dist of 28 from 0 is 3
dist of 29 from 0 is 2
dist of 30 from 0 is 3
dist of 31 from 0 is 3
dist of 32 from 0 is 2147483647
dist of 33 from 0 is 3
dist of 34 from 0 is 2147483647
dist of 35 from 0 is 3
dist of 36 from 0 is 4

throws to reach 36 : 4
36<--30<--29<--15<--0

*/
