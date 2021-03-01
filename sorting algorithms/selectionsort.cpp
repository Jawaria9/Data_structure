#include<iostream>
#include<limits.h>
using namespace std;

//does'nt matter array is integer or char it is passed to function by reference
int main(){
    int array[5]={1,2,9,7,6};
    int minimum_index;
    for(int i=0;i<4;i++){
        minimum_index=i;
        for(int j=i+1;j<5;j++){
            if(array[j]<array[minimum_index]){
               minimum_index=j;
            }
        }
            swap(array[i],array[minimum_index]);
        }

    for(int i=0;i<5;i++){
        cout<<array[i];
    }
}
