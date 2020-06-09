/*
for weighted graphs, nondirectional 
minimum distance from source to another nodes
ex:
          1
    1-----------2
    | \        /
  7 |   \4    /1
    |     \  /
    4-------3
        2

maintain a distance map, key : city and value is distance
initially all distances set to infinity

*/
#include<bits/stdc++.h>
using namespace std;

template<typename T>

class graph{
    unordered_map< T, list< pair<T,int>> > m;

    public: 
    void addEdge(T u,T v,int dist,bool bidir=true){
        m[u].push_back(make_pair(v,dist));   //city ->othercity,distance : string,pair(string,int)
        
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj(){
        for(auto j: m){  //m is map of string, pair(string,int)
            cout<<j.first<<"-->";
            for(auto k:j.second){
                cout<<"("<<k.first<<","<<k.second<<")";
            }
            cout<<endl;
        }
    }

    void dijsktras(T src)
    {
        unordered_map<T,int> dist;  //map to store distance of each node
        //set all distances to infinity in beginning
        for(auto j:m){
            dist[j.first]=INT_MAX;
        }

        //using set to find out node with minimum distance
        set< pair<int,T> > s;  //used set bcs sorting according to first parameter
        
        dist[src]=0; //dist of starting node is zero
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            //find pair at front
            auto p=*(s.begin());
            T node = p.second;  //first is distance, second is node
            int nodeDistance = p.first;

            //node : present in set,  nodeDistance is distance of that node
            s.erase(s.begin());

            //iterate over neighbours/children of current node
            for(auto childPair : m[node]){
                if(nodeDistance + childPair.second < dist[childPair.first]){  //(parent dist) + (child dist, from iterator) < dist of childpair 
                    //in set,updation of a particular pair is not possible
                    //we have to remove old pair and insert a new one 
                    
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));  //finding the childpair to be edited
                    if(f != s.end()){
                        //node found
                        s.erase(f);
                    }
                    //insert the new pair
                    dist[dest] = nodeDistance + childPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }
        }

        //printing distances to all other nodes from source
        for(auto d: dist){
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }
};


int main() 
{

    /*
    graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
   // g.printAdj();
    g.dijsktras(1);
    */
      
    graph<string> india;
    india.addEdge("amritsar","delhi",1);
    india.addEdge("amritsar","jaipur",4);
    india.addEdge("jaipur","delhi",2);
    india.addEdge("jaipur","mumbai",8);
    india.addEdge("bhopal","agra",2);
    india.addEdge("mumbai","bhopal",3);
    india.addEdge("agra","delhi",1);
    
    india.printAdj();
    cout<<"\nDistances:\n";
    india.dijsktras("amritsar");
    
}
