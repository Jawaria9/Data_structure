#include<iostream>
using namespace std;

int sum_of_array(int array[],int size,int i){
    if(i==size){
        return 0;
    }
    int sum=sum_of_array(array,size,i+1);
    
    return sum+array[i];
}
int main(){
    int arr[5]={1,2,3,4,5};
    int ans=sum_of_array(arr,5,0);
    cout<<ans;
}