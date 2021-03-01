#include<iostream>
using namespace std;


int print_numbers(int number){
    if(number==0){
        return 0;
    }


    int min_print=print_numbers(number-1);
    cout<<min_print+1;


    return min_print+1;

}
int main(){
       print_numbers(5);

}