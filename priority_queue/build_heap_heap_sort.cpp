#include<iostream>
#include<vector>
using namespace std;

void reheap_down(int pi, int size, vector<int>&pq) {

    int lc = pi * 2 + 1;
    int rc = pi * 2 + 2;
    int max = pi;
    if (lc<size && pq[lc]>pq[max])
        max = lc;
    if (rc<size && pq[rc]>pq[max])
        max = rc;
    if (max == pi) {
        return;
    }
    swap(pq[pi], pq[max]);
    reheap_down(max, size, pq);
}

void build_heap(vector<int>& pq) {
    int p = (pq.size() - 2) / 2;
    while (p >= 0) {
        reheap_down(p, pq.size() - 1, pq);
        p--;
    }
}

 void heap_sort(vector<int>&pq){
     build_heap(pq);
     int s=pq.size();
     while(s>0){
         swap(pq[0],pq[s-1]);
         s--;
         reheap_down(0,s,pq);
     }
 }
int main() {
    vector<int>v = { 0,4,3,2,1 };
    build_heap(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
    heap_sort(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }




}