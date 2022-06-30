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

node* insertInTree() //1 2 3 -1 4 5 6 -1 -1 7 2 -1 -1 3 -1 -1
{
    int data;
    cin>>data;

    if(data==-1)
    { return NULL; }
    node* root = new node(data);
    root->left = insertInTree();
    root->right = insertInTree();
    return root;
}

/*
            1
      2          5
    3   4      6   7
                   2   3
*/

class HBpair{
    public: 
    int height;
    bool balance;
};

HBpair isHeightBalanced(node *root){
    HBpair p;
    if(root == NULL){
        p.height = 0;
        p.balance = false; 
        return p;
    }

    HBpair left = isHeightBalanced(root->left);
    HBpair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if(abs(left.height - right.height) <=1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

int main() 
{
    node* lol= constructTree();
   if(isHeightBalanced){
       cout<<"yes";
   }
   else{
       cout<<"no";
   }
}
