/*
BFS : breadth first search explained
1. a queue is maintained
2. root is pushed, (1)
3. now it is popped and its children are pushed (,2,5)
4. now the front element is popped and its children are pushed (,,5,3,4)
5. continued the same process

queue         output
(1)
(,2,5)         1,
(,,5,3,4)      1,2
(,,3,4,6,7)    1,2,5
(,,4,6,7)      1,2,5,3
(,,6,7,)       1,2,5,3,4
(,,,7)         1,2,5,3,4,6
(,,,,8,9)      1,2,5,3,4,6,7

complexity : O(N)

tree:
            1
      2          5
    3   4      6   7
                   8   9
*/

#include <iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* constructTree()  //returns address of root node
{
    int d;
    cin>>d;
    if(d==-1)   // data of form : 3 -1 -1 means, 3 root, child none
    { return NULL; }  

    node* root = new node(d);
    root->left = constructTree();
    root->right = constructTree();
    return root; 
}

void bfs(node* root)
{
    queue<node*> q;  //queue of node*
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
            { q.push(NULL); }
        }
        else{
            node* temp = q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main() 
{
    node* lol = constructTree();
    bfs(lol);
}

/*
    sample input : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 8 -1 -1 9 -1 -1
    output : 
    1 
    2 5 
    3 4 6 7 
    8 9 
*/
