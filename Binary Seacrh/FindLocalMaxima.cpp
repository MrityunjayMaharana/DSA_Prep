#include <iostream>
#include <vector>
using namespace std;

// Function to find a local maximum in an array
int findLocalMaxima(const vector<int>& arr) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check boundary conditions for local maxima
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
            (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            return mid; // Local maxima found
        }

        // Move to the side with a larger neighbor
        if (mid > 0 && arr[mid - 1] > arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1; // No local maxima found (should not occur in a valid input)
}

int main() {
    vector<int> arr = {1, 3, 20, 21, 22, 21, 4, 1, 0}; // Example array

    int localMaxima = findLocalMaxima(arr); // Call the function

    if (localMaxima != -1) {
        cout << "A local maxima is at index " << localMaxima << " with value " << arr[localMaxima] << endl;
    } else {
        cout << "No local maxima found." << endl;
    }

    return 0;
}
