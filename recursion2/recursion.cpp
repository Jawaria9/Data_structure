#include<iostream>
#include<limits.h>
using namespace std;


int factorial_function(int n){
    if(n<0){
        return -1;
    }
    if(n==0) {
       return 1;
    }
    int mini_factorial=factorial_function(n-1);
    return mini_factorial*n;
}
int main(){
   cout<<factorial_function(5);
}