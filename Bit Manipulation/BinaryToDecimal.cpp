#include <iostream>
#include <string>
using namespace std;

// Function to convert a binary number to decimal
int binaryToDecimal(const string& binary) {
    // Function implementation goes here

    /*
        _____________________________________________________________
        | 1         | 1         | 0         | 0         | 1         | => 25
        -------------------------------------------------------------
        _____________________________________________________________
        | pow(2, 4) | pow(2, 3) | pow(2, 2) | pow(2, 1) | pow(2, 0) | => pow(2, 0) + pow(2, 3) + pow(2, 4) => 1 + 8 + 16 => 25
        -------------------------------------------------------------
    */
    int n = binary.length();
    int count = 0;
    int ans = 0;

    for(int index=n-1; index>=0; index--) {
        if(binary[index] == '1') {
            ans += (1 << count);
        }
        count++;
    }

    return ans; // Placeholder return value
}

int main() {
    string binary = "1011"; // Example binary input

    int decimal = binaryToDecimal(binary); // Call the function

    cout << "The decimal equivalent of binary " << binary << " is: " << decimal << endl;

    return 0;
}
