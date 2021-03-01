#include<iostream>
using namespace std;

int numberofdigits(int number){
    if(number==0){
        return 0;
    }
    int count=numberofdigits(number/10);
    
    return count+1;
    
}
int main(){
    cout<<numberofdigits(45645654);

}