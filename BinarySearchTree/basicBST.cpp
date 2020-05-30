#include<iostream>
#include<queue>
#include<limits.h>
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

node* insertInBST(node* root,int d){
    //base case: make new node and return address
    if(root==NULL){
        return new node(d);
    }

    //rec case
    if(d<=root->data)
        root->left = insertInBST(root->left,d);
    else
        root->right = insertInBST(root->right,d);

    return root;
}

node* makeBST()  //helper functon
{
    int d;
    cin>>d;
    node* root=NULL;
    while(d!=-1){    //take i/p till -1
        root=insertInBST(root,d);
        cin>>d;
    }
    return root;
}


//SEARCH : returns if element is present or not
bool searchInBST(node* root,int d)  
{
    if(root==NULL) return false;

    if(root->data==d) return true; 
    
    if(d <= root->data) 
        return searchInBST(root->left,d);
    else
        return searchInBST(root->right,d); 
}


/* delete a particular node
3 types of node
1) leaf node : 0 childern
    make the previous node to point to null

2) 1 child node
    store child to temporary variable, 
    make previous node to point at child

3) 2 child node
    replacement will be, either maximum element from the left
    or minimum element from the right
    for BST ::
           5  
         3   7 
        1   6 8 
    in order : 1,3,5,6,7,8 
    to replace 5, either 3 or 6 
    then remove the element
*/
node* deleteFromTree(node* root,int data)
{
    if(root==NULL) return NULL;  //no data found 
    else
    if(root->data > data){
        root->left = deleteFromTree(root->left,data);
        return root;
    }
    else
    if(root->data < data){
        root->right = deleteFromTree(root->right,data);
        return root;
    }

    if(root->data==data){   //data to be deleted found
        //case 1, 0 child
            if(root->left==NULL && root->right==NULL){
                delete root;   //delete the node
                return NULL;   //return null to parent
            }

        //case 2: 1 child
            if(root->left!=NULL && root->right==NULL){   //case 2.1 : left child is present
                node* temp=root->left;   //store
                delete root;
                return root->left;
            }

            if(root->left==NULL && root->right!=NULL){   //case 2.2 : right child is present
                node* temp=root->right;
                delete root;
                return root->right;
            }

        //case 3: 2 child 
                node* replace = root->right;  //replacing with the smallest element in right,(5->6 in example )
                //right, then leftmost element(6) is next to 5

                while(replace->left!=NULL){
                    replace = replace->left;
                }
                root->data = replace->data;  //swap root(5) with replace(6)

                //now deleting the replaced node
                //the root(6) right with point to tree without replace node
                root->right = deleteFromTree(root->right,replace->data); //delete replace node from tree
                return root;
    }
    return root;
}

//check whether a BST
//for any node, it should be greater than max value on left & min value on the right, also, left and right should also be bst
bool isBST(node* root,int minVal=INT_MIN,int maxVal=INT_MAX)  //top down approach
{
    if(root==NULL) return true;
    if(root->data<=maxVal && root->data>=minVal && isBST(root->left,minVal,root->data) && isBST(root->right,root->data,maxVal)){
        return true;
    }
    return false;  //else
}

//for printing
void printBFS(node* root){  //print : level order 
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        if(q.front()==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            node* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void printInOrder(node* root){  //print in order of a BST is sorted array
    if(root==NULL) return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main()
{
    node* lol=makeBST();
    cout<<"original tree : \n";
    printBFS(lol);
    cout<<"In order : ";
    printInOrder(lol);
    cout<<"\n\ndelete 5 \n";
    lol = deleteFromTree(lol,5);
    
    cout<<"new tree : \n";
    printBFS(lol);
    cout<<"In order : ";
    printInOrder(lol);

    cout<<"\n\nsearch 19 in tree : ";
    if(searchInBST(lol,19)) cout<<"present\n";
    else  cout<<"not present\n";  
}

/*
input : 5 3 7 1 6 8 -1
output : 
        original tree : 
        5 
        3 7 
        1 6 8 
        In order : 1 3 5 6 7 8 

        delete 5 
        new tree : 
        6 
        3 7 
        1 8 
        In order : 1 3 6 7 8 

        search 19 in tree : not present

*/
