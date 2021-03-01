#include<iostream>
#include<limits.h>
using namespace std;

//linear search do no take into consideration whether the given array is sorted or unsorted

int linearsearch(int myarray[],int mysize,int mykey){
    for(int i=0;i<mysize;i++){
        if(myarray[i]==mykey){
            return i;
        }
    }
    return -1;

}

int main(){
    int array[6]={1,2,3,4,5,6};
    int key=4;
    int size=6;
    cout<<linearsearch(array,size,key);

}