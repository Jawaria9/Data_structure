#include<iostream>
using namespace std;

void replace_char_recursively(char array[],char character,char changer){
    if(array[0]=='\0'){
        return ;
    }
    if(array[0]==character){
        array[0]=changer;

    }
    
    replace_char_recursively(array+1,character,changer);

}

int main(){
    char character='a';
    char changer='x';
    char a[]="abcad";
    replace_char_recursively(a,character,changer);
    cout<<a;
}