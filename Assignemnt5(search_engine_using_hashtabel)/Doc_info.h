#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Doc_Info {
	//data members
	int docId;
	int tf;

public:

	//constructor
	Doc_Info() {

	}
	//operator overloading
	bool operator!=(const Doc_Info& obj) {
		if (docId != obj.docId) {
			return 1;
		}
		return 0;
	}
	//operator overloading
	bool operator==(const Doc_Info& obj) {
		if (docId == obj.docId) {
			return 1;
		}
		return 0;
	}
	//operator overloading
	friend ostream& operator << (ostream& out, Doc_Info& d) {
		out << "doc id: " << d.docId << endl;
		out << "term frequency: " << d.tf << endl;
		return out;
	}
	//operator overloading
	void operator=(const Doc_Info& obj) {
		docId = obj.docId;
		tf = obj.tf;
	}

	Doc_Info(const Doc_Info& obj) {
		docId = obj.docId;
		tf = obj.tf;
	}

	Doc_Info(int di, int t) {
		docId = di;
		tf = t;
	}
	//setter
	void set(int di, int t) {
		docId = di;
		tf = t;
	}
	//getter
	int getDocID() {
		return docId;
	}

	int gettf() {
		return tf;
	}
	//print method
	void display() {
		cout << "doc id: " << docId << endl;
		cout << "term frequency: " << tf << endl;
	}

	void displayID() {
		cout << "doc " << docId << endl;
	}
	//destructor
	~Doc_Info() {
	}


};