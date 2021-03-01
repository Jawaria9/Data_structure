#include<iostream>
using namespace std;

void reverseprint_char_array_recursively(char array[]){
    if(array[0]=='\0'){
        return;
    }
    reverseprint_char_array_recursively(array+1);
    cout<<array[0];
}

int main(){
    char a[]="abcd";
    reverseprint_char_array_recursively(a);

}