#include <iostream>
using namespace std;

int main() {
    int arr[6] = { 10, 20, 30, 40, 50 };
    int n = 5; 
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int element_to_add = 60;

    if (n < 6) { 
        arr[n] = element_to_add;
        n++; 
    } else {
        cout << "Array is full, cannot add more elements." << endl;
    }
    cout << "Updated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
