#include <iostream>
#include <vector>
using namespace std;

// Function to find the unique element in the array
int findUniqueElement(const vector<int>& arr) {
    // Function implementation goes here
    int n = arr.size();
    int ans = 0;
    /*
        A ^ A = 0
        A ^ 0 = A

        repeated element will become 0
        and 0 ^ uniqueEle = uniqueEle
    */

    for(int index = 0; index < n; index++) {
        ans ^= arr[index];
    }
    

    return ans ? ans : -1; // Placeholder return value
}

int main() {
    vector<int> arr = {2, 3, 4, 4, 5, 3, 2}; // Example array

    int uniqueElement = findUniqueElement(arr); // Call the function

    cout << "The unique element is: " << uniqueElement << endl;

    return 0;
}
