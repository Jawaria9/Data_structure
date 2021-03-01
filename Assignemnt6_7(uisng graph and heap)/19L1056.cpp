#include<iostream>
#include<vector>
#include<string>
#include<List>
#include<fstream>
using namespace std;



//heapclass using  priority queue
template<typename t>
class priorityqueue {
private:
    //data members

    vector<t> pq;
public:
    //function to check whether heap is empty or not
    bool isempty() {
        return pq.size() == 0;
    }
    //method to get the size of minheap
    int get_size() {
        return pq.size();
    }
    //method to get the minimum element
    t get_min() {
        if (pq.empty()) {
            return 0;
        }
        else {
            return pq[0];
        }
    }
    //method to update the value of  element in heap
    void updateVal(t key, int val) {
        for (int i = 0; i < pq.size(); i++) {
            if (key == pq[i]) {
                pq[i] = val;
                break;
            }
        }
        reheap_up(0, pq.size() - 1);
    }

    //constructor
    priorityqueue() {
        ;
    }
    //priorityqueue(t n) {
    // /*   pq = new t[n];*/
    //}
   //function to heapify the heap from bottom to top
    void reheap_up(int root, int last) {
        if (last <= 0) {
            return;
        }
        int parent = (last - 1) / 2;
        if (pq[parent] < pq[last]) {
            return;
        }
        swap(pq[parent], pq[last]);
        reheap_up(0, parent);

    }
    //method to insert in heap
    void insert_recursive(t element) {
        pq.push_back(element);
        reheap_up(0, pq.size() - 1);
    }
    //copy constructor
    priorityqueue(const priorityqueue& a) {
        for (int i = 0; i < pq.size(); i++) {
            this->pq[i] = a.[i];
        }
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

    //method to heapify the heap from top to bottom
    void reheap_down(int ci, int size) {

        int lc = ci * 2 + 1;
        int rc = ci * 2 + 2;
        int min = ci;
        if (lc < size && pq[lc] < pq[min])
            min = lc;
        if (rc < size && pq[rc] < pq[min])
            min = rc;
        if (min == ci) {
            return;
        }
        swap(pq[ci], pq[min]);
        reheap_down(min, size);
    }
    //method to delete or remove the minimum element from heap 
    void removemin() {
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        reheap_down(0, pq.size());
    }
    friend class Graph;
    friend class vertex_node;
    //destructor
    ~priorityqueue() {
        ;
    }

};


//defination of class vertex node
class vertex_node {
private:
    //data members
    int dest;
    int weight;
    string name;
public:
    //default constuctor
    vertex_node() {
        dest = 0;
        weight = INT_MAX;
        name = "";
    }
    //parametrized constructor
    vertex_node(const vertex_node* g) {
        this->weight = g->weight;
        this->dest = g->dest;
        this->name = g->name;
    }
    //parametrized constructor
    vertex_node(int dest, int weight, string n) {
        this->weight = weight;
        this->dest = dest;
        name = n;
    }

    string get_name() {
        return name;
    }
    int get_weight() {
        return weight;
    }
    int get_dest() {
        return dest;
    }

    //operator overloading
    void operator=(const vertex_node* g) {
        this->weight = g->weight;
        this->dest = g->dest;
        this->name = g->name;
    }
    //operator overloading
    bool operator<(const vertex_node& a) {
        return this->weight < a.weight;
    }
    //operator overloading
    bool operator>(const vertex_node& a) {
        return this->weight > a.weight;
    }
    //operator overloading
    bool operator==(const vertex_node& a) {
        return this->name == a.name;
    }
    //destructor
    ~vertex_node() {
        ;
    }
    friend class Graph;

};
//defination of class graph
class Graph {
private:
    //data members
    int v; // No. of nodes in the graph 
    list<vertex_node>* adj; // adjacency lists array
    int** weights;//weights of edges
    vertex_node* ver;//array containg v vertex node type objects

   //allocating no of vertices to adjacency list array
   //allocating no of vertex_node type objects to ver array
public:

    void my_space(int v) {
        this->v = v;
        adj = new list<vertex_node>[v];
        ver = new vertex_node[v];
    }
    int** get_weights() {
        return weights;
    }
    int get_v() {
        return v;
    }
    vertex_node* get_ver() {
        return ver;
    }
    list<vertex_node>* get_adj() {
        return adj;
    }
    //adding vertex to the ver array
    void add_vertex(string n, int in) {
        ver[in].dest = in;
        ver[in].name = n;
        ver[in].weight = INT_MAX;
    }
    //adding edges in adjacency list array and allocating weights in weights of edges in 2D array
    void addEdge(int src, int dest, int weight) {
        adj[src].push_back(ver[dest]);
        weights[src][dest] = weight;
    }
    //constructor
    Graph() {
    }

    //this->v = 0;
    //this->ver = NULL;
    //*weights = new int[v];
    //for (int i = 0; i < v; i++) {
    //    weights[i] = NULL;
    //}
    //adj = NULL;

//destructor
    ~Graph() {
        if (adj != NULL) {
            delete[] adj;
        }

        if (weights != NULL) {
            for (int i = 0; i < v; i++) {
                if (weights[i] != NULL)
                    delete weights[i];
            }
            delete[] weights;
        }
        if (ver != NULL) {
            delete[] ver;
        }
    }

    //copy constructor
    Graph(const Graph* a) {
        this->v = a->v;
        this->weights = new int* [v];
        for (int i = 0; i < v; i++) {
            weights[i] = new int[v];
        }
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                weights[i][j] = a->weights[i][j];
            }
        }
        ver = new vertex_node[v];
        for (int i = 0; i < v; i++) {
            ver[i] = a->ver[i];
        }
        adj = new list<vertex_node>[v];
        for (int i = 0; i < v; i++) {
            list<vertex_node>::iterator ite = a->adj[i].begin();
            while (ite != a->adj[i].end()) {
                adj[i].push_back(*ite);
                ite++;
            }
        }
    }

};


int main() {

    //object of class graph
    Graph obj;
    //reading data fom file and storing in ver array and weights 2 d array and adj list array 
    ifstream fin("data.txt");
    char character = '\0';
    string name;//for name of vertice node
    int var_1, var_2, var_3;

    fin >> var_1;//no of vertex nodes
    obj.my_space(var_1);//allocating no of vertex nodes in adj list array

    while (character != '\n') {//character will help us read upto the no of edges
        fin >> var_1;
        fin.get(character);
        if (character != '\n') {
            getline(fin, name);
            obj.add_vertex(name, var_1 - 1);
        }
    }
    int** weights = obj.get_weights();
    int v = obj.get_v();
    weights = new int* [v];
    for (int i = 0; i < var_1; i++) {
        weights[i] = new int[v];
    }
    //reading edges info
    while (!fin.eof()) {
        fin >> var_1 >> var_2 >> var_3;
        obj.addEdge(var_1 - 1, var_2 - 1, var_3);
        obj.addEdge(var_2 - 1, var_1 - 1, var_3);
    }

    //creating object of min heap class
    priorityqueue<vertex_node> my_minheap;
    //creating object of vertex node class
    vertex_node myvertex;
    vertex_node* ver =obj. get_ver();
    ver[0]->get_weight() = 0;//making the weight of one vertex 0
    for (int i = 0; i < v; i++) {//inserting vertices in min heap class
        my_minheap.insert_recursive(ver[i]);
    }
    //updating the value of vertice whose weight is setted zero
    my_minheap.updateVal(ver[0], 0);
    //repeating the logic of removing minelement of heap
    //and updating the weight of vertice to weight of edge if edge weight is greater than vertice
    while (my_minheap.get_size() != 0) {
        myvertex = my_minheap.get_min();//getting minimum elemnt of heap
        my_minheap.removemin();//removing min element from the heap
        list<vertex_node>* adj =obj.get_adj();
        for (list<vertex_node>::iterator ite = adj[myvertex.get_dest()].begin(); ite != adj[myvertex.get_dest()].end() && adj[myvertex.get_dest()].empty(); ite++) {
            //vertex_weight = *ite.weight
            //edge_weight = weights[myvertex.dest][(*ite).dest]
            if ((*ite).get_weight() > weights[myvertex.get_dest()][(*ite).get_dest()]) {
                (*ite).get_weight() = weights[myvertex.get_dest()][(*ite).get_dest()];
                my_minheap.updateVal(*ite, weights[myvertex.get_dest()][(*ite).get_dest()]);
            }
        }
        cout << myvertex.get_name();
    }
}