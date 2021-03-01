#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

template<typename V>
class mapnode{
    public:
    string key;
    V value;
    mapnode *next;
    mapnode(string key,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    ~mapnode(){
        delete next;
    }
};
template<typename V>
class mymap{
    private:
    mapnode<V>** buckets;
    int count;//No of keys pairs
    int numbuckets;//size of buckets

    int getbucketindex(string key){
        int hashcode=0;
        int base=1;
        int p=37;
        for(int i=key.size()-1;i>=0;i++){
            hashcode=key[i]*base;
            base=base*p;
            hashcode=hashcode%numbuckets;
            base=base%numbuckets;
        }
        return hashcode%numbuckets;

    }
    public:
    mymap(){
        count=0;
        numbuckets=5;
        buckets=new mapnode<V>*[numbuckets];
        for(int i=0;i<numbuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~mymap(){
        for(int i=0;i<numbuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }
    int size(){
        return count;
    }

    void insert(string key,V value){
        int bucketindex=getbucketindex(key);
        mapnode<V>*head=buckets[bucketindex];
        mapnode<V>*temp=head;
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
            }
            head=head->next;
        }
        mapnode<V> pre=temp;
        temp=new mapnode<V>(key,value);
        temp->next=pre;
        count++;
    }
    
    V remove(string key){
        int bucketindex=getbucketindex(key);
        mapnode<V>*head=buckets[bucketindex];
        mapnode<V>*temp=head;
        if(head->key==key){
            buckets[bucketindex]=head->next;
            head->next=NULL;
            V val=head->value;
            delete head;
            count--;
            return val;
        }
        while(head!=NULL && head->next!=NULL){
            if(head->next->key==key){
                mapnode<V>temp=head->next;
                head->next=temp->next;
                temp->next=NULL;
                V val=temp->value;
                delete temp;
                count--;
                return val;
            }
            head=head->next;
        }
        return 0;
    }
    V search(string key){//getvalue function
        int bucketindex=getbucketindex(key);
        mapnode<V>*head=buckets[bucketindex];
        mapnode<V>*temp=head;
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;

    }
};
