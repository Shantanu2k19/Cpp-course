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

int height(node *root){  
    if(root == NULL) return 0; 

    int ls = height(root->left);
    int rs = height(root->right);
    int hmax = max(ls,rs)+1;   //formula
    return hmax;
}

void PrintKthLevel(node* root, int k){
    if(root == NULL) return;

    if(k==1){
        cout<<root->data<<" ";
        return;
    }   
    PrintKthLevel(root->left,k-1);
    PrintKthLevel(root->right,k-1);
}

int main() 
{
    node* lol = constructTree();
    int heightt=height(lol);   //finding height of tree
   // cout<<endl;
    for(int i=1;i<=heightt;i++){  //printing all levels
        PrintKthLevel(lol,i);
        cout<<endl;
    }
}
