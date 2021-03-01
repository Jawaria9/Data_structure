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
    int get_max() {
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
        if (pq[parent] > pq[last]) {
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


    //int removemax_iterative() {
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
    //            int max = pi;

    //            if (lci < pq.size() && pq[lci] > pq[max]) {
    //                max = lci;
    //            }
    //            if (rci < pq.size() && pq[rci] > pq[max]) {
    //                max = rci;
    //            }

    //            if (max == pi) {
    //                break;
    //            }
    //            swap(pq[pi], pq[max]);
    //            pi = max;
    //        }
    //  /*  return ans;*/
    //}
    void reheap_down(int ci, int size) {

        int lc = ci * 2 + 1;
        int rc = ci * 2 + 2;
        int max = ci;
        if (lc < size && pq[lc] > pq[max])
            max = lc;
        if ( rc < size  && pq[rc] > pq[max])
            max = rc;
        if (max == ci) {
            return;
        }
        swap(pq[ci], pq[max]);
        reheap_down(max, size);
    }
    void removemax() {
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
    //cout << p.get_max() << endl;
    //while (!p.isempty()) {
    //    p.removemax_iterative();
    //}
    //cout << p.get_size() << endl;
    //cout << p.get_max() << endl;

    //recursive

    p.insert_recursive(100);
    p.insert_recursive(10);
    p.insert_recursive(15);
    p.insert_recursive(4);
    p.insert_recursive(17);
    p.insert_recursive(21);
    p.insert_recursive(67);
    cout << p.get_size() << endl;
    cout << p.get_max() << endl;
    while (!p.isempty()) {
      p.removemax();
    }
    cout << p.get_size() << endl;
    cout << p.get_max() << endl;


    return 0;
}


 