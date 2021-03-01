#include<iostream>
using namespace std;

void remove_char_recursively(char array[],char character){
    if(array[0]=='\0'){
        return;
    }
    if(array[0]==character){
        for(int i=0;array[i]!='\0';i++)
            array[i]=array[i+1];
            remove_char_recursively(array,character);
        }
    else{
        remove_char_recursively(array+1,character);

    }

}

int main(){
    char character='a';
    char a[]="abcad";
    remove_char_recursively(a,character);
    cout<<a;
}