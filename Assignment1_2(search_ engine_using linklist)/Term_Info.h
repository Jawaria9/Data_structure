#pragma once
#include<string>
#include"Doc_info.h"
class Term_Info {
public:
	string term;
	DLL<Doc_Info> docList;
	Term_Info() {

	}
	Term_Info(const Term_Info& obj) {
		term = obj.term;
		docList = obj.docList;
	}

	Term_Info(string t, Doc_Info& di) {
		term = t;
		docList.insertAtStart(di);
	}

	void operator=(const Term_Info& obj) {
		term = obj.term;
		docList = obj.docList;
	}

	void set(string t, Doc_Info& di) {
		term = t;
		if (!docList.search(di)) {
			docList.insertAtStart(di);
		}
		else {
			docList.update(di);
		}
	}

	void print() {
		cout << "Term: " << term << endl;;
		Node<Doc_Info>* d = docList.head;
		while (d != nullptr) {
			d->data.print();
			d = d->next;
			cout << endl;
		}
	}

	~Term_Info() {

	}
};
