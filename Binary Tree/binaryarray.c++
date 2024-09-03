#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class BinaryTree {
private:
    vector<int> tree;

public:
    BinaryTree(size_t size) : tree(size, -1) {}

    void insert(size_t index, int value) {
        if (index >= tree.size()) {
            throw out_of_range("Index out of range.");
        }
        tree[index] = value;
    }

    int get(size_t index) const {
        if (index >= tree.size()) {
            throw out_of_range("Index out of range.");
        }
        return tree[index];
    }

    size_t leftChild(size_t index) const {
        size_t left = 2 * index + 1;
        if (left >= tree.size()) {
            throw out_of_range("Left child index out of range.");
        }
        return left;
    }

    size_t rightChild(size_t index) const {
        size_t right = 2 * index + 2;
        if (right >= tree.size()) {
            throw out_of_range("Right child index out of range.");
        }
        return right;
    }

    size_t parent(size_t index) const {
        if (index == 0) {
            throw out_of_range("Root node has no parent.");
        }
        return (index - 1) / 2;
    }

    void display() const {
        for (size_t i = 0; i < tree.size(); ++i) {
            cout << "Index " << i << ": " << tree[i] << endl;
        }
    }
};

int main() {
    BinaryTree bt(7);

    bt.insert(0, 1);
    bt.insert(1, 2);
    bt.insert(2, 3);
    bt.insert(3, 4);
    bt.insert(4, 5);
    bt.insert(5, 6);
    bt.insert(6, 7);

    cout << "Binary Tree:" << endl;
    bt.display();

    return 0;
}

