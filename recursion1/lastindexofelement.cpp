#include<iostream>
using namespace std;

int lastIndex(int a[],int n,int element){
    if(n==0){
        return -1;
    }
    if(a[n-1]==element){
        return n-1;
    }
    return lastIndex(a,n-1,element);
}

int main(){
  int a[] = {1,4,3,3,4};
  cout<<lastIndex(a,5,3);
  return 0;
}
