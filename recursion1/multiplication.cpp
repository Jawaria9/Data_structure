#include<iostream>
using namespace std;

int multiplication(int number,int multiplier){
    if(multiplier==0){
        return 0;
    }

    int sum=multiplication(number,multiplier-1);

    return number+sum;

}

int main(){
    cout<<multiplication(6,8);

}