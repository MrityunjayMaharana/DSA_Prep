#include <iostream>
#include <string>
using namespace std;

// Function to convert a decimal number to binary
string decimalToBinary(int decimal) {
    /*
        Explanation:
        -------------------------------------------------------------
        | Decimal | Binary Representation | Bitwise Operations      |
        -------------------------------------------------------------
        | 11      | 1011                   | 11 & 1 -> 1            |
        |         |                        | 11 >> 1 -> 5           |
        -------------------------------------------------------------
        | 5       | 101                    | 5 & 1 -> 1             |
        |         |                        | 5 >> 1 -> 2            |
        -------------------------------------------------------------
        | 2       | 10                     | 2 & 1 -> 0             |
        |         |                        | 2 >> 1 -> 1            |
        -------------------------------------------------------------
        | 1       | 1                      | 1 & 1 -> 1             |
        |         |                        | 1 >> 1 -> 0            |
        -------------------------------------------------------------
        Read the binary digits from bottom to top: 1011
    */

    if (decimal == 0) return "0";

    string binary = "";
    while (decimal > 0) {
        // Use bitwise AND to extract the least significant bit
        binary = to_string(decimal & 1) + binary;
        // Use right shift to move to the next bit
        decimal >>= 1;
    }

    return binary;
}

int main() {
    int decimal = 11; // Example decimal input

    string binary = decimalToBinary(decimal); // Call the function

    cout << "The binary equivalent of decimal " << decimal << " is: " << binary << endl;

    return 0;
}
