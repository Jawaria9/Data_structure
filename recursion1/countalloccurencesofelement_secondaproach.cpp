#include<iostream>
using namespace std;

int countalloccurencesofelement(int a[],int n,int element,int i){
    if(i==n){
        return 0;
    }
    if(a[i]==element){
        return 1+countalloccurencesofelement(a,n,element,i+1);
    }
    else{
    countalloccurencesofelement(a,n,element,i+1);
    }
}

int main(){
  int count=0;
  int a[] = {1,4,3,3,4};
  cout<<countalloccurencesofelement(a,5,4,0);


}