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

node* insertInBST(node* root,int d)
{ 
    if(root==NULL)
    {
        return new node(d);
    }
    if(d<=root->data)
    {
        root->left=insertInBST(root->left,d);
    }
    else
    {
        root->right=insertInBST(root->right,d);
    }
    return root;
}

void printBFSs(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            node* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

node* createTreeFromTraversal(int *inn,int *pre,int s,int e){
    static int i=0;  //static variable can only be initialised once
    //used because it will backtrack otherwise
    //base case
    if(s>e) return NULL;

    //rec case
    node* root = new node(pre[i]);  //creating new node from preOrder array

    int index = -1; //for searching in inOrder array
    for(int j=s;j<=e;j++){
        if(inn[j]==pre[i]){
            index = j;   //found element in inOrder array
            break;
        }
    }
    i++;    
    root->left = createTreeFromTraversal(inn, pre,s,index-1);
    root->right = createTreeFromTraversal(inn, pre,index+1,e);
    return root;
}

int main() {
    int inn[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};
    int n = sizeof(inn)/sizeof(int);
    node* lol = createTreeFromTraversal(inn, pre, 0, n-1);
    printBFSs(lol);
}
/* 
given pre-order traversal array of a tree : pre[] = {1,2,3,4,8,5,6,7};
given in-order traversal array of tree : inn[] = {3,2,8,4,1,6,7,5};

if only pre-order or post-order given, many number of trees can be formed
but with preOrder+inOrder or postOrder+inOrder, a unique tree will be formed

algo:
for every element in preOrder array, search it in inOrder array, left elements lies in left, right elements lies in right
ex:
given pre-order traversal array of a tree : pre[] = {1,2,3,4,8,5,6,7};
for 1 in pre,
inn[] = {3,2,8,4,  1  ,6,7,5};
    (root->left)       (root->right)

tree: 
            1 
        2       5 
      3   4    6 
        8        7 


similarly for all the elements 
*/
