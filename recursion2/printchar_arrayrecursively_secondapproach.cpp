#include<iostream>
using namespace std;

void printrecursively(char array[],int i){
    if(array[i]=='\0'){
        return;
    }
    cout<<array[i];
    printrecursively(array,i+1);
}

int main(){

    char a[]="abcd";
    printrecursively(a,0);

}