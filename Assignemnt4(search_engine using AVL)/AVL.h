#include <iostream>
using namespace std;

// Defines class AVLNode 
template<typename T>
class AVLnode {
public:

    T data;
    AVLnode<T>* right;
    AVLnode<T>* left;
    int height;

    // Default constructor

    AVLnode() {
        left = NULL;
        right = NULL;
        height = 1;
    }

    // Parameterized constructor to assign data

    AVLnode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
    //Destructor
    friend ostream& operator <<(ostream& out, AVLnode<T>& obj) {
        out << obj.data << endl;
        return out;
    }
    ~AVLnode() {
        delete left;
        delete right;
    }
};
// Defines class AVL
template<typename T>
class AVL {
public:
    // Creates a root node
    AVLnode<T>* root;

    // Default constructor
    AVL() {
        root = nullptr;
    }
    // Parameterized constructor
    AVL(AVLnode<T>* root) {
        this->root = root;
    }
    //Destructor
    ~AVL() {
        delete root;
    }

    // Helper methods for inserting/deleting
    int NodeHeight(AVLnode<T>* p);
    int BalanceFactor(AVLnode<T>* p);
    AVLnode<T>* LLRotation(AVLnode<T>* p);
    AVLnode<T>* RRRotation(AVLnode<T>* p);
    AVLnode<T>* LRRotation(AVLnode<T>* p);
    AVLnode<T>* RLRotation(AVLnode<T>* p);
    AVLnode<T>* InPre(AVLnode<T>* p);
    AVLnode<T>* InSucc(AVLnode<T>* p);
    void insert(T data) {
        root = rInsert(root, data);
    }
    //Searching
    AVLnode<T>* hasData(T data) {
        return hasData(root, data);
    }

    AVLnode<T>* hasData(AVLnode<T>* root, T data);


    // Insert
    AVLnode<T>* rInsert(AVLnode<T>* p, int key);

    // Traversal
    void Inorder(AVLnode<T>* p);
    void Inorder() {
        Inorder(root);
    }

    // Delete
    AVLnode<T>* Delete(AVLnode<T>* p, int key);
};
template<typename T>
// Method to return height
int AVL<T>::NodeHeight(AVLnode<T>* node) {
    int left_height;
    int right_height;
    if (node != NULL && node->left != NULL) {
        left_height = node->left->height;
    }
    else {
        left_height = 0;
    }
    if (node != NULL && node->right != NULL) {
        right_height = node->right->height;
    }
    else {
        right_height = 0;
    }
    if (left_height > right_height) {
        return left_height + 1;
    }
    else {
        return right_height + 1;
    }
}
// Method to return balancefactor
template<typename T>
int AVL<T>::BalanceFactor(AVLnode<T>* node) {
    int left_height;
    int right_height;
    if (node != NULL && node->left != NULL) {
        left_height = node->left->height;
    }
    else {
        left_height = 0;
    }
    if (node != NULL && node->right != NULL) {
        right_height = node->right->height;
    }
    else {
        right_height = 0;
    }

    return left_height - right_height;
}


// Method to perform right rotation
template<typename T>
AVLnode<T>* AVL<T>::LLRotation(AVLnode<T>* p) {
    AVLnode<T>* pl = p->left;
    AVLnode<T>* plr = pl->right;

    pl->right = p;
    p->left = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p) {
        root = pl;
    }
    return pl;
}
// Method to perform left rotation
template<typename T>
AVLnode<T>* AVL<T>::RRRotation(AVLnode<T>* p) {
    AVLnode<T>* pr = p->right;
    AVLnode<T>* prl = pr->left;

    pr->left = p;
    p->right = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p) {
        root = pr;
    }
    return pr;
}

// Method to perform left and right rotation
template<typename T>
AVLnode<T>* AVL<T>::LRRotation(AVLnode<T>* p) {
    AVLnode<T>* pl = p->left;
    AVLnode<T>* plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    // Update root
    if (p == root) {
        root = plr;
    }
    return plr;
}
// Method to perform  right and left rotation
template<typename T>
AVLnode<T>* AVL<T>::RLRotation(AVLnode<T>* p) {
    AVLnode<T>* pr = p->right;
    AVLnode<T>* prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    // Update root
    if (root == p) {
        root = prl;
    }
    return prl;
}

// Method to search a node in AVL tree
template<typename T>
AVLnode<T>* AVL<T>::hasData(AVLnode<T>* node, T data) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == data) {
        return node;
    }

    if (node->data > data) {
        return hasData(node->left, data);
    }
    else {
        return hasData(node->right, data);
    }
}
template<typename T>
AVLnode<T>* AVL<T>::InPre(AVLnode<T>* p) {
    while (p && p->right != nullptr) {
        p = p->right;
    }
    return p;
}
template<typename T>
AVLnode<T>* AVL<T>::InSucc(AVLnode<T>* p) {
    while (p && p->left != nullptr) {
        p = p->left;
    }
    return p;
}
// Method to insert a node to AVL tree
template<typename T>
AVLnode<T>* AVL<T>::rInsert(AVLnode <T>* p, int key) {
    AVLnode<T>* t;
    if (p == nullptr) {
        t = new AVLnode<T>;
        t->data = key;
        t->left = nullptr;
        t->right = nullptr;
        t->height = 1;  // Starting height from 1 
        return t;
    }

    if (key < p->data) {
        p->left = rInsert(p->left, key);
    }
    else if (key > p->data) {
        p->right = rInsert(p->right, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) {
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1) {
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1) {
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1) {
        return RLRotation(p);
    }

    return p;
}

// Method to perform in order traversing 
template<typename T>
void AVL<T>::Inorder(AVLnode<T>* p) {
    if (p) {
        Inorder(p->left);
        cout << p->data << ", ";
        Inorder(p->right);
    }
}

// Method to delete a node from AVL tree 
template<typename T>
AVLnode<T>* AVL<T>::Delete(AVLnode<T>* p, int key) {
    if (p == nullptr) {
        return nullptr;
    }

    if (p->left == nullptr && p->right == nullptr) {
        if (p == root) {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data) {
        p->left = Delete(p->left, key);
    }
    else if (key > p->data) {
        p->right = Delete(p->right, key);
    }
    else {
        AVLnode<T>* q;
        if (NodeHeight(p->left) > NodeHeight(p->right)) {
            q = InPre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else {
            q = InSucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 1) {  // L1 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == -1) {  // L-1 Rotation
        return LRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == -1) {  // R-1 Rotation
        return RRRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 1) {  // R1 Rotation
        return RLRotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->left) == 0) {  // L0 Rotation
        return LLRotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->right) == 0) {  // R0 Rotation
        return RRRotation(p);
    }

    return p;
}

