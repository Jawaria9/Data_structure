#include<iostream>
using namespace std;

void printallpositionsofelement(int a[],int n,int element,int i){
    if(i==n){
        return;
    }
    if(a[i]==element){
            cout<<i<<" ";
    }


    printallpositionsofelement(a,n,element,i+1);
    
}

int main(){
  int a[] = {1,4,3,3,4};
  printallpositionsofelement(a,5,4,0);

}