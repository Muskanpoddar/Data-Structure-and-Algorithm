#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    int t;
    bool leaf;

    BTreeNode(int _t, bool _leaf) : t(_t), leaf(_leaf) {}

    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf)
                children[i]->traverse();
            cout << keys[i] << " ";
        }
        if (!leaf)
            children[i]->traverse();
    }

    BTreeNode* search(int k) {
        int i = 0;
        while (i < keys.size() && k > keys[i])
            i++;
        if (i < keys.size() && keys[i] == k)
            return this;
        if (leaf)
            return nullptr;
        return children[i]->search(k);
    }

    void insertNonFull(int k) {
        int i = keys.size() - 1;
        if (leaf) {
            keys.push_back(0);
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && keys[i] > k)
                i--;
            i++;
            if (children[i]->keys.size() == 2 * t - 1) {
                splitChild(i, children[i]);
                if (keys[i] < k)
                    i++;
            }
            children[i]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->t, y->leaf);
        z->keys.resize(t - 1);
        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];
        if (!y->leaf) {
            z->children.resize(t);
            for (int j = 0; j < t; j++)
                z->children[j] = y->children[j + t];
        }
        y->keys.resize(t - 1);
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[t - 1]);
    }

    void remove(int k) {
        int idx = findKey(k);
        if (idx < keys.size() && keys[idx] == k) {
            if (leaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            if (leaf)
                return;
            bool flag = (idx == keys.size());
            if (children[idx]->keys.size() < t)
                fill(idx);
            if (flag && idx > keys.size())
                children[idx - 1]->remove(k);
            else
                children[idx]->remove(k);
        }
    }

    int findKey(int k) {
        int idx = 0;
        while (idx < keys.size() && keys[idx] < k)
            ++idx;
        return idx;
    }

    void removeFromLeaf(int idx) {
        for (int i = idx + 1; i < keys.size(); ++i)
            keys[i - 1] = keys[i];
        keys.resize(keys.size() - 1);
    }

    void removeFromNonLeaf(int idx) {
        int k = keys[idx];
        if (children[idx]->keys.size() >= t) {
            int pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred);
        } else if (children[idx + 1]->keys.size() >= t) {
            int succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ);
        } else {
            merge(idx);
            children[idx]->remove(k);
        }
    }

    int getPred(int idx) {
        BTreeNode* cur = children[idx];
        while (!cur->leaf)
            cur = cur->children[cur->keys.size()];
        return cur->keys[cur->keys.size() - 1];
    }

    int getSucc(int idx) {
        BTreeNode* cur = children[idx + 1];
        while (!cur->leaf)
            cur = cur->children[0];
        return cur->keys[0];
    }

    void fill(int idx) {
        if (idx != 0 && children[idx - 1]->keys.size() >= t)
            borrowFromPrev(idx);
        else if (idx != keys.size() && children[idx + 1]->keys.size() >= t)
            borrowFromNext(idx);
        else {
            if (idx != keys.size())
                merge(idx);
            else
                merge(idx - 1);
        }
    }

    void borrowFromPrev(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];
        child->keys.insert(child->keys.begin(), keys[idx - 1]);
        if (!child->leaf)
            child->children.insert(child->children.begin(), sibling->children[sibling->keys.size()]);
        keys[idx - 1] = sibling->keys[sibling->keys.size() - 1];
        sibling->keys.resize(sibling->keys.size() - 1);
    }

    void borrowFromNext(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys.push_back(keys[idx]);
        if (!child->leaf)
            child->children.push_back(sibling->children[0]);
        keys[idx] = sibling->keys[0];
        for (int i = 1; i < sibling->keys.size(); ++i)
            sibling->keys[i - 1] = sibling->keys[i];
        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->keys.size(); ++i)
                sibling->children[i - 1] = sibling->children[i];
        }
        sibling->keys.resize(sibling->keys.size() - 1);
    }

    void merge(int idx) {
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys.push_back(keys[idx]);
        for (int i = 0; i < sibling->keys.size(); ++i)
            child->keys.push_back(sibling->keys[i]);
        if (!child->leaf) {
            for (int i = 0; i <= sibling->keys.size(); ++i)
                child->children.push_back(sibling->children[i]);
        }
        for (int i = idx + 1; i < keys.size(); ++i)
            keys[i - 1] = keys[i];
        for (int i = idx + 2; i <= keys.size(); ++i)
            children[i - 1] = children[i];
        keys.resize(keys.size() - 1);
        children.resize(children.size() - 1);
        delete sibling;
    }
};

class BTree {
public:
    BTreeNode* root;
    int t;

    BTree(int _t) : root(nullptr), t(_t) {}

    void traverse() {
        if (root != nullptr)
            root->traverse();
    }

    BTreeNode* search(int k) {
        return root == nullptr ? nullptr : root->search(k);
    }

    void insert(int k) {
        if (root == nullptr) {
            root = new BTreeNode(t, true);
            root->keys.push_back(k);
        } else {
            if (root->keys.size() == 2 * t - 1) {
                BTreeNode* s = new BTreeNode(t, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->children[i]->insertNonFull(k);
                root = s;
            } else {
                root->insertNonFull(k);
            }
        }
    }

    void remove(int k) {
        if (!root)
            return;
        root->remove(k);
        if (root->keys.size() == 0) {
            BTreeNode* tmp = root;
            if (root->leaf)
                root = nullptr;
            else
                root = root->children[0];
            delete tmp;
        }
    }
};

int main() {
    BTree t(3);
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal of the constructed tree is ";
    t.traverse();
    cout << endl;

    t.remove(6);
    cout << "Traversal after deletion of 6 ";
    t.traverse();
    cout << endl;

    t.remove(13);
    cout << "Traversal after deletion of 13 ";
    t.traverse();
    cout << endl;

    t.remove(7);
    cout << "Traversal after deletion of 7 ";
    t.traverse();
    cout << endl;

    t.remove(4);
    cout << "Traversal after deletion of 4 ";
    t.traverse();
    cout << endl;

    t.remove(2);
    cout << "Traversal after deletion of 2 ";
    t.traverse();
    cout << endl;

}