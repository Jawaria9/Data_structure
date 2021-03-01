#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>


template<typename V>
class MapNode{
    //class mapnode
public:
    string key;
    V value;
    MapNode *next;
    //constructor
    MapNode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    //destructor
    ~MapNode(){
        if (next != NULL)
            delete next;
    }
};

template<typename V>
class mymap{
   private:
       //data members
       MapNode<V>** buckets;
       int count;
       int numBuckets;
       //method to find bucket index
       int getBucketIndex(string key){
           int hashcode = 0;
           int base = 1;
           int p = 37;
           for(int i=key.size()-1;i>=0;i--){
                hashcode += key[i] * base;
                base = base * p;
                hashcode = hashcode%numBuckets;
                base = base%numBuckets;
           }
           return hashcode%numBuckets;
       }
       //Method for rehash 
       void rehash(){
          MapNode<V>** temp = buckets;
          buckets = new MapNode<V>*[2*numBuckets];
          for(int i=0;i<2*numBuckets;i++){
            buckets[i] = NULL;
          }
          int oldBucketSize = numBuckets;
          numBuckets *= 2;
          count = 0;

          for(int i=0;i<oldBucketSize;i++){
             MapNode<V>* head = temp[i];
             while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head = head->next;
             }
          }

          for(int i=0;i<oldBucketSize;i++){
            delete temp[i];
          }
          delete []temp;
       }
   public:
    //default constructor
    mymap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i] = NULL;
        }
    }
    //destructor
    ~mymap(){
       for(int i=0;i<numBuckets;i++){
        delete buckets[i];
       }
       delete []buckets;
    }
    //get size function
    int size(){
       return count;
    }
    //get value method
    MapNode<V>* getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                return head;
            }
            head = head->next;
        }
        return 0;
    }
    //insert method
    void insert(string key, V value){
      int bucketIndex = getBucketIndex(key);
      MapNode<V>* head = buckets[bucketIndex];
      while(head!=NULL){
        if(head->key == key){
            head->value = value;
            return;
        }
        head = head->next;
      }
      MapNode<V>* node = new MapNode<V>(key,value);
      node->next = buckets[bucketIndex];
      buckets[bucketIndex] = node;
      node = nullptr;
      count++;
      double loadFactor = (1.0*count)/numBuckets;
      if(loadFactor > 2){
        rehash();
      }
    }
    //delete method
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        while(head!=NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }
        return 0;
    }
    //load factor
    double getLoadFactor(){
       return (1.0*count)/numBuckets;
    }
};
