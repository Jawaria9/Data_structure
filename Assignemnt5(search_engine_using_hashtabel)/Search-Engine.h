#pragma once
#include"Term_Info.h"
#include"hash_map.h"
#include<string.h>
#include<fstream>

using namespace std;

class Search_Engine {
	mymap<Term_Info> index;
public:
	Search_Engine() {
	}

	void Create_Index(string* fname, int n) {
		for (int i = 0; i < n; i++) 
			Add_Doc_To_Index(fname[i]);
	}
	

	void Search_Query(string inStr) {
		vector<string> terms;
		string qn; // query name
		//this is to tokenixze the string
		for (int i = 0; i <= inStr.length(); i++) {
			if (inStr[i] == ' ' || inStr[i] == '\n' || inStr[i] == '\0') {
				terms.push_back(qn);
				qn.clear();
			}
			else {
				qn = qn + inStr[i];
			}
		}
		MapNode<Term_Info>* temp;
		Term_Info queryT;
		for (int i = 0; i < terms.size(); i++) {

			queryT.term = terms[i];
			temp = index.getValue(queryT.term);
			cout << temp->value << endl;
		}
	}

	void Add_Doc_To_Index(string fname) {
		DLL<string> str;
		string s;
		string tstr;
		node<string>* aux;
		node<string>* aux1;
		MapNode<Term_Info>* inAUx;
		MapNode<Term_Info>* ti;
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
		//ti = index.root;

		aux1 = aux;
		//Logic same as creating document. Read all words and store them in index and later we search through
		while (aux != nullptr) {
			Doc_Info di;
			Term_Info x;
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
			//this loop indicates if word is already indexed or not.

			x.term = aux->data;
			MapNode<Term_Info>* temp = index.getValue(x.term);
			if (temp != NULL) {
				if (temp->value.docList.head->data.getDocID() != di.getDocID())
					temp->value.docList.insert_at_start(di);
			}
			else {
				if (di.gettf() != 0) {
					x.docList.insert_at_start(di);
					index.insert(x.term, x);
				}
			}
			aux = aux->next;
		}


	}
	



	~Search_Engine() {
		index.~mymap();
	}


};
