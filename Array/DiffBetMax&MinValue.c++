#include <iostream>
#include <climits>
using namespace std;

int main() {
    int array[] = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    int n = sizeof(array) / sizeof(array[0]);

    if (n < 1) {
        cout << "Array must have at least one element." << endl;
        return 1;
    }

    int maxVal = INT_MIN;
    int minVal = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }

    int difference = maxVal - minVal;
    cout << "The difference between the largest and smallest values is: " << difference << endl;

    return 0;
}
