#include <iostream>
using namespace std;

// Function to calculate the total number of set bits from 1 to n
int totalSetBits(int n) {
    // Function implementation goes here
    int setBits = 0;

    // n=25 binary = 11001
    /*
        11001 & 1 -> 00001 -> set bit -> count ++ -> n>>1
        01100 & 1 -> 00000 -> not set bit -> count -> n>>1
        00110 & 1 -> 00000 -> not set bit -> count -> n>>1
        00011 & 1 -> 00001 -> set bit -> count++ -> n>>1
        00001 & 1 -> 00001 -> set bit -> count++ -> n>>1
        00000 -> loop ends

        total set bits => 3
    */

    while(n > 0) {
        if(n & 1) {
            setBits++;
        }
        n = n>>1;
    }
    return setBits; // Placeholder return value
}

int main() {
    int n = 10; // Example input

    int result = totalSetBits(n); // Call the function

    cout << "Total set bits in " << n << " is: " << result << endl;

    return 0;
}
