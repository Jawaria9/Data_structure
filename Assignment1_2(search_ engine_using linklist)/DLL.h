#include <iostream>
#include <string>
using namespace std;
template <class t>
class Node {
public:
	t data;
	Node* next;
	Node* prev;
	Node() {
		next = prev = nullptr;
	}
};

template <class t>
class DLL {
public:
	class iterator {
	private:
		Node<t>* ptr;
	public:
		iterator(Node<t>*& const obj) {
			ptr = obj;
		}
		iterator(const DLL<t>& obj) {
			ptr = obj.head;
		}
		Node<t>* operator++ (int) {
			ptr = ptr->next;
			return ptr;
		}
		Node<t>* operator-- () {
			ptr = ptr->prev;
			return ptr;
		}
		void setPtr(Node<t>* obj) {
			ptr = obj;
		}
		t& operator* () {
			if (ptr != nullptr) {
				return ptr->data;
			}
		}
		bool checkPtr() {
			if (ptr == nullptr) {
				return 0;
			}
			else {
				return 1;
			}
		}
	};

	Node<t>* head;
	Node<t>* tail;
	DLL() {
		head = nullptr;
		tail = nullptr;
	}
	void insertAtStart(t const element) {
		if (head == nullptr) {
			head = new Node<t>();
			head->data = element;
			head->next = nullptr;
			tail = head;
			tail->next = nullptr;
			tail->prev = head;
		}
		else {
			Node<t>* temp = new Node<t>();
			temp->next = head;
			head = temp;
			head->prev = nullptr;
			temp->prev = head;
			head->data = element;
		}
	}

	void print() const {
		if (head->next != nullptr) {
			Node<t>* temp = head;
			while (temp != nullptr) {
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		else {
			cout << head->data;
		}
		cout << endl;
	}

	bool search(t const& element, Node<t>*& no) const {
		bool flag = false;
		Node<t>* temp = head;
		if (head != nullptr) {
			if (head->next != nullptr) {
				while (temp != nullptr) {
					if (temp->data == element) {
						no = temp;
						return 1;
					}
					temp = temp->next;
				}
			}
			else {
				if (head->data == element) {
					no = temp;
					return 1;
				}
			}
		}
		return 0;

	}

	bool search(t const& element) const {
		bool flag = false;
		if (head != nullptr) {
			Node<t>* temp = head;
			if (head->next != nullptr) {
				while (temp != nullptr) {
					if (temp->data == element) {
						return 1;
					}
					temp = temp->next;
				}
			}
			else {
				if (head->data == element) {
					return 1;
				}
			}
		}
		return 0;
	}

	void DeleteAtStart() {
		Node<t>* temp = head;
		Node<t>* temp1;
		if (head->next != nullptr) {
			temp1 = head->next;
			delete head;
			head = temp1;
			head->prev = nullptr;

		}
		else {
			delete head;
			head = nullptr;
		}
	}

	iterator& begin(Node<t>* head) const {
		iterator it(head);
		return it;
	}

	iterator& end(Node<t>* tail) const {
		iterator it(tail);
		return it;
	}

	void update(t const& element) const {
		bool flag = false;
		if (head->next != nullptr) {
			Node<t>* temp = head;
			while (temp != nullptr) {
				if (temp->data == element) {
					temp->data = element;
					return;
				}
				temp = temp->next;
			}
		}
		else {
			if (head->data == element) {
				head->data = element;
				return;
			}
		}
		return;

	}

	int length() {
		int l = 0;
		Node<t>* temp = head;
		while (temp != nullptr) {
			l++;
			temp = temp->next;
		}
		return l;
	}

	void clear() {
		while (head != nullptr) {
			DeleteAtStart();
		}
	}

	void operator=(const DLL<t>& obj) {
		Node<t>* temp = obj.head;
		while (temp != nullptr) {
			insertAtStart(temp->data);
			temp = temp->next;
		}
	}

	~DLL() {
		while (head != nullptr) {
			this->DeleteAtStart();
		}
	}

};
