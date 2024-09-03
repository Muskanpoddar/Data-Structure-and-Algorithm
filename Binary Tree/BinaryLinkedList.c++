#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void inorderTraversal(TreeNode* node) const {
        if (node) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void levelOrderTraversal(TreeNode* node) const {
        if (!node) return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    void deleteTree(TreeNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    void insert(int value) {
        if (!root) {
            root = new TreeNode(value);
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (!current->left) {
                current->left = new TreeNode(value);
                return;
            } else {
                q.push(current->left);
            }
            if (!current->right) {
                current->right = new TreeNode(value);
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void inorder() const {
        inorderTraversal(root);
        cout << endl;
    }

    void levelOrder() const {
        levelOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    cout << "Inorder Traversal: ";
    bt.inorder();

    cout << "Level Order Traversal: ";
    bt.levelOrder();

    return 0;
}

