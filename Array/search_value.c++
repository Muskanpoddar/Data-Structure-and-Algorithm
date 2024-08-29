#include <iostream>
using namespace std;

bool arrayContainsValue(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int main() {
   
    int my_array[] = {1, 2, 3, 4, 5};

    // Value to search for
    int search_value = 3;

   
    if (arrayContainsValue(my_array, sizeof(my_array)/sizeof(my_array[0]), search_value)) {
        cout << "The array contains " << search_value << endl;
    } else {
        cout << "The array does not contain " << search_value << endl;
    }

    return 0;
}
