#include <iostream>
#include <vector>
using namespace std;

// Function to find the first occurrence of a target in a sorted array
int findFirstOccurrence(const vector<int>& arr, int target) {
    // Function implementation goes here
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while(start <= end) {
        int mid = start + (end - start);
        if(arr[mid] == target) {
            ans = mid;
            end = mid - 1;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans; // Placeholder return value
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5}; // Example sorted array
    int target = 2; // Example target value

    int index = findFirstOccurrence(arr, target); // Call the function

    if (index != -1) {
        cout << "First occurrence of " << target << " is at index " << index << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}
