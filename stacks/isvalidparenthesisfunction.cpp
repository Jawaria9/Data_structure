#include<iostream>
#include<stack>
using namespace std;

bool idvalidparenthesis(string str){
   stack<int> s;
   for(int i=0;i<str.size();i++){
       if(str[i]=='(' || str[i]=='{'  ||  str[i]=='['){
           s.push(str[i]);
       }
       else{
           if(s.empty()){
               return false;
           }
           else{
               if(str[i]==')'){
                   if(s.top()=='('){
                       s.pop();
                   }
               }
                if(str[i]=='}'){
                    if(s.top()=='{'){
                        s.pop();
                    }
                }     
                if(str[i]==']'){
                   if(s.top()=='['){
                       s.pop();
                   }  
               }
           }
       }
   }
   if(s.empty()){
       return true;
   }
   else{
       return false;
   }

}

int main(){
    string a="{[()}";
    cout<<idvalidparenthesis(a);
    
}