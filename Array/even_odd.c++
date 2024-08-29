#include <iostream>
using namespace std;

int main() {
 
    int array[] = {5, 7, 2, 4, 9};
    int n = sizeof(array) / sizeof(array[0]);

    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << "Number of even integers: " << evenCount << endl;
    cout << "Number of odd integers: " << oddCount << endl;

    return 0;
}
