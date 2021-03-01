#include<iostream>
using namespace std;

int lastIndex(int a[],int n,int element,int i){//either remove n or i because botha are doing the same work
    if(i<0){
        return -1;
    }
    if(a[i]==element){
        return i;
    }
    return lastIndex(a,n,element,i-1);
}

int main(){
  int a[] = {1,4,3,3,4};
  cout<<lastIndex(a,5,4,4);
  return 0;
}