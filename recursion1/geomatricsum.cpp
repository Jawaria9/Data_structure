#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double geometric_sum(int exponent){
    if(exponent==0){
        return 1;
    }

    double sum=geometric_sum(exponent-1);


    return sum+1.0/pow(2,exponent);



}

int main(){
    cout<<geometric_sum(3);

}