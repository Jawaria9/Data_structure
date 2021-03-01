#include<iostream>
using namespace std;

int fibo(int n){
    //base case
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    //hypothesis induction
    int small_output1=fibo(n-1);
    int small_output2=fibo(n-2);

    //induction step
    return small_output1+small_output2;


}
int main(){
    int f=4;
    cout<<fibo(f);
}