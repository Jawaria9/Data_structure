#include<iostream>
using namespace std;

class stack{
private:

int *array;
int nextindex;
int capacity;

public:

stack(){
array=new int[capacity];
nextindex=0;
capacity=4;
}

stack(int capacity){
array=new int[capacity];
nextindex=0;
this->capacity=capacity;
}


void push(int element){
if(nextindex==capacity){
cout<<"stack is full";
}
else{
array[nextindex]=element;
nextindex++;
}
}

void pop(){
if(isempty()){
cout<<"stack is empty";
}
else{
nextindex--;
}
}

int top(){
if(size()==0){
cout<<"stack is empty";
}
else{
return array[nextindex-1];
}
}

int size(){
return nextindex-1;
}
bool isempty(){
  return nextindex==0;
}

};

int main(){
    stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<endl;

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.top();
    s.pop();
    cout<<endl;

    cout<<s.size();
    cout<<endl;

    cout<<s.isempty();
    cout<<endl;

    stack s2(10);
    for(int i=0;i<10;i++){
        s2.push(i);
    }
    while(!s2.isempty()){
        cout<<s2.top();
    }

    


}