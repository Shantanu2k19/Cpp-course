#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* right;
    node* left;
    node(int d)
    {
        data=d;
        right=NULL;
        left=NULL;
    }
};

node* insertInBST(node* root,int d)     //INSERTING 
{
    if(root==NULL) { return new node(d); }
    
    if(root->data>=d)
    {
        root->left=insertInBST(root->left,d);
    }
    else
    {
        root->right=insertInBST(root->right,d);
    }
    return root;
}

node* build()
{
    int d;
    cin>>d;
    node* temp=NULL;
    while(d!=-1)
    {
        temp=insertInBST(temp,d);
        cin>>d;
    }
    return temp;
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


//flattening a tree into linked-list 
class linkedList
{
    public:
    node* head;
    node* tail;
};

linkedList createLinkedList(node* root)
{
    linkedList l;
    //base case
    if(root==NULL){      
        l.head=l.tail=NULL;
        return l;
    }
    //case 1: both sides null
    if(root->left==NULL && root->right==NULL){
        l.head=l.tail=root;   //ha=ead and tail will point to same node
        return l;
    }

    //case 2: left not null (one side not null)
    if(root->left!=NULL && root->right==NULL){
        linkedList leftLL = createLinkedList(root->left); 
        leftLL.tail->right = root;   //previous node and root connected
    
        l.head=leftLL.head;
        l.tail=root;
        return l;
    }

    //case 3: right not null (one side not null)
    if(root->left==NULL && root->right!=NULL){
        linkedList rightLL = createLinkedList(root->right);
        root->right = rightLL.head;

        l.head=root;
        l.tail=rightLL.tail;
        return l;
    }

    //case 4: both sides not null, post order traversal used
    linkedList leftLL = createLinkedList(root->left);
    linkedList rightLL = createLinkedList(root->right);
    
    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head=leftLL.head;
    l.tail=rightLL.tail;
    return l;
}

int main(){
    node* lol=build();
    printBFS(lol);
    linkedList l = createLinkedList(lol);
    cout<<endl;
    node* temp=l.head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
