#include<iostream>
#include<vector>
using namespace std;

class priorityqueue {
private:
    vector<int> pq;
public:

    bool isempty() {
        return pq.size() == 0;
    }
    int get_size() {
        return pq.size();
    }
    int get_min() {
        if (pq.empty()) {
            return 0;
        }
        else {
            return pq[0];
        }
    }
    void reheap_up(int root, int last) {
        if (last<= 0) {
            return;
        }
        int parent = (last - 1 )/ 2;
        if (pq[parent] < pq[last]) {
            return;
        }
        swap(pq[parent], pq[last]);
        reheap_up(0, parent);
        
    }

    void insert_recursive(int element) {
        pq.push_back(element);
        reheap_up(0, pq.size() - 1);
    }

    //void insert_iterative(int element) {
    //    pq.push_back(element);
    //    int child = pq.size() - 1;
    //    while (child > 0) {
    //        int parent = child - 1 / 2;
    //        if (pq[parent] < pq[child]) {
    //            swap(pq[parent], pq[child]);
    //            child = parent;
    //        }
    //        else {
    //            break;
    //        }
    //    }
    //}


    //int removemin_iterative() {
    //    if (pq.empty()) {
    //        return 0;  /// pq is empty
    //    }
    //   /* int ans = pq[0];*/
    //        swap(pq[0], pq[pq.size() - 1]);
    //        pq.pop_back();

    //        /// CBT yes , Heap no
    //        /// Down Heapify

    //        int pi = 0;
    //        while (true) {
    //            int lci = 2 * pi + 1;
    //            int rci = 2 * pi + 2;
    //            int min = pi;

    //            if (lci < pq.size() && pq[lci] > pq[min]) {
    //                min = lci;
    //            }
    //            if (rci < pq.size() && pq[rci] > pq[min]) {
    //                min = rci;
    //            }

    //            if (min == pi) {
    //                break;
    //            }
    //            swap(pq[pi], pq[min]);
    //            pi = min;
    //        }
    //  /*  return ans;*/
    //}
    void reheap_down(int ci, int size) {

        int lc = ci * 2 + 1;
        int rc = ci * 2 + 2;
        int min = ci;
        if (lc < size && pq[lc] < pq[min])
            min = lc;
        if ( rc < size  && pq[rc] < pq[min])
            min = rc;
        if (min == ci) {
            return;
        }
        swap(pq[ci], pq[min]);
        reheap_down(min, size);
    }
    void removemin() {
        swap(pq[0], pq[pq.size()-1]);
        pq.pop_back();
        reheap_down(0, pq.size());
    }

};
int main() {

    priorityqueue p;
    //p.insert_iterative(100);
    //p.insert_iterative(10);
    //p.insert_iterative(15);
    //p.insert_iterative(4);
    //p.insert_iterative(17);
    //p.insert_iterative(21);
    //p.insert_iterative(67);
    //cout << p.get_size() << endl;
    //cout << p.get_min() << endl;
    //while (!p.isempty()) {
    //    p.removemin_iterative();
    //}
    //cout << p.get_size() << endl;
    //cout << p.get_min() << endl;

    //recursive

    p.insert_recursive(100);
    p.insert_recursive(10);
    p.insert_recursive(15);
    p.insert_recursive(4);
    p.insert_recursive(17);
    p.insert_recursive(21);
    p.insert_recursive(67);
    cout << p.get_size() << endl;
    cout << p.get_min() << endl;
    while (!p.isempty()) {
      p.removemin();
    }
    cout << p.get_size() << endl;
    cout << p.get_min() << endl;


    return 0;
}