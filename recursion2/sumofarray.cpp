#include<iostream>
using namespace std;

int sum_of_array(int array[],int size){
    if(size==0){
        return 0;
    }
    int sum=sum_of_array(array,size-1);
    
    return sum+array[size-1];
}
int main(){
    int arr[5]={1,2,3,4,5};
    int ans=sum_of_array(arr,5);
    cout<<ans;
}