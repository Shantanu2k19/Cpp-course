#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;   //left & right child
    node* right;

    node(int d) //for defaults
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

//input: provided from allready a tree,  ex: 3 4 -1 6 -1 -1 5 1 -1 -1 -1 
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

void printTree(node* root) //1. pre-order : root->left->right
{
    if(root==NULL)
    { return ; }

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

//3 types of print
void printInOrder(node *root) //2. in-Order : left->root->right
{
    if(root==NULL)
    { return;  }

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

void printPostOrder(node *root) //3. post-order : left->right->root
{
    if(root==NULL)
    { return; }

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

int main() 
{
    node* lol = constructTree();
    printTree(lol);
   // cout<<endl;
    //printInOrder(lol)
    cout<<endl;
   // printPostOrder(lol);
}
