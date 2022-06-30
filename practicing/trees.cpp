#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right; 
    
    node(int d){
        this->left=NULL;
        this->right=NULL;
        this->data = d;
    };
};

/*
            1
      2          5
    3   4      6   7
                   2   3
*/
node* makeTree(){
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node* root = new node(d);
    root->left=makeTree();
    root->right=makeTree();
    return root;
}

void printTree(node* root){     //in order, root->l->r    1 2 3 -1 4 5 6 -1 -1 7 2 -1 -1 3 -1 -1
    if(root == NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    cout<<endl;
}

class HBpair{
    public:
    bool isBal;
    int height; 
};

HBpair* check_height(node* root){
    HBpair p;
    if(root==NULL){
        p.isBal = false;
        p.height = 0;
    }
}



int main(){
    node* lol = makeTree();
    printTree(lol);
    cout<<"\n__________________________________\n";
    return (0);
}