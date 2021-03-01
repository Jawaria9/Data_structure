#include<iostream>
using namespace std;


template <typename T>
class Node{
  T data;
  Node<T> *next;
  public:
      Node(T data){
       this->data = data;
       next = NULL;
      }
       Node(T data,Node <T>*next){
        this->data=data;
        this->next=next;
    }
      template<typename u>friend class Stack;
};

template<typename T>
class Stack{
   Node<T> *head;
   int size;
   public:
       Stack(){
          head = NULL;
          size = 0;
       }
       int getSize(){
           return size;
       
       }
       bool isEmpty(){
           return size==0;
       
       }
       void push(T element){

            head=new Node<T>(element,head);
            size++;
       }
       
       
       void pop(){
           if(head!=NULL){
           Node<T>*temp=head;
           head=head->next;
           delete temp;
           size--;
           }
       }
       T top(){
           if(head!=NULL){
           return head->data;
           }
       }
};

int main(){
   Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.getSize();
    cout<<endl;
    cout<<s.isEmpty();

   
   return 0;
}