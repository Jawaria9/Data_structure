#include<iostream>
using namespace std;
#include<stack>

template<typename T>
class Node{
    private:
       T data;
       Node<T>* next;
    public:
       Node(T data){
         this->data = data;
         next = NULL;
       }
       Node(T data,Node*next){
         this->data = data;
         this->next = next;
       }
        template<typename u>friend class Queue;
};

template<typename T>
class Queue{
    Node<T>* head;
    Node<T>* tail;
    int size;
    
  public:
    Queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T element){
         if(head==NULL){
             head=tail=new Node<T>(element,NULL);
             size++;
         }
         else{
             tail->next=new Node<T>(element,NULL);
             tail=tail->next;
             size++;
         }
    
    }
    T front(){
        if(head!=NULL){
        return head->data;
        }
        else{
            return 0;
        }
    
    }
    void pop(){
        if(head!=NULL){
        Node<T>*temp=head;
        head=head->next;
        delete temp;
        temp=NULL;
        size--;
        }
    
    }
    
};




void reverse(Queue<int> &q){
    stack<int>s;
    while(!q.isEmpty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
}

int main(){
 Queue<int> q;
 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);

 reverse(q);
 while(!q.isEmpty()){
     cout<<q.front()<<" ";
     q.pop();
 }

}
