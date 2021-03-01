//address of the array is the same as adress of the first item in array
//name of the array is also the address of the array
//char array and a char pointer are same

//str1[]="hey me"
//*str2="hello world"

//here str2 is the address of the string "hello world" and also str2 is hello world"
//str1 and &str1 are same as both are address
//but str2 and &str2 are not same  str2 is  the address of the string and also "hey me" but &str2 is the address of the pointer
//str2=&str1 now str2 is the adres of helllo world and is hello world also
//str2=str1 same thing

// #include<iostream>
// using namespace std;

// int main(){
//     int data[3]={0,1,2};
//     int *p;
//     int **ppi;
//     p=data;
//     ppi=&p;
//     for(int i=0;i<3;i++){
//         cout<<"data:"<<data;
//         cout<<'\n';
//         cout<<"*p:"<<*p;
//         cout<<'\n';
//         cout<<"&data=data:"<<&data<<"="<<data;
//         cout<<'\n';
//         cout<<"*ppi=data or p:"<<*ppi<<"="<<data;
//         cout<<'\n';
//         cout<<"**ppi=data[i] or *p:"<<**ppi<<"="<<*p<<"="<<data[i];
//         cout<<'\n';

//         p++;
//     }
// }


//increment of +1 in p means ncrement of +4 in address which is p  but not &p
//&p remains same all the time
//*p changes and p changes