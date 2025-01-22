#include <iostream>
#include <vector>
using namespace std;

// Binary Search Function (Corrected Implementation)
int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Correct formula for mid
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            left = mid + 1;  // Move the left boundary up
        } else {
            right = mid - 1; // Move the right boundary down
        }
    }
    return -1;  // Element not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    int left = 0;
    int right = arr.size() - 1;
    
    int result = binarySearch(arr, left, right, target);
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
