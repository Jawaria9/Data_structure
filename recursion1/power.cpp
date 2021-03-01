#include<iostream>
using namespace std;

int calculate_power(int number,int exponent){  
    //base case     
    if(exponent==0){
        return 1;
    }

    //induction hypothesis

    int small_output1=calculate_power(number,exponent-1);

    //induction step

    return number*small_output1;

}


int main(){
   cout<<calculate_power(5,3);
}                                                          