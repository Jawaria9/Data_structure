#include<iostream>
using namespace std;

int sumofdigits(int number){
    if(number==0){
        return 0;
    }
    int smaller_sum=sumofdigits(number/10);

    return smaller_sum+number%10;
}
int main(){

  cout<<sumofdigits(12345);
}