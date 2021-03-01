#include<iostream>
using namespace std;

int storeallposition(int a[],int n,int element,int i,int j,int *newarray){
    if(i==n){
        return 0;
    }
    if(a[i]==element){
        newarray[j]=i;
        j++;
        return 1+storeallposition(a,n,element,i+1,j,newarray);
    }
    else{
    return storeallposition(a,n,element,i+1,j,newarray);
    }

}

int main(){
  int j=0;
  int *newarray=new int[5];
  int a[] = {1,4,3,3,4};
  int count=storeallposition(a,5,4,0,j,newarray);
  for(int i=0;i<count;i++){
      cout<<newarray[i]<<" ";
  }
  }