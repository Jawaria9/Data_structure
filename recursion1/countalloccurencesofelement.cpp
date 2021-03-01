#include<iostream>
using namespace std;

void countalloccurencesofelement(int a[],int n,int element,int i,int &count){
    if(i==n){
        return;
    }
    if(a[i]==element){
        count++;
    }


    countalloccurencesofelement(a,n,element,i+1,count);
    
}

int main(){
  int count=0;
  int a[] = {1,4,3,3,4};
  countalloccurencesofelement(a,5,4,0,count);
  cout<<count;

}