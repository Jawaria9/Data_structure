#include<iostream>
using namespace std;

bool check_if_element_present(int array[],int size,int element,int i){
    if(i==size){
        return false;
    }
    if(array[i]==element){
        return true;
    }

    return check_if_element_present(array,size,element,i+1);
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<check_if_element_present(arr,5,9,0);
}