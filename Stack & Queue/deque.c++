#include <iostream>
#include <stdexcept>

using namespace std;

class Deque {
private:
    int* array;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int cap) : capacity(cap), size(0), front(0), rear(cap - 1) {
        if (cap <= 0) {
            throw invalid_argument("Capacity must be greater than 0.");
        }
        array = new int[capacity];
    }

    ~Deque() {
        delete[] array;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void addFront(int value) {
        if (isFull()) {
            throw overflow_error("Deque is full. Cannot add to front.");
        }
        front = (front - 1 + capacity) % capacity;
        array[front] = value;
        size++;
    }

    void addRear(int value) {
        if (isFull()) {
            throw overflow_error("Deque is full. Cannot add to rear.");
        }
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
    }

    int removeFront() {
        if (isEmpty()) {
            throw underflow_error("Deque is empty. Cannot remove from front.");
        }
        int value = array[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int removeRear() {
        if (isEmpty()) {
            throw underflow_error("Deque is empty. Cannot remove from rear.");
        }
        int value = array[rear];
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return value;
    }

    int peekFront() const {
        if (isEmpty()) {
            throw underflow_error("Deque is empty. Cannot peek front.");
        }
        return array[front];
    }

    int peekRear() const {
        if (isEmpty()) {
            throw underflow_error("Deque is empty. Cannot peek rear.");
        }
        return array[rear];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; ++i) {
            cout << array[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        Deque dq(5);

        dq.addRear(10);
        dq.addRear(20);
        dq.addFront(30);
        dq.addFront(40);

        cout << "Deque after adding elements: ";
        dq.display();

        cout << "Removed from front: " << dq.removeFront() << endl;
        cout << "Removed from rear: " << dq.removeRear() << endl;

        cout << "Deque after removals: ";
        dq.display();

        cout << "Front element: " << dq.peekFront() << endl;
        cout << "Rear element: " << dq.peekRear() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

