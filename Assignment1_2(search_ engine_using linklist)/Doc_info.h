#pragma once
class Doc_Info {
	int docId;
	int tf; // term frequency

public:
	Doc_Info() {

	}

	bool operator!=(const Doc_Info& obj) {
		if (docId != obj.docId) {
			return 1;
		}
		return 0;
	}

	bool operator==(const Doc_Info& obj) {
		if (docId == obj.docId) {
			return 1;
		}
		return 0;
	}

	Doc_Info(const Doc_Info& obj) {
		docId = obj.docId;
		tf = obj.tf;
	}

	Doc_Info(int di, int t) {
		docId = di;
		tf = t;
	}

	void operator=(const Doc_Info& obj) {
		docId = obj.docId;
		tf = obj.tf;
	}

	void set(int di, int t) {
		docId = di;
		tf = t;
	}

	int getDocID() {
		return docId;
	}

	int gettf() {
		return tf;
	}

	void print() {
		cout << "Doc ID: " << docId << endl;
		cout << "Term Frequency: " << tf << endl;
	}

	void printID() {
		cout << "Doc " << docId << endl;
	}

	~Doc_Info() {
	}


};
