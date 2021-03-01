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




void push(int element){
if(nextindex==capacity){
    int *newarray=new int[capacity*2];
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

int top(){
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
    stack s;
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



    


}