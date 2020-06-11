#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *next;

    node(int d){
        next=NULL;
        data=d;
    }
};

void insertAtTail(node *&head,int data){
    node *temp=head;
    while(temp->next!=NULL)    temp=temp->next;    
    temp->next=new node(data);
    return;
}

void insert(node *&head,int data){
    if(head==NULL){
        head=new node(data);
        return;
    }
    else
    insertAtTail(head,data);
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}


int main() {
    int n;
    cin>>n;
    node *head=NULL;
    for(int i=0;i<n;i++){
        int lol;
        cin>>lol;
        insert(head,lol);
    }
    print(head);
}
