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

node* insertInTree()
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


int countNodes(node* root){    //COUNT the number of nodes
    //base case
    if(root == NULL){
        return 0;
    }

    int count = 1 + countNodes(root->right) + countNodes(root->left);
    return count;
}  

int heightOfTree(node* root)
{
    if(root==NULL)
    { return 0; }

    int lh=heightOfTree(root->left);
    int rh=heightOfTree(root->right);
    int height= max(lh,rh)+1;
    return height;
}

//diameter of tree : 3 cases: (1)passes through root node, (2)lies in left of root node, (3)lies in right of root node, 
//also : diameter = maximum number of continuous edges, not the nodes, height of left + right = diameter 
// no need to add 1, height addition compensates for it 

int diameterOfTree(node* root)    //complexity :: O(n^2)
{
    if(root==NULL) return 0;
    int h1=heightOfTree(root->left);  
    int h2=heightOfTree(root->right);
    int op1=h1+h2;                       //case 1
    int op2=diameterOfTree(root->left);  //case 2
    int op3=diameterOfTree(root->right); //case 3
   // cout<<op1<<" "<<op2<<" "<<op3<<endl;
    return max(op1,(max(op2,op3)));     // max of all cases
}  


//FAST DIAMETER 
/* created a pair of height and diameter, hence in only once traversal, heights and diameter is calculated 
reduced complexity 
node from bottom returns height and diameter to top one 
*/

class Pairr  //STL pair can also be used
{
    public:
    int height;
    int diameter;
};

Pairr fastDiameter(node* root)
{
    Pairr p;
    if(root==NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    Pairr left=fastDiameter(root->left);
    Pairr right=fastDiameter(root->right);

    p.height = max(left.height,right.height)+1;  //height

    p.diameter =max( (left.height+right.height) , max(left.diameter,right.diameter) ); 
    return p;
}

int main() 
{
    node* lol = insertInTree();
    //bfs(lol);
    cout<<"number of nodes in tree : "<<countNodes(lol)<<endl;
    cout<<"diameter of tree: "<<diameterOfTree(lol)<<endl<<endl;

    Pairr p=fastDiameter(lol);  //fast diameter accept argument of pair type
    cout<<"diameter using faster method : "<<p.diameter<<endl;  
    cout<<"height : "<<p.height<<endl;
}

/*
input : 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 8 -1 -1 9 -1 -1 
output : tree
            1
      2          5
    3   4      6   7
                   8   9
*/
