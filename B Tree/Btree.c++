#include <iostream>
using namespace std;

class BTreeNode {
    int *keys;         // Array to store keys
    BTreeNode **C;     // Array to store child pointers
    int t;             // Minimum degree
    int n;             // Current number of keys
    bool leaf;         // Is true if the node is a leaf

public:
    // Constructor
    BTreeNode(int t, bool leaf) : t(t), leaf(leaf), n(0) {
        keys = new int[2 * t - 1];      // Max keys in a node
        C = new BTreeNode *[2 * t];     // Max children in a node
    }

    // Function to traverse all nodes in this subtree
    void traverse() {
        for (int i = 0; i < n; i++) {
            if (!leaf) C[i]->traverse();  // Visit child before printing key
            cout << " " << keys[i];
        }
        if (!leaf) C[n]->traverse();  // Visit last child
    }

    // Function to search key k in the subtree rooted with this node
    BTreeNode *search(int k) {
        int i = 0;
        while (i < n && k > keys[i]) i++;

        if (i < n && keys[i] == k) return this;  // Found key

        if (leaf) return nullptr;  // If it's a leaf, key isn't found

        return C[i]->search(k);  // Search in the appropriate child
    }

    // Insert a new key in this node (must be non-full)
    void insertNonFull(int k) {
        int i = n - 1;

        if (leaf) {
            // Find location of new key to be inserted and shift greater keys
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n++;
        } else {
            // Find child to insert the key
            while (i >= 0 && keys[i] > k) i--;

            if (C[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, C[i + 1]);

                if (keys[i + 1] < k) i++;
            }
            C[i + 1]->insertNonFull(k);
        }
    }

    // Split a full child into two
    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];

        if (!y->leaf) {
            for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];

        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];

        keys[i] = y->keys[t - 1];

        n++;
    }

    friend class BTree;  // BTree class can access private members of BTreeNode
};

class BTree {
    BTreeNode *root;  // Pointer to root node
    int t;            // Minimum degree

public:
    // Constructor for BTree
    BTree(int t) : root(nullptr), t(t) {}

    // Function to traverse the entire tree
    void traverse() {
        if (root != nullptr) root->traverse();
    }

    // Function to search a key in the tree
    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    // Function to insert a new key in the B-tree
    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode *s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);

                int i = (s->keys[0] < k) ? 1 : 0;
                s->C[i]->insertNonFull(k);

                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    BTree t(3);  // A B-tree with minimum degree 3

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is: ";
    t.traverse();

    int k = 6;
    (t.search(k) != nullptr) ? cout << "\nPresent" : cout << "\nNot Present";

    k = 15;
    (t.search(k) != nullptr) ? cout << "\nPresent" : cout << "\nNot Present";

    return 0;
}