#include<iostream>
#include<vector>
using namespace std;

void storeallposition(int a[],int n,int element,int i,vector<int> &ans){
    if(i==n){
        return;
    }
    if(a[i]==element){
        ans.push_back(i);
    }
    storeallposition(a,n,element,i+1,ans);

}


int main(){
  int a[] = {5,5,6,5,6,7};
  vector<int> v;

  storeallposition(a,6,6,0,v);
  for(int j=0;j<v.size();j++){
      cout<<v[j]<<" ";
  }

  
  
  }