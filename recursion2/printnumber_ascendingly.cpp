#include<iostream>
using namespace std;


int print_numbers(int number){
    if(number==0){
        return 0;
    }


    print_numbers(number-1);

    

    cout<<number ;



    

}

int main(){
       print_numbers(5);

}