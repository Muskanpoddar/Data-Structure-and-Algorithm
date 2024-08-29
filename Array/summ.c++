#include<iostream>
using namespace std;

class Exercise2 {
public:
    static void main() {
        int my_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        int sum = 0;
        for (int i : my_array)
            sum += i;

       
        cout << "The sum is " << sum << endl;
    }
};


int main() {
    Exercise2::main();
    return 0;
}
