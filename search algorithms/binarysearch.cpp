#include<iostream>
#include<limits.h>
using namespace std;

//binarysearch is only for sorted array
int binary_search(int myarray[],int mysize,int mykey){
    int start_index=0;
    int end_index=mysize-1;
    int mid_index;
    while(start_index<=end_index){
         mid_index=(start_index)+(end_index-start_index)/2;

         if(mykey==myarray[mid_index]){
             return mid_index;
         }
         else if(mykey<myarray[mid_index]){
             end_index=mid_index-1;
         }
         else{
             start_index=mid_index+1;
         }

    }
    return -1;

}

int main(){
    int array[9]={1,2,3,4,5,6,7,8,9};
    int size=9;
    int key=6;

    cout<<binary_search(array,size,key);
}