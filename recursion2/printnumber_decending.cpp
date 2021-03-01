#include<iostream>
using namespace std;


int print_numbers(int number){
    if(number==1){
        return 1;
    }

    cout<<number ;
    print_numbers(number-1);

}

int main(){
       cout<<print_numbers(5);

}