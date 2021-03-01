#pragma once
#include"DLL.h"
#include"Term_Info.h"
#include"AVL.h"
#include<string.h>
#include<fstream>
using namespace std;
class Search_Engine {
	AVL<Term_Info> index;
public:
	Search_Engine() {
	}

	void Create_Index(string* fname, int n) {
		for (int i = 0; i < n; i++) 
			Add_Doc_To_Index(fname[i]);
	}
	

	void Search_Query(string inStr) {
		DLL<string> terms;
		string qn; // query name
		//this is to tokenixze the string
		for (int i = 0; i < inStr.length(); i++) {
			if (inStr[i] == ' ' || inStr[i] == '\n') {
				terms.insert_at_start(qn);
				qn.clear();
			}
			else {
				qn = qn + inStr[i];
			}

			for (int i = terms.length(); i > 0; i--) {
				Term_Info temp;
				temp.term = terms[i];
				AVLnode<Term_Info>* temp = index.hasData(temp);

				cout << temp->data << endl;
			}


			cout << "IDs of documents containing searched queries are following." << endl;

			for (int i = 0; i < terms.length(); i++) {
				terms[i].display();
			}
		}
	}

	void Add_Doc_To_Index(string fname) {
		DLL<string> str;
		string s;
		string tstr;
		node<string>* aux;
		node<string>* aux1;
		AVLnode<Term_Info>* inAux;
		AVLnode<Term_Info>* ti;
		bool check = 0;
		int id = 0, c = 0;
		// finding id
		for (int i = 0; i < fname.length(); i++) {
			if (fname[i] >= 48 && fname[i] <= 57) {
				id = fname[i] - 48;
			}
		}
		ifstream fin(fname);
		if (fin.is_open()) {
			while (!fin.eof()) {
				fin >> s;
				str.insert_at_start(s);
			}
			fin.close();
		}
		aux = str.head; // head of list containing strings of current file
		ti = index.root;

		aux1 = aux;
		//Logic same as creating document. Read all words and store them in index and later we search through
		while (aux != nullptr) {
			Doc_Info di;
			c = 1; //frequency of words 
			tstr = aux->data;
			aux1 = str.head;
			//Loop to find number of occurences in file
			while (aux1 != nullptr) {
				if (tstr == aux1->data && aux1 != aux) {
					c++;
				}
				aux1 = aux1->next;
			}
			di.set(id, c);
			inAux = index.root;
			//this loop indicates if word is already indexed or not.
			while (inAux != nullptr) {
				Term_Info x;
				Doc_Info docId;

				x.term = aux->data;
				AVLnode<Term_Info>* temp = index.hasData(x);
				if (temp != NULL) {
					temp->data.docList.insert_at_end(docId);
				}
				else {
					x.docList.insert_at_end(docId);
					index.insert(x);
				}
				aux = aux->next;
			}

		}
	}



	~Search_Engine() {
		index.~AVL();
	}


};
