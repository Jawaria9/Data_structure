#include<iostream>
using namespace std;


template<typename T>
class Queue{
    private:
    T *array;
    int first;
    int next;
    int size;
    int capacity;

    public:
    Queue(){
        capacity=5;
        array=new T[capacity];
        first=-1;
        next=0;
        size=0;
    }
    Queue(int capacity){
        this->capacity=capacity;
        array=new T[capacity];
        first=-1;
        next=0;
        size=0;
    }
    void push(T element){
        if(size==capacity){
            T *newarray=new T[capacity*2];
            int j=0;
            for(int i=first;i<capacity;i++){
                newarray[j]=array[i];
                j++;
            }
            for(int i=0;i<first;i++){
                newarray[j]=array[i];
                j++;
            }
            first=0;
            next=capacity;
            delete []array;
            array=newarray;
            capacity=capacity*2;
        }
        array[next]=element;
        next=(next+1)%capacity;
        size++;
        if(first==-1){
            first=0;
        }
    }
    //next+1%capacity
            
    //         else{
    //             T *newarray=new T[capacity*2];
    //             for(int i=0;i<capacity;i++){
    //                 newarray[i]=array[i];
    //             }
    //             delete array;
    //             array=newarray;
    //             capacity=capacity*2;
    //             array[next]=element;
    //             next++;
    //             size++;
    //             }
    //         }
    //     else{
    //         array[next]=element;
    //         next++;
    //         first++;
    //         size++;
    //     }
    // }

    void pop(){
        if(first!=-1){
        first=(first+1)%capacity;
        size--;
        }
        else{
            cout<<"queue is empty"<<endl;
        }
        
    }

    T front(){
        if(first!=-1){
        return array[first];
        }
        else{
            cout<<"queue is empty";
        }
    }

    int getsize(){
        return size;
    //     //return (next-first+capacity)%capacity;
    //     //next-first
     }
    bool isempty(){
       return first==-1;
    }
};
int main(){
    Queue<int> obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(5);

    obj.pop();
    cout<<obj.front();
        //   cout<<obj.getsize();
        //   cout<<obj.isempty();

    // cout<<obj.front();
  

    

    // obj.isempty();

}