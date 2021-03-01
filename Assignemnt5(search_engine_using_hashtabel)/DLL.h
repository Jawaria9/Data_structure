#include <iostream>
#include <string>
using namespace std;

template <class T>
//class node
class node {

public:
	//data members
	T data;
	node* next;
	node* prev;
	//constructor
	node() {
		next = NULL;
		prev = NULL;
	}
	node(T data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
	node(T data, node <T>* next, node <T>* previous) {
		this->data = data;
		this->next = next;
		this->prev = previous;
	}
	//destructor
	~node() {
		next = NULL;
		prev = NULL;
	}
};
//doublylinklist classimplementation
template <class T>
class DLL {

public:
	node<T>* head;
	node<T>* tail;
	//constructor
	DLL() {
		head = new node<T>();
		head->prev = NULL;
		head->next = NULL;
	}
	//destructor
	~DLL() {
		node<T>* p = head;
		while (head) {
			head = head->next;
			delete p;
			p = head;
		}
	}
	//printing method
	void display() const {
		if (head->next != NULL) {
			node<T>* temp = head;
			while (temp != NULL) {
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		else 
			cout << head->data;
		
		cout << endl;
	}
	//insersion at start method
	void insert_at_start(T data){

		node<T>* temp = new node<T>(data);
		if (head == NULL){
			head = tail = temp;
			temp->prev = NULL;
			temp->data = data;
			temp->next = NULL;
		}
		else
		{
			temp->next = head;
			temp->data = data;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;

		}
	}
	//insersion at end
	void insert_at_end(T const data){

		node<T>* temp = new node<T>;
		//n->data = data;
		if (head == NULL){
			head = temp;
			temp->previous = NULL;
			temp->next = NULL;
			tail = temp;
		}
		else{
			temp->previous = tail;
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
		}
	}


	bool search(T const& data, node<T>*& n) const {
		bool checker = false;
		node<T>* temp = head;
		if (head != NULL) {
			if (head->next != NULL) {
				while (temp != NULL) {
					if (temp->data == data) {
						n = temp;
						return 1;
					}
					temp = temp->next;
				}
			}
			else {
				if (head->data == data) {
					n = temp;
					return 1;
				}
			}
		}
		return 0;

	}
	
	bool search(T const& data) const {
		bool checker = false;
		if (head != NULL) {
			node<T>* temp = head;
			if (head->next != NULL) {
				while (temp != NULL) {
					if (temp->data == data) {
						return 1;
					}
					temp = temp->next;
				}
			}
			else {
				if (head->data == data) {
					return 1;
				}
			}
		}
		return 0;
	}
	//deletion method
	void delete_at_start() {
		if (head == tail)
		{
			return;
		}
		if (head == tail)
		{
			node<T>* temp1 = head;
			head = NULL;
			tail = NULL;
			delete temp1;
			return;
		}
		else
		{
			node<T>* temp = head;
			head = head->next;
			head->previous = NULL;
			delete temp;
		}
	}
	void delete_at_end(){
		if (head != NULL){
			if (head == tail){
				delete head;
				head = tail = 0;
			}
			else{
				tail = tail->previous;
				delete tail->next;
				tail->next = 0;
			}
		}
	}
	

	void update(T const& data) const {
		bool checker = false;
		if (head->next != NULL) {
			node<T>* temp = head;
			while (temp != NULL) {
				if (temp->data == data) {
					temp->data = data;
					return;
				}
				temp = temp->next;
			}
		}
		else {
			if (head->data == data) {
				head->data = data;
				return;
			}
		}
		return;

	}


	//operator overloading
	void operator=(const DLL<T>& obj) {
		node<T>* temp = obj.head;
		while (temp != NULL) {
			insert_at_start(temp->data);
			temp = temp->next;
		}
	}
	//finding length method
	int length() {
		int length = 0;
		node* p = head;
		while (p != NULL) {
			length++;
			p = p->next;
		}
		return length;
	}
	//method to clear the data
	void clear() {
		while (head != NULL) {
			delete_at_start();
		}
	}



};
