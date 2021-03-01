#pragma once
#include"Doc_info.h"
#include<fstream>
#include"DLL.h"

using namespace std;

int find_size(string str) {
	int size = 0;
	for (int i = 0; i < str.size(); i++)
		size = str[i] + size;

	return size;
}

class Term_Info {
public:
	//data members
	string term;
	DLL<Doc_Info> docList;
	Term_Info() {

	}
	//destructor
	~Term_Info() {

	}
	//copy constructor
	Term_Info(const Term_Info& obj) {
		term = obj.term;
		docList = obj.docList;
	}

	Term_Info(string t, Doc_Info& di) {
		term = t;
		docList.insert_at_start(di);
	}
	//operator overloading
	void operator=(const Term_Info& obj) {
		term = obj.term;
		docList = obj.docList;
	}
	//setter
	void set(string t, Doc_Info& di) {
		term = t;
		if (!docList.search(di)) {
			docList.insert_at_start(di);
		}
		else {
			docList.update(di);
		}
	}
	//printing method
	void display() {
		cout << "Term: " << term << endl;;
		node<Doc_Info>* d = docList.head;
		while (d != nullptr) {
			d->data.display();
			d = d->next;
			cout << endl;
		}
	}
	//operator overloading
	bool operator==(const Term_Info& obj) {
		if (obj.term == term)
			return 1;
		else
			return 0;
	}
	//operator overloading
	bool operator >=(const Term_Info& obj) {
		if (obj.term <= term)
			return 1;
		else
			return 0;
	}
	//operator overloading
	bool operator >(const Term_Info& obj) {
		if (obj.term < term)
			return 1;
		else
			return 0;
	}
	//operator overloading
	bool operator <(const Term_Info& obj) {
		if (obj.term > term)
			return 1;
		else
			return 0;
	}
	//operator overloading
	friend ostream& operator <<(ostream& out, Term_Info& obj) {
		out << obj.term << endl;
		obj.docList.display();
		return out;
	}
};