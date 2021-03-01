#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

template<typename V>
class mapnode {
private:
    string key;
    V value;
    mapnode* next;
    mapnode(string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapnode() {
        delete next;
    }
    template<typename s>friend class mymap;
};

template<typename V>
class mymap {
private:
    mapnode<V>** buckets;
    int count;//No of keys pairs
    int numbuckets;//size of buckets

public:

    int getbucketindex(string key) {
        int hashcode = 0;
        int base = 1;
        int p = 37;
        for (int i = key.size() - 1; i >= 0; i--) {
            hashcode =+ key[i] * base;
            base = base * p;
            hashcode = hashcode % numbuckets;
            base = base % numbuckets;
        }
        return hashcode % numbuckets;

    }
    mymap() {
        count = 0;
        numbuckets = 5;
        buckets = new mapnode<V> * [numbuckets];
        for (int i = 0; i < numbuckets; i++) {
            buckets[i] = NULL;
        }
    }
    ~mymap() {
        for (int i = 0; i < numbuckets; i++) {
            delete buckets[i];
        }
        delete[]buckets;
    }

    int size() {
        return count;
    }

    double getloadfactor() {
        double LF = (1.0 * count) / numbuckets;
        return LF;
    }

    void rehash() {
        mapnode<V>** temp = buckets;
        int oldnumbuckets = numbuckets;
        numbuckets = numbuckets * 2;
        count = 0;
        buckets = new mapnode<V> * [numbuckets];
        for (int i = 0; i < numbuckets; i++) {
            buckets[i] = NULL;
        }
        for (int i = 0; i < oldnumbuckets; i++) {
            while (temp[i] != NULL) {
                string key = temp[i]->key;
                V value = temp[i]->value;
                insert(key, value);
                temp[i] = temp[i]->next;
            }
            delete temp[i];
        }
        delete[]temp;
    }

    void insert(string key, V value) {
        int bucketIndex = getbucketindex(key);
        mapnode<V>* head = buckets[bucketIndex];
        while (head != NULL) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        mapnode<V>* node = new mapnode<V>(key, value);
        node->next = buckets[bucketIndex];
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0 * count) / numbuckets;
        if (loadFactor >= 2) {
            rehash();
        }
    }


    V remove(string key) {
        int bucketindex = getbucketindex(key);
        mapnode<V>* head = buckets[bucketindex];
        mapnode<V>* previous = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (previous == NULL) {
                    V value = head->value;
                    buckets[bucketindex] = head->next;
                    delete head;
                    count--;
                    return value;
                }
                else {
                    previous->next = head->next;
                    V value = head->value;
                    head->next = NULL;//putting on the place, not pointing
                    delete head;
                    count--;
                    return value;
                }
            }
            previous = head;
            head = head->next;
        }
    }

    V search(string key) {//getvalue function
        int bucketindex = getbucketindex(key);
        mapnode<V>* head = buckets[bucketindex];
        mapnode<V>* temp = head;
        while (head != NULL) {
            if (head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;

    }

};



