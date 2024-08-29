#include <iostream>
using namespace std;

void insertElement(int arr[], int& size, int pos, int value) {
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = size; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    
    arr[pos] = value;
    ++size;
}

int main() {
    const int MAX_SIZE = 100; 
    int my_array[MAX_SIZE] = {1, 2, 3, 4, 5}; 
    int size = 5; 
    int position = 2; 
    int element = 10;
    
   
    cout << "Array before insertion:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << my_array[i] << " ";
    }
    cout << endl;
    
  
    insertElement(my_array, size, position, element);
    
  
    cout << "Array after insertion:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << my_array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
