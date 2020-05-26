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

node* buildTreeFromArray(int *a,int s,int e){
    //base case
    if(s>e) return NULL;

    //recursive
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
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

int main() {
    int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    node  *lol = buildTreeFromArray(a, 0, n-1);
    printBFSs(lol);
}
