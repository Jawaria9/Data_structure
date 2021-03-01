#include<iostream>
using namespace std;

template<typename T>
class stack{
private:

T *array;
int nextindex;
int capacity;

public:

stack(){
array=new T[capacity];
nextindex=0;
capacity=4;
}

void push(T element){
if(nextindex==capacity){
    T *newarray=new T[capacity*2];
    for(int i=0;i<capacity;i++){
        newarray[i]=array[i];
    }
    capacity=capacity*2;
    delete []array;
    array=newarray;
}
array[nextindex]=element;
nextindex++;

}

void pop(){
if(isempty()){
cout<<"stack is empty";
}
else{
nextindex--;
}
}

T top(){
if(size()==0){
cout<<"stack is empty";
}
else{
return array[nextindex-1];
}
}

int size(){
return nextindex;
}
bool isempty(){
  return nextindex==0;
}

};

int main(){
    // stack <int>s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);

    // cout<<endl;

    // cout<<s.top();
    // s.pop();
    // cout<<endl;

    // cout<<s.top();
    // s.pop();
    // cout<<endl;

    // cout<<s.top();
    // s.pop();
    // cout<<endl;

    // cout<<s.size();
    // cout<<endl;

    // cout<<s.isempty();
    // cout<<endl;

    stack <char>s2;
    s2.push(100);
    s2.push(101);
    s2.push(102);
    s2.push(103);
    s2.push(104);


    cout<<s2.top();
    s2.pop();
    cout<<endl;


    cout<<s2.top();
    s2.pop();
    cout<<endl;

    cout<<s2.top();
    s2.pop();
    cout<<endl;

    cout<<s2.size();
    cout<<endl;
    cout<<s2.isempty();


}