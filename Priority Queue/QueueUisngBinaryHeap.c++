#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;  // This will store the binary heap

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void siftUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        if (l < heap.size() && heap[l] > heap[maxIndex])
            maxIndex = l;

        int r = rightChild(i);
        if (r < heap.size() && heap[r] > heap[maxIndex])
            maxIndex = r;

        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            siftDown(maxIndex);
        }
    }

public:
    bool isEmpty() {
        return heap.size() == 0;
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }
        return heap[0];
    }

    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }

    void display() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(45);
    pq.insert(20);
    pq.insert(14);
    pq.insert(12);
    pq.insert(31);
    pq.insert(7);
    pq.insert(11);
    pq.insert(13);
    pq.insert(7);

    cout << "Max-Heap array: ";
    pq.display();

    cout << "Max element: " << pq.getMax() << endl;

    pq.extractMax();
    cout << "After extracting max, new heap: ";
    pq.display();

    return 0;
}

