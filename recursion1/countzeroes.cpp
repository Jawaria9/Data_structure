// #include<iostream>
// using namespace std;

// int countzeroes(int number){
//     if(number==0){
//         return 0;
//     }

//     int zerocounter=countzeroes(number/10);

//     if(number%10==0){
//         return zerocounter+1;
//     }
//     else{
//         return zerocounter;
//     }

// }

// int main(){

//     cout<<countzeroes(102000039);

// }





#include<iostream>
using namespace std;

void countzeroes(int number,int &count){

    if(number==0){
        return;
    }

    if(number%10==0){
        count++;
    }

    return countzeroes(number/10,count);
 

}

int main(){
 int count=0;
 countzeroes(102000039,count);
 cout<<count;

}