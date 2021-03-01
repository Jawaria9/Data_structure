#include<iostream>
using namespace std;

void remove_char_recursively(char array[],char character,int i,int j){
    if(array[i]=='\0'){
        return;
    }
    if(array[i]==character){
        j=i;
        while(array[j]!='\0'){
            array[j]=array[j+1];
            j++;
        }
    }
    
    remove_char_recursively(array,character,i+1,j);

}

int main(){
    char character='a';
    char a[]="abcad";
    int j=0;
    remove_char_recursively(a,character,0,j);
    cout<<a;
}