#include<iostream>
using namespace std;

void remove_consectiveduplicates_recursively(char array[]){
    if(array[0]=='\0'){
        return;
    }
    if(array[0]==array[1]){
        for(int i=0;array[i]!='\0';i++)
            array[i]=array[i+1];
            remove_consectiveduplicates_recursively(array);
        }
    else{
       remove_consectiveduplicates_recursively(array+1);

    }

}

int main(){
    char a[]="aabbccad";
    remove_consectiveduplicates_recursively(a);
    cout<<a;
}