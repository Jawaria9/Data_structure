#include<iostream>
using namespace std;

int lengthof_char_array_recursively(char array[]){
    if(array[0]=='\0'){
        return 0;;
    }
    
    return 1+lengthof_char_array_recursively(array+1);

}

int main(){
    char a[]="abcd";
    cout<<lengthof_char_array_recursively(a);
}