#include<iostream>
using namespace std;

void reverseprint_char_array_recursively(char array[],int i){
    if(i==-1){
        return;
    }
    cout<<array[i];
    reverseprint_char_array_recursively(array,i-1);

}

int main(){
    char a[]="abcd";
    reverseprint_char_array_recursively(a,3);

}