#include<iostream>
using namespace std;

bool check_if_element_present(int array[],int size,int element,int i){
    if(i==size){
        return false;
    }

    bool check=check_if_element_present(array,size,element,i+1);

    if(!check){
        return array[i]==element;
    }
    else
    {
        return check;
    }
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<check_if_element_present(arr,5,9,0);
}