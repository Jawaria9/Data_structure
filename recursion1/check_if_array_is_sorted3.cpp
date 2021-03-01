#include<iostream>
using namespace std;

bool sorted_checker(int array[],int size){
    if(size==0  || size==1){
        return true;
    }
    //we can comment this
    bool checker=sorted_checker(array,size-1);
    
    if(array[0]<array[1]){
        return checker;
        //or
        //return sorted_checker(array,size-1);
    }
    else{
        return false;
    }
}

int main(){
    int a[5]={1,2,3,4,5};
    cout<<sorted_checker(a,5);

}