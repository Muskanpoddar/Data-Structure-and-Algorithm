 #include <iostream>
#include <vector>
using namespace std;

// A utility function to get the middle index
int getMid(int s, int e) {
    return s + (e - s) / 2;
}

/* A function to build the segment tree from the given array. 
   The function stores the sum of elements in the range from index 'start' to 'end' at index 'index' of the segment tree. */
void buildTree(vector<int>& segTree, const vector<int>& arr, int start, int end, int index) {
    if (start == end) { // Leaf node
        segTree[index] = arr[start];
        return;
    }
    int mid = getMid(start, end);
    buildTree(segTree, arr, start, mid, 2 * index + 1); // Recursively build the left child
    buildTree(segTree, arr, mid + 1, end, 2 * index + 2); // Recursively build the right child
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2]; // Internal node will have the sum of both of its children
}

/* A function to update the segment tree. It changes the value of element at index 'idx' in the array to 'value'. */
void updateValue(vector<int>& segTree, int start, int end, int idx, int value, int index) {
    if (start == end) { // Leaf node
        segTree[index] = value;
        return;
    }
    int mid = getMid(start, end);
    if (idx <= mid) {
        updateValue(segTree, start, mid, idx, value, 2 * index + 1); // Update left child
    } else {
        updateValue(segTree, mid + 1, end, idx, value, 2 * index + 2); // Update right child
    }
    segTree[index] = segTree[2 * index + 1] + segTree[2 * index + 2]; // Update internal node
}

/* A function to get the sum of elements in a given range from 'qs' to 'qe'. */
int getSum(vector<int>& segTree, int segStart, int segEnd, int qs, int qe, int index) {
    if (qs <= segStart && qe >= segEnd) { // If segment of this node is within the query range
        return segTree[index];
    }
    if (segEnd < qs || segStart > qe) { // If segment of this node is outside the query range
        return 0;
    }
    int mid = getMid(segStart, segEnd);
    return getSum(segTree, segStart, mid, qs, qe, 2 * index + 1) + 
           getSum(segTree, mid + 1, segEnd, qs, qe, 2 * index + 2); // Sum of values in the left and right subtrees
}

/* A function to display the segment tree. */
void displaySegmentTree(const vector<int>& segTree) {
    for (int i = 0; i < segTree.size(); ++i) {
        cout << segTree[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Input array
    int n = arr.size();
    vector<int> segTree(4 * n, 0); // Segment tree array of size 4*n

    // Build the segment tree
    buildTree(segTree, arr, 0, n - 1, 0);

    cout << "Segment Tree after building:\n";
    displaySegmentTree(segTree);

    // Range Sum Query from index 1 to 3
    cout << "Sum of values in range [1, 3] is: " << getSum(segTree, 0, n - 1, 1, 3, 0) << endl;

    // Update the value at index 2 to 10
    arr[2] = 10;
    updateValue(segTree, 0, n - 1, 2, 10, 0);

    cout << "Segment Tree after updating index 2 to 10:\n";
    displaySegmentTree(segTree);

    // Range Sum Query from index 1 to 3 after update
    cout << "Sum of values in range [1, 3] after update is: " << getSum(segTree, 0, n - 1, 1, 3, 0) << endl;

    return 0;
}
