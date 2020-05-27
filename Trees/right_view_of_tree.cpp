#include <bits/stdc++.h>
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


//right view using BFS : method 1
void rightviewBFS(node* root)
{
    queue<node*> q;
    q.push(root);  
    q.push(NULL);                   //push root node and a null
    cout<<q.front()->data<<" ";     //print root node
    while(!q.empty()){
        if(q.front()==NULL){        
            q.pop();
            if(!q.empty()){        //front null, and poping null fives right node in front of queue
                cout<<q.front()->data<<" ";
                q.push(NULL);
            }
        }
        else{
            node* temp=q.front();
            q.pop();
            if(temp->right) q.push(temp->right);
            if(temp->left)  q.push(temp->left);
        }
    }
}


//right view using depth traversal : method 2

int arr[100] = {0};  //creating array for levels, putting rightmost value in index(level)
void rightviewDepthFirst(node* root,int level){
    //base case
    if(root==NULL) return;

    if(arr[level] == 0){          //level not visited before
        arr[level] = root->data;
        cout<<root->data<<" ";     //put data at that level and print
    }
    rightviewDepthFirst(root->right,level+1);        //traverse right first
    rightviewDepthFirst(root->left,level+1);
}

int main() {
    node* lol = constructTree();
    cout<<"tree : \n";
    bfs(lol);

    cout<<"\nright view using level order : ";

    rightviewBFS(lol);
    cout<<"\n\nright view using depth first : ";
    rightviewDepthFirst(lol,1);
}

/*
1 2 3 -1 -1 4 -1 3 -1 -1 5 6 -1 -1 7 -1 -1 
right view:

            1
      2          5
    3   4      6   7
          3            
right view : [1,5,7,3]

1. using depth first : in,pre,post-Order
    
2. using breadth first(level order) : bfs
*/
