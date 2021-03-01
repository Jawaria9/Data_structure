#include<iostream>
using namespace std;

void countoccurencesofelement(int a[],int n,int element,int i,int &count){
    if(i==n){
        return 0;
    }
    if(a[i]==element){
        count++;
    }


    printalloccurencesofelement(a,n,element,i+1,count);
    
}

int main(){
  int count=0;
  int a[] = {1,4,3,3,4};
  printalloccurencesofelement(a,5,4,0,count);
  cout<<count;

}