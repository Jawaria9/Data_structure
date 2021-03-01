#include<iostream>
using namespace std;

template<typename T>
class Node{
    private:
    T data;
    Node<T>  *next;
    public:
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
    Node(T data,Node <T>*next){
        this->data=data;
        this->next=next;
    }
    template<typename u>friend class list;

};
template<typename T>
class list{
    private:
    Node<T>*head;
    Node<T>*tail;
    public:
    list(){
        head=NULL;
        tail=NULL;
    }
    ~list(){
        if(head!=NULL){
            if(head!=tail){
                delete head;
                delete tail;
                head=tail=NULL;
            }
            else{
            delete head;
            head=tail=NULL;
            }
        }
       
       
    }

    bool search_an_element(T element){
        Node<T> *temp=head;
        while(temp!=NULL && temp->data!=element){
            temp=temp->next;
        }
        return temp!=NULL;

    }
    void print_singly_list()const {
        Node<T>*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void insert_at_start(T const element){
        head=new Node<T>(element,head);
        if(tail==NULL){
            tail=head;
        }
    }
    void insert_at_end(T const element){
        if(tail!=NULL){
            tail->next=new Node<T>(element);
            tail=tail->next;
        }
        else{
            tail=head=new Node<T>(element);
        }
    }


    void delete_at_start(){
        if(head!=NULL){
            Node<T> *temp=head;
            head=head->next;
            delete temp;
            temp=NULL;
                if(head==tail){
                tail==head;
                }
        }

    }
    void delete_from_end(){
        
        if(head!=NULL){
            if(head!=tail){
                Node<T>*temp=head;
                while(temp->next!=tail){
                    temp=temp->next;
                }
                delete tail;
                tail=temp;
                tail->next=NULL;
                
            }
            else{
                delete head;
                head=tail=NULL;
               
            }
        }
       
    }
    bool delete_first_occurance(T const element){
        if(head!=NULL){
            if(head==tail ){
                if(head->data==element){
                delete head;
                head=tail=NULL;
                return true;
                }
                else{
                    return false;
                }
            }
            else{
                Node<T>*temp=head;
                while( temp->next!=NULL && temp->next->data!=element){
                    temp=temp->next;
                }
                if(temp->next==NULL){
                    return false;
                }
                else{
                    Node<T>*newtemp=temp->next;
                    temp->next=newtemp->next;
                    delete newtemp;
                    newtemp=NULL;
                    return true;
                }
            }
            
        }
        else{
            return false;
        }
    }
    void reverse_linklist(){
        Node<T>*previous=NULL;
        Node<T>*current=head;
        Node<T>*new_next=NULL;
        while(current!=NULL){
            new_next=current->next;
            current->next=previous;
            previous=current;
            current=new_next;
        }
        head=previous;
    }

};
int main(){

    list<int> obj1;
    obj1.insert_at_start(2);
    obj1.insert_at_start(6);
    obj1.insert_at_start(7);
    obj1.insert_at_end(3);
    obj1.insert_at_end(8);
    obj1.insert_at_end(2);
    obj1.insert_at_end(1);
    obj1.delete_at_start();
    obj1.delete_from_end();
    obj1.print_singly_list();
    cout<<obj1.search_an_element(2)<<endl;
    cout<<obj1.search_an_element(8)<<endl;
    cout<<obj1.search_an_element(1)<<endl;
    obj1.delete_first_occurance(2);
    obj1.print_singly_list();
    obj1.reverse_linklist();
    obj1.print_singly_list();

}