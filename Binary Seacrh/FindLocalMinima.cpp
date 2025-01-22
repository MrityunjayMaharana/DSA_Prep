#include <iostream>
#include <vector>
using namespace std;

// Function to find a local minimum in an array
int findLocalMinima(const vector<int>& arr) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check boundary conditions for local minima
        if ((mid == 0 || arr[mid] <= arr[mid - 1]) && 
            (mid == n - 1 || arr[mid] <= arr[mid + 1])) {
            return mid; // Local minima found
        }

        // Move to the side with a smaller neighbor
        if (mid > 0 && arr[mid - 1] < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1; // No local minima found (should not occur in a valid input)
}

int main() {
    vector<int> arr = {9, 7, 2, 8, 5, 1}; // Example array

    int localMinima = findLocalMinima(arr); // Call the function

    if (localMinima != -1) {
        cout << "A local minima is at index " << localMinima << " with value " << arr[localMinima] << endl;
    } else {
        cout << "No local minima found." << endl;
    }

    return 0;
}
