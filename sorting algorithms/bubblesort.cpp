#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int array[5]={1,2,9,7,6};
    for(int i=1;i<5;i++){
        for(int j=0;j<4;j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
        }
    }
    for(int i=0;i<5;i++){
        cout<<array[i];
    }
}