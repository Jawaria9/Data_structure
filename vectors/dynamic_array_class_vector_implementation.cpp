#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class dynamicarray{
    public:
    int size;
    int *data;
    int traceindex;

    dynamicarray(){
        size=5;
        data=new int[5];
        traceindex=0;
    }
    dynamicarray(int size){
        this->size=size;
        data=new int[size];
        traceindex=0;
    }
    dynamicarray(dynamicarray const &obj){
        size=obj.size;
        traceindex=obj.traceindex;
        data=new int[size];
        for(int i=0; i<traceindex;i++){
            data[i]=obj.data[i];
        }
    }
    void operator=(dynamicarray const &obj){
        size=obj.size;
        traceindex=obj.traceindex;
        data=new int[size];
        for(int i=0; i<traceindex;i++){
        data[i]=obj.data[i];
        }

    }
    void add_element(int element){
        if(traceindex!=size){
            data[traceindex]=element;
            traceindex++;
        }
        else{
            int *newdata=new int[size*2];
            for(int i=0; i<traceindex; i++){
                newdata[i]=data[i];
            }
            delete []data;
            size=size*2;
            data=new int[size];
            for(int i=0; i<traceindex;  i++){
                data[i]=newdata[i];
            }
            delete []newdata;
            newdata=NULL;
            data[traceindex]=element;
            traceindex++;
        }

    }
    void print()const{
        cout<<"data=";
        cout<<"{";
        for(int i=0;  i<traceindex;  i++){
            cout<<data[i]<<",";
        }
        cout<<"}";
        cout<<'\n';
    }
    int get_element(int index)const{
        for(int i=0;  i<traceindex; i++){
            if(index==i){
                return data[i];
            }
        }
        return -1;
    }

    void insert_element(int index,int element){
        if(index<traceindex ){
            data[index]=element;
            
        }
        else if(index==traceindex){
             add_element(element);
        }
        else{
            cout<<"index is not valid to insert element"<<'\n';
        }

    }
    int get_size() const{
        return size;

    }

};
int main(){
    dynamicarray obj;
    obj.add_element(1);
    obj.add_element(2);
    obj.add_element(3);
    obj.add_element(4);
    obj.add_element(5);
    obj.add_element(6);
    obj.add_element(7);
    obj.print();
    cout<<"size:"<<obj.get_size()<<'\n';
    cout<<"element:"<<obj.get_element(4)<<'\n';
    obj.insert_element(2,10);
    obj.print();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
    dynamicarray obj2(obj);//built in copy constructo make shallow copy
    obj2.insert_element(0,100);
    obj2.print();
    obj.print();

cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
    dynamicarray obj3;
    obj3=obj;//copy asssignment operatr also make shallow copy
    obj.insert_element(0,99);
    obj3.print();
cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<"\n";
   dynamicarray obj4(100);
   cout<<"size of obj4:"<<obj4.get_size()<<'\n';

}

