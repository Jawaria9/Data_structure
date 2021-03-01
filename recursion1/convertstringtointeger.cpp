#include<iostream>
using namespace std;

int length(char input[]){
    if(input[0]=='\0'){
        return 0;
    }
    return 1 + length(input+1);;
}

int convertStringToInt(char str[], int n){
     if(n==0){
        return 0;
     }
     int lastDigit = str[n-1] - '0';
     return lastDigit+convertStringToInt(str, n-1)*10;
}

int main(){
  char str[] = "12345";
  int n = length(str);

  int a = convertStringToInt(str,n);
  cout<<a<<endl;

  return 0;
}