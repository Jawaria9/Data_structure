#include<iostream>
using namespace std;

void storeallposition(int a[],int n,int element,int i,int &j,int *newarray){
    if(i==n){
        return;
    }
    if(a[i]==element){
        newarray[j]=i;
        j++;
    }
    storeallposition(a,n,element,i+1,j,newarray);

}

int main(){
  int j=0;
  int *newarray=new int[5];
  int a[] = {1,4,3,3,4};
  storeallposition(a,5,4,0,j,newarray);
  for(int i=0;i<j;i++){
      cout<<newarray[i]<<" ";
  }
  }


