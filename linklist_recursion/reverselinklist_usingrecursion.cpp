#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *Next;

    Node(int data){
        this->data=data;
        Next=NULL;
    }
};
void print(Node *Head){//*&Head is by reference
    Node *temp=Head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->Next;
    }

}

Node* reverselink_list(Node*current,Node*previous){
    if(current==NULL){
        return previous;
    }
    Node*next=current->Next;
    current->Next=previous;
    previous=current;
    current=next;

    reverselink_list(current,previous);

}
int main(){
    
        Node *n1=new Node(3);
        Node *n2=new Node(4);
        Node *n3=new Node(5);
        n1->Next=n2;
        n2->Next=n3;
        Node *Head=n1;
        Head=reverselink_list(Head,NULL);
        print(Head);

}