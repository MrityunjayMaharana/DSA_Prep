#include <iostream>
using namespace std;

// Function to check if the i-th bit of a number is set
bool isIthBitSet(int num, int i) {
    // Function implementation goes here

    /*
        n = 25, i = 3
        1100_1 -> i=1 -> n>>1 -> 0110_0
        0110_0 -> i=2 -> n>>1 -> 0011_0
        0011_0 -> i=3 -> n>>1 -> 0001_1

        now, n & 1 -> 00011 & 1 -> 00001 -> setBit -> true

    */

    while (i)
    {
        num = num >> 1;
        i--;
    }
    

    return num & 1; // Placeholder return value
}

int main() {
    int num = 5; // Example number
    int i = 1;   // Bit position to check (0-based index)


    bool result = isIthBitSet(num, i); // Call the function

    if (result) {
        cout << "The " << i << "-th bit of " << num << " is set." << endl;
    } else {
        cout << "The " << i << "-th bit of " << num << " is not set." << endl;
    }

    return 0;
}
