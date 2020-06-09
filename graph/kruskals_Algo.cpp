/*
kruskals algo to find minimum spanning tree
*/
#include <iostream>
#include<algorithm>
using namespace std;

class edge
{
public:
    int src;
    int dest;
    int weight;
};

//class and 2 functions for finding cycle
class set
{
public:
    int rank;
    int parent;
};

int find(set *set, int i)  //return parent of set in which i(integer) lies
{
    if(set[i].parent != i)
    {
        set[i].parent = find(set, set[i].parent);
    }
    return set[i].parent;
}

void union(set *set, int v1, int v2)
{
    //union rank by path compression
    int v1_root = find(set,v1);
    int v2_root = find(set,v2);
    if(set[v1_root].rank>set[v2_root].rank)
    {
        set[v_root].parent=v2_root;
    }
    else
    if(set[v1_root].rank>set[v2_root].rank)
    {
        set[v2_root].parent=v1_root;
    }
    else
    {
        set[v2_root].parent=v1_root;
        set[v2_root].rank++;
    }
}

//own comparitor function for sort according to the weight 
bool comp(edge e1, edge e2)
{
    return e1.weight<e2.weight;
}

void Kruskals(edge *input, int n, int e)
{
    sort(input, input+e, comp);
    edge *output=new edge[n-1]; //total n-1 edges in final tree, edges=vertex-1
    set *set = new Set[n];
    for(int i=0;i<n;i++)
    {
        set[i].rank=0;
        set[i].parent=i;
    }
    int counter =0,i=0;  //counter become n-1, hence while stops
    while(counter<n-1)
    {
        edge currentEdge = input[i];
        int sourceParent = find(set, currentEdge.src);
        int destinationParent = find(set, currentEdge.dest);
        if(sourceParent != destinationParent)
        {
            output[counter]=currentEdge;
            union(set,sourceParent,destinationParent);
            counter++;
        }
        i++;
    }
}



int main(int argc, char const *argv[])
{
    int n,e; //vertices and edges
    cin>>n>>e;
    edge *input=new edge[e]; //edge array
    for(int i=0;i<e;i++)
    {
        int s,d,w; //source destination and weight
        cin>>s>>d>>w;
        input[i].src=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    cout<<"Hello World!";
}
