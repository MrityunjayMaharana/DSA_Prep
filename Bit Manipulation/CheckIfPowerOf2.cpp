#include <iostream>
using namespace std;

bool checkIfPowerOfTwo(int num) {
    /*
        approach: 01
            count set bits if the count == 1 it is a power of 2 else not.

        approach: 02
            num & (nums - 1) == 0 then power of 2 else not.
    */

    return (num & (num - 1)) == 0;
}

int main() {
    int num = 9;
    int i = 2;
    if(checkIfPowerOfTwo(num)) {
        cout << "The number: " << num << " is power of 2." << endl;
    } else {
        cout << "Not a power of 2." << endl;
    }
    return 0;
}