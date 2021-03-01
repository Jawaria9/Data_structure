#include<iostream>
using namespace std;

int firstIndex(int a[],int n,int element){
    if(n==0){
        return -1;
    }
    if(a[n]==element){
        return n;
    }
    return firstIndex(a,n-1,element);
}

int main(){
  int a[] = {1,4,3,3,4};
  cout<<firstIndex(a,5,3);
  return 0;
}
