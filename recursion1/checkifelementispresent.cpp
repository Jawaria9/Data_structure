#include<iostream>
using namespace std;

bool check_if_element_present(int array[],int size,int element){
    if(size==0){
        return false;
    }

    bool check=check_if_element_present(array,size-1,element);

    if(!check){
        return array[size-1]==element;
    }
    else
    {
        return check;
    }
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<check_if_element_present(arr,5,0);
}