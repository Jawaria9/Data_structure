#include<iostream>
using namespace std;

void printrecursively(char array[]){
    if(array[0]=='\0'){
        return;
    }
    cout<<array[0];
    printrecursively(array+1);
}

int main(){
    char a[]="abcd";
    printrecursively(a);

}