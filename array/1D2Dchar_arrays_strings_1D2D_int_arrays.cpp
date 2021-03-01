#include<iostream>
using namespace std;

int main() {



	//////////////////1D int array///////////////////////////////////////////////////////////////////////////////


	//int a[4] = { 1,2,3,4};



	//int a[10];
	//for (int i = 0; i < 10; i++) {
	//	cout << a[i];
	//}



	/*int a[10] = { 1,2,3,4};
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}*/



	//a[] is wrong


	//int b;
	//cout << sizeof(b);



	//int a[10] = { 1,2,3 };
	//cout << sizeof(a);



	/////////////////////sum of element in array//////////////////////


	/*int size;
	int sum = 0;
	cout << "enter the size of array:" << endl;
	cin >> size;
	int array[size];
	for (int i = 0; i < size; i++) {
		cout << "enter the " << i << " element:"<<endl;
		cin >> array[i];
	}

	for (int i = 0; i < size; i++) {
		sum += array[i];
	}*/



	///////////////////////largest value in array//////////////////

	//int size;
	//cout << "enter the size of array:" << endl;
	//cin >> size;
	//int array[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "enter the " << i << " element:"<<endl;
	//	cin >> array[i];
	//}
	//int largest = INT_MIN;
	//for (int i = 0; i < size; i++) {
	//	if (array[i] > largest) {
	//		largest = array[i];
	//	}
	//}
	//cout << largest << " is largest" << endl;
	//


	/////////////////////smallest value in array///////////////////

	//int size;
	//cout << "enter the size of array:" << endl;
	//cin >> size;
	//int array[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "enter the " << i << " element:"<<endl;
	//	cin >> array[i];
	//}
	//int smallest = INT_MAX; 
	//for (int i = 0; i < size; i++) {
	//	if (array[i] < smallest) {
	//		smallest = array[i];
	//	}
	//}
	//cout << smallest << " is smalllest" << endl;
	//


	////////////////////swap two varaible by temp////////////////////

	/*int a = 5;
	int b = 8;
	int swapper = a;
	a = b;
	b = swapper;
	cout << a << " " << b << endl;*/

	  
////////////swapping by zore method//////////////
     //   int a = 5;
	 //int b = 7;
	 //a = a ^ b;
	 //b = a ^ b;
	 //a = a ^ b;
	 //cout << a << " " << b << endl;

/////////////swapping by using swap method/////////////////

	// int a = 5;
	//int b = 7;
    //swap(a, b);



//////////////////////printing aarray in reverse order///////////////

   //int a[4] = { 1,2,3,4};
   //for (int i = 3; i>=0; i--) {
	  // cout << a[i];
   //}


///////////reverse the array/////////////////

   
  /* int a[4] = { 1,2,3,4};
   int length = 4;
   int indexlength = length - 1;
   int mid = (indexlength / 2);
   int temp;
   for (int i = 0; i <=mid; i++) {
	   temp = a[indexlength - i];
	   a[indexlength - i] = a[i];
	   a[i] = temp;
   }
   for (int i = 0; i <=indexlength; i++) {
	   cout << a[i];
   }*/

////////////rverse array using swap ////////////////////



//	int size;
//	cout << "enter the size of array:" << endl;
//	cin >> size;
//	int array[size];
//	for (int i = 0; i < size; i++) {
//		cout << "enter the " << i << " element:" << endl;
//		cin >> array[i];
//	}
//	int start = 0;
//	int end = size - 1;
//
//	while (start < end) {
//		swap(array[start], array[end]);
//		start++;
//		end--;
//
//	}
//	for (int i = 0; i < size; i++) {
//		cout << array[i];
//	}
//
//}////////////////////////////////////////////////////////strings/1 D char arrays//////////////////////////////////
    
///////////////cin char array/////////////////////

//char name[100];
//cout << "enter your name" << endl;//abc
//cin >> name;
//name[1] = '\0';
//name[3] = 'd';
//name[4] = 'x';
//cout << name;


////////////length of char array////////////////////////////

// int length(char input[]){
//     int count=0;
//     for(int i=0;input[i]!=0;i++){
//         count++;
//     }
//     return count;
// }

///we do not need to paas size i char array like integer because it will terminate at null character


// int main(){

// char name[100];
// cout<<"enter your name:"<<endl;//abc
// cin>>name;
// cout<<name<<endl;;
// cout<<length(name);

// }


////////////////////////cin limitation in char array//////////////////////////

// char name[100];
// cout<<"enter your name:"<<endl;//abc
// cin>>name;
// cout<<name<<endl;
//cin stop taking input when receieving space,tabs or new line





// char array[4];
// cout<<"enter four characters";
// cin>>array;
// cout<<array;
// //garbage will printed bcz 4rth  place was of null character but its now replaced 


//////////////////////////////////cin.getline///////////////////

//cin.getline(name,size,delimeter(optionl) and by default it is new line char)
//cin.getline will stop taking input when encounter new line
// char name[100];
// cout<<"enter your name:"<<endl;//abc
// cin.getline(name,4);
// cout<<name<<endl;


// char name[100];
// cout<<"enter your name:"<<endl;//abc
// cin.getline(name,20,'o');
// cout<<name<<endl;

  //////////////////////////////reverse a char array//////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;


// int length(char a[]){
//     int count=0;
//     for(int i=0;a[i]!='\0';i++){
//         count++;
//     }
//     return count;
// }

// void reverse(char a[]){

//     int string_length;
//     int total_index;
//     int first_index=0;
//     int last_index;

//     string_length=length(a);
//     total_index=string_length-1;
//     last_index=total_index;

//     while(first_index!=last_index){
//     swap(a[first_index],a[last_index]);
//     first_index++;
//     last_index--;
//     }

// }


// int main(){

//     char array[100];
//     cout<<"enter a string"<<endl;
//     cin.getline(array,sizeof(array));
//     reverse(array);
//     cout<<array;

// }

////////////////////////////////////////////////inbuilt function//////////////////////////////////////////////////////

///sizeof(name of array) function will calculate the whole size of char array
/// but strlen(name of array) will calcultae the size of total alphabit stored


/////////////////////////////strlen() and  sizeof() functions/////////////////////////////////
//char str1[100];
//cin >> str1;
//
//int length = strlen(str1);
//cout << length;
//
//int len = sizeof(str1);
//cout << len;

///if strcmp(str1,str2)==0 it means two strings are equal if it give some non zero value it means string are not equal


/////////////////////strcmp(str1,str2) function///////////////////////////////////////////



// int main(){

//    char str1[100];
//    char str2[100];
//    cin>>str1;
//    cin>>str2;

//   if(strcmp(str1,str2)==0){
//       cout<<"equal"<<endl;
//   }
//   else{
//       cout<<"not equal"<<endl;
//   }


////////////////////////compare without function/////////////////////////////////////////////////




// #include<iostream>
// #include<cstring>
// using namespace std;



// bool compare(char first_string[],char second_string[]){
//     if(strlen(first_string)!=strlen(second_string)){
//         return false;
//     }
//     else{
//         for(int i=0;i<strlen(first_string);i++){
//             if(first_string[i]!=second_string[i]){
//                 return false;
//             }
//         }
//     }
//     return true;

// }
// int main(){

//    char str1[100];
//    char str2[100];
//    cin>>str1;
//    cin>>str2;
//    cout<<compare(str1,str2);
// }

//////////////////////////////////////////////strcpy(destination string,source string) function///////////////////////////////////////

//string copy function also copy the null character


// int main(){

//    char str1[100]="abcd";
//    char str2[100]="defb";

//    strcpy(str1,str2);
//    cout<<str1;
// }

///////////////////////////////////string copy without function////////////////////////////



// void copyingstring2into1(char str1[],char str2[]){
//     int i=0;
//     while(str2[i]!='\0'){
//         str1[i]=str2[i];
//         i++;
//     }
//     str1[i]='\0';

// }
// int main(){

//    char str1[100]="abcd";
//    char str2[100]="defb";


// copyingstring2into1(str1,str2);
//    cout<<str1;

// }



///////////////////////////strncpy(destination string,source string,n) is a function which copies only the first n characters///////////////////////////////////

///it will not copy the null character
///n means how many first characters


// int main(){
//    char str1[100]="jhsjsakbkasjbkajsbk";
//    char str2[100]="javer";
//    strncpy(str1,str2,5);
//    cout<<str1;
// }




// int main(){
//    char str1[100]="abcd";
//    char str2[100]="xy";
//    strncpy(str1,str2,4);
//    cout<<str1;
// }

///////////////////////////////////string concatenation function strcat()///////////////////////////////

////strcat(string 1,string 2) copies the contents of string 2 after string 1 in string 1


//void copying_firstn_char_of_string2_to_string1(char str1[], char str2[]) {
//	strcat(str1, str2);
//
//}
//int main() {
//
//	char str1[100] = "abcd";
//	char str2[100] = "xy";
//	copying_firstn_char_of_string2_to_string1(str1, str2);
//	cout << str1;
//
//}

///////////////////////////////string concatenationwithout funtion////////////////////



// void copying_firstn_char_of_string2_to_string1(char str1[],char str2[]){
//     int length_of_string1=strlen(str1);
//     int length_of_string2=strlen(str2);

//     for(int i=0;i<=length_of_string2;i++){
//         str1[i+length_of_string1]=str2[i];
//     }

// }
// int main(){

//    char str1[100]="abcd";
//    char str2[100]="xy";
//    copying_firstn_char_of_string2_to_string1(str1,str2);
//    cout<<str1;

// }


/////////////////////////////print all prefixes///////////////////////////////

// #include<iostream>
// #include<cstring>
// using namespace std;


// int main(){

//    char str1[100]="javeria";

//    for(int i=0;i<strlen(str1);i++){
//        int j=0;
//        while(j<=i){
//            cout<<str1[j];
//            j++;
//        }
//        cout<<endl;
//    }


// }


/////////////////////print all sufix //////////////////////////

// #include<iostream>
// #include<cstring>
// using namespace std;


// int main(){

//    char str1[100]="javeria";
//    for(int i=strlen(str1)-1;i>=0;i--){
//        int j=strlen(str1)-1;
//        while(j>=i){
//            cout<<str1[j];
//            j--;
//        }
//        cout<<endl;
//    }
// }


/////////////////////////input in 2d array//////////////////////


//int main() {
//	int a[5][3];
//	for (int i = 0; i < 5; i++) {
//		for (int j = 0; j < 3; j++) {
//			cin >> a[i][j];
//		}
//	}
//
//}

///////////////print 2d array row wise///////////

//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 5; j++) {
//		cout << a[j][i];
//	}
//	cout << endl;
//}


/////////////printing 2d array column wise///////////

//for (int i = 0; i < 5; i++) {
//	for (int j = 0; j < 3; j++) {
//		cout << a[i][j];
//	}
//}


/////////////////row size is optional but column size is mendatory////////////

///like 1D arrray all the values which rae not provided but size is given will be filled by zero
//a[4]={1,2};
//a[][3]={{1,2},{1,2,3}};
//a[10]={0};  //all the 10 values will be zero
//a[10][10]={{0}};



///////////////initializing 2D array////////////////////////////////

// #include<iostream>
// #include<cstring>
// using namespace std;
//                                           //1 2 3 
// void printingrowise(int array[][2],int rows,int cols){
//     for(int i=0;i<rows;i++){
//          for(int j=0;j<cols;j++){
//              cout<<array[i][j];
//     }
//         cout<<endl;
// }
// }                                       
// int main(){
//     int a[][2]={{1,2},{3,4}};
//    printingrowise(a,2,2);
// }



////////no of colomns are mendatory to give in function while rows are optional
//a[i][j]=i*c+j
//c=cols
///////////////////in function value of cols is mendaotory to paas not in variable form but in number form///////////////////////////////////////////////////


// #include<iostream>
// #include<cstring>
// using namespace std;

// void printingrowise(int array[][5],int rows,int cols){

//     for(int i=0;i<rows;i++){
//          for(int j=0;j<cols;j++){
//              cout<<array[i][j];
//     }
//         cout<<endl;
// }
// }                                      
// int main(){
//     int r,c;
//     int a[][5];
//     cin>>r>>c;
//     printingrowise(a,r,c);  
// }


/////////////////////////////////////////////////////////////////////////////////////////////strings////////////////////////////////////////////////////////////////////////////


//// #include<iostream>
// #include<cstring>
// using namespace std;
                                          
                               
// int main(){

//     string s="abc";
//     cout<<s<<endl;
//     string s1;
//     s1="def";
//     cout<<s1<<endl;

//     //////string intilazing dynamically/////////

//     string *sp=new string;
//     *sp="javeria";
//     cout<<*sp<<endl;


    
 
// }

////////////////////////////////////////////////vector of string as a 2D array////////////////////////////////////////

//    vector<string>v; is used in place of 2D char array


///// #include<iostream>
// #include<vector>
// using namespace std;
                                          
                               
// int main(){

//     string s="abc";
//     string s1;
//     s1="def";
//     vector<string>v;
//     v.push_back(s);
//     v.push_back(s1);
//     v.push_back("javeria");

//     for(int i=0;i<v.size();i++){
//         cout<<v[i]<<endl;;
//     }
// }

/////////////////////function sort()//////////////////////////

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;


// int main(){

//     string s="abc";
//     string s1;
//     s1="def";
//     vector<string>v;
//     v.push_back(s);
//     v.push_back(s1);
//     v.push_back("javeria");
//     for(int i=0;i<v.size();i++){
//         sort(v[i].begin(),v[i].end());
//         cout<<v[i]<<endl;
//     }
// }


////////////////////////////taking input in string///////////////////////////

//string s3;
//getline(cin, s3);
//no need to worry about length  or null character in strings
//strings can be treated as an array

// #include<iostream>
// using namespace std;

// int main(){

//     string s3;
//     getline(cin, s3);
//     cout<<s3;
//     cout<<'\n';
//     cout<<s3[2];
//     cout<<'\n';
//     s3[0]='D';
//     cout<<s3;
// }


//////////////////string concatenation///////////////////////

//#include<iostream>
//using namespace std;
//int main() {
//	string s3 = "hjjjj";
//	string s2 = "ghvh";
//	string s = s3 + s2+"hello;
//	cout << s;
//}



// #include<iostream>
// using namespace std;
// int main(){
//     string s3="hjjjj";
//     string s2="ghvh";
//     string s="";
//     s+=s3+s2+"hello";
//     cout<<s;
// }

//////////////////////////////size() and length() functions of string//////////////////////////

// #include<iostream>
// using namespace std;
// int main(){
//     string s3="hjjjj";
//     string s2="ghvh";
//     string s="";
//     s+=s3+s2+"hello";
//     cout<<s;
//     cout<<'\n';
//     cout << s.size() << '\n' << s.length();
// }

///////////////////substr(index) function of string//////////////////////////////////

//starting from index including index onward this function will give everything

// #include<iostream>
// using namespace std;

// int main(){

//     string s3="javeria";
//     string s2=" shahzadi";
//     string s="";
//     s+=s3+s2+" hello";
//     cout<<s;
//     cout<<'\n';
//     cout << s.size() << '\n' << s.length();
//     cout<<'\n';
//     cout<<s.substr(4);
// }

//////////////////////substr(starting index,how many characters)////////////////

// #include<iostream>
// using namespace std;

// int main(){

//     string s3="javeria";
//     string s2=" shahzadi";
//     string s="";
//     s+=s3+s2+" hello";
//     cout<<s;
//     cout<<'\n';
//     cout << s.size() << '\n' << s.length();
//     cout<<'\n';
//     cout<<s.substr(4,6);
// }

///////////////////////////find(substring) function of string////////////////////////////////

//this function will return the index where the first time first letter of the substring starts and other other consectively in original string

// #include<iostream>
// using namespace std;

// int main(){

//     string s3="javeriaabcabcabc";
//     string s2=" shahzadiabc";
//     string s="";
//     s+=s3+s2+" hello";
//     cout<<s;
//     cout<<'\n';
//     cout << s.size() << '\n' << s.length();
//     cout<<'\n';
//     cout<<s.substr(4,6);
//      cout<<'\n';
//     cout<<s.find("abc");
// }


////////////////////////////converting integer into string function is "to_string(integer)"///////////////


// #include<iostream>
// #include<string>
// using namespace std;

// int main(){

//   int i=798;
//   string str=to_string(i);
//   cout<<str;
//   cout<<'\n';
//   str[0]='8';
//   cout<<str;
// }


/////////////////////converting string to integer function is "atoi(string.c_str())" /////////////////////////////


// #include<iostream>
// #include<string>
// using namespace std;

// int main(){

//   int i=798;
//   string str=to_string(i);
//   cout<<str;
//   cout<<'\n';
//   str[0]='8';
//   cout<<str;
//   cout<<'\n';
//   int integer=atoi(str.c_str());
//   cout<<integer;
// }

////////////////////////////"push_back()" is the function to insert element in a string at the end/////////////////


// #include<iostream>
// #include<string>
// using namespace std;

// int main(){

//   int i=798;
//   string str=to_string(i);
//   str.push_back('6');
//   cout<<str;


// }




