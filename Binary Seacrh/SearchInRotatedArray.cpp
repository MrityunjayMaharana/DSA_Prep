#include <iostream>
#include <vector>
using namespace std;

// Function to search in a rotated sorted array
int searchInRotatedArray(const vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Check if the mid element is the target
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[start] <= arr[mid]) {
            // Target lies in the left half
            if (target >= arr[start] && target < arr[mid]) {
                end = mid - 1;
            } else { // Target lies in the right half
                start = mid + 1;
            }
        } else { // Right half is sorted
            // Target lies in the right half
            if (target > arr[mid] && target <= arr[end]) {
                start = mid + 1;
            } else { // Target lies in the left half
                end = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array
    int target = 0; // Target element to search for

    int result = searchInRotatedArray(arr, target); // Call the function

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
