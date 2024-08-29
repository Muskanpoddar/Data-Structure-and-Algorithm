#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 20, 30, 40, 50};  
    int n = 5;  
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int element_to_add = 5;

    if (n < 6) {
        for (int i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element_to_add;
        n++;
    } else {
        cout << "No space to add a new element." << endl;
    }
    cout << "Updated Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
