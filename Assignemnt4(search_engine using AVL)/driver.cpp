#include<iostream>
#include<fstream>
#include<string>
#include"Search-Engine.h"
using namespace std;

int main()
{

	Search_Engine a;
	string s[5] = { "doc2.txt" ,"doc5.txt", "doc3.txt" , "doc4.txt" };
	a.createIndex(s, 4);
	a.searchQuery("data structure ");
	cout << "after Adding Query." << endl;
	a.Add_Doc_To_Index("doc1.txt");
	a.searchQuery("data structure ");
	return 0;
}