#include <iostream>
using namespace std;

int main() {
    int arr[7] = {10, 20, 30, 40, 50}; 
    int n = 5; 

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int element_to_add = 25;
    int position = 2; 

    if (position < 0 || position > n) {
        cout << "Invalid position!" << endl;
        return 1;
    }
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element_to_add;
    n++;
    cout << "Updated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
