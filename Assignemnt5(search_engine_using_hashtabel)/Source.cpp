#include"Search-Engine.h"

using namespace std;

int main()
{


	Search_Engine se;
	string s[2] = { "doc1.txt", "doc2.txt" };
	se.Create_Index(s,2);
	se.Search_Query("breakthough");







	return 0;
}