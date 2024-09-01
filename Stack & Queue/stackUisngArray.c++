#include <iostream>
#define MAX 1000
using namespace std;

class StackArray {
private:
    int top;
    int arr[MAX];

public:
    StackArray() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[++top] = value;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
        } else {
            top--;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        cout << "Stack is empty" << endl;
        return -1;
    }

    bool isEmpty() {
        return top < 0;
    }

    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();
    cout << "Top element is: " << stack.peek() << endl;
    return 0;
}
