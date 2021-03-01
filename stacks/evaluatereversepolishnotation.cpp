#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;


int reverse_polish_notation(string post_fix[4]){
   stack<int> s;
   for(int i=0;i<post_fix.size();i++){
       if(post_fix[i]=='+' ){
           int number1=s.top();
           s.pop();
           int number2=s.top();
           s.pop();
           s.push(number2+number1);
       }
       if(post_fix[i]=='-' ){
           int number1=s.top();
           s.pop();
           int number2=s.top();
           s.pop();
           number1=number2-number1;
           s.push(number1);
       }
       if(post_fix[i]=='*'){
           int number1=s.top();
           s.pop();
           int number2=s.top();
           s.pop();
           number1=number2*number1;
           s.push(number1);
       }
       if( post_fix[i]=='/'){
           int number1=s.top();
           s.pop();
           int number2=s.top();
           s.pop();
           number1=number2/number1;
           s.push(number1);
       }
       else{
       s.push(atoi(post_fix[i].c_str()));
       }
   }
   return s.top();
}
int main(){
    string a[4]={"4","1","5","/","*"};
    cout<<reverse_polish_notation(a);
}
