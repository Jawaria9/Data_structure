#include<iostream>
using namespace std;

bool checkpalindrom(int array[],int start,int end){
    if(start>end){
        return true;
    }

    if(array[start]==array[end]){
        return checkpalindrom(array,start+1,end-1);
    }
    else{
        return false;
    }
}

int main(){
    int a[5]={1,2,3,2,1};
    cout<<checkpalindrom(a,0,4);

}