#include<iostream>
using namespace std;

void reverseprint_char_array_recursively(char array[]){
    if(array[0]=='\0'){
        return;
    }
    printrecursively(array+1);
    cout<<array[0];
}

int main(){
    char a[]="abcd";
    printrecursively(a);

}