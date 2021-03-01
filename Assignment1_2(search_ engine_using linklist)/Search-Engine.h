#pragma once
#include"DLL.h"
#include"Term_Info.h"
#include<fstream>
class Search_Engine {
	DLL<Term_Info> index;
public:
	Search_Engine() {}

	void createIndex(string* fname, int n) {
		int c = 1;

		Node<string>* aux;
		Node<string>* aux1;

		Node<Term_Info>* inAux;
		Node<Term_Info>* tempInfo;

		string fileName;
		string tstr;

		bool check = 0;
		DLL<string> fList;
		Term_Info tmIn;
		ifstream fin;
		for (int i = 0; i < n; i++) {
			//reading file
			fin.open(fname[i]);
			if (fin.is_open()) {
				while (!fin.eof()) {
					fin >> fileName;
					fList.insertAtStart(fileName);
				}
				fin.close();
			}
			else {
				cout << "File ERR...!" << endl;
			}

			aux = fList.head; // auxilary pointer to the head of document name list 
			tempInfo = index.head; // temp for head node of index 

			// aux is referring to auxillary pointer
			while (aux != nullptr) {
				Doc_Info di;
				c = 1; //c is total number of frequencies
				tstr = aux->data;
				aux1 = fList.head;
				// This loop is checking the occurences of whole word in one file.
				while (aux1 != nullptr) {
					if (tstr == aux1->data && aux1 != aux) {
						c++;
					}
					aux1 = aux1->next;
				}

				int id = 0; // id of doc
				int j = 0;
				while (j < fname[i].length()) { // this loop will look for document id
					if (fname[i][j] >= 48 && fname[i][j] <= 57) {
						id = fname[i][j] - 48;
						j = fname[i].length();
					}
					j++;
				}
				di.set(id, c); // updating  doc_info object with new info
				inAux = index.head;

				//this loop indicates if word is already indexed or not.
				Node<Term_Info>* conNode = nullptr; //node containing final place where we should insert or update data;
				while (inAux != nullptr) {
					if (check != 1) {
						if (inAux->data.term == tstr) {
							check = 1;
							conNode = inAux;
						}
						inAux = inAux->next;
					}
					if (check == 1) {
						inAux = nullptr;
					}
				}

				if (check == 0) {
					tmIn.set(tstr, di);
					index.insertAtStart(tmIn);
				}
				else {
					conNode->data.set(tstr, di);
				}
				aux = aux->next;
				check = 0;
			}
			fList.clear();
		}
	}

	void searchQuery(string inStr) {
		DLL<string> terms;
		string qn; // query name
		//this is to tokenixze the string
		for (int i = 0; i < inStr.length(); i++) {
			if (inStr[i] == ' ' || inStr[i] == '\n') {
				terms.insertAtStart(qn);
				qn.clear();
			}
			else {
				qn = qn + inStr[i];
			}
		}
		Node<Term_Info>* auxIn = index.head; // aucillary pointer to the start of index 
		Node<string>* auxQ = terms.head; // aucillary pointer to the start of query
		DLL<Doc_Info> final; // answer
		Doc_Info doIn; // doc_info auxillary var
		Node<Doc_Info>* dt = nullptr; // auxillary node to doc_info
		bool check = 0;
		while (auxQ != nullptr) {
			while (auxIn != nullptr) {
				if (auxIn->data.term == auxQ->data) {
					Node<Doc_Info>* auxD = auxIn->data.docList.head; // start of doc list of queires
					// loop searching if word already exist in final list
					while (auxD != nullptr) {
						bool flag = final.search(auxD->data, dt);

						if (final.head != nullptr && flag) { //
							int docid = auxD->data.getDocID();
							int termF = auxD->data.gettf() + dt->data.gettf();

							doIn.set(docid, termF);
							final.update(doIn);
						}
						else {
							final.insertAtStart(auxD->data);
						}
						dt = nullptr;
						auxD = auxD->next;

					}
				}
				auxIn = auxIn->next;
			}
			auxIn = index.head;
			auxQ = auxQ->next;

		}

		int len = final.length();
		dt = final.head;
		Doc_Info* arr = new Doc_Info[len];
		for (int i = 0; i < len; i++) { // adding list to array to apply sorting 
			arr[i] = dt->data;
			dt = dt->next;
		}

		for (int i = 0; i < len - 1; i++) { // Last i elements are already in place  
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j].gettf() < arr[j + 1].gettf()) {
					Doc_Info aux = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = aux;
				}
			}
		}

		cout << "IDs of documents containing searched queries are following." << endl;

		for (int i = 0; i < len; i++) {
			arr[i].print();
		}
	}

	void Add_Doc_To_Index(string fname) {
		DLL<string> str;
		string s;
		string tstr;
		Node<string>* aux;
		Node<string>* aux1;
		Node<Term_Info>* inAux;
		Node<Term_Info>* ti;
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
				str.insertAtStart(s);
			}
			fin.close();
		}
		aux = str.head; // head of list containing strings of current file
		ti = index.head;

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
			inAux = index.head;
			//this loop indicates if word is already indexed or not.
			while (inAux != nullptr && check != 1) {
				if (inAux->data.term == tstr) {
					check = 1;
				}
				else
					inAux = inAux->next;
			}
			if (check == 0) {
				Term_Info var(tstr, di);
				index.insertAtStart(var);
			}
			else {
				inAux->data.set(tstr, di);
			}
			aux = aux->next;
			check = 0;

		}
	}

	void print() {
		Node<Term_Info>* i = index.head;
		while (i != nullptr) {
			i->data.print();
			cout << endl;
			i = i->next;
		}
	}

	~Search_Engine() {
		index.~DLL();
	}


};
