#include<iostream>
using namespace std;

int lastIndex(int a[],int n,int element,int i){
    if(i==n){
        return -1;
    }

    int index= lastIndex(a,n,element,i+1);
    if(index==-1){
        if(a[i]==element){
            return i;
    }
        else{
            return -1;
        }

    }
    else{
        return index;
    }
}

int main(){
  int a[] = {1,4,3,3,4};
  cout<<lastIndex(a,5,4,0);

}