#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it's possible to place cows with a given minimum distance
bool canPlaceCows(const vector<int>& stalls, int numCows, int minDist) {
    int count = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            count++; // Place a cow in the current stall
            lastPosition = stalls[i];
            if (count == numCows) {
                return true;
            }
        }
    }

    return false; // Not possible to place all cows with the given minDist
}

// Function to find the largest minimum distance for placing cows
int aggressiveCows(const vector<int>& stalls, int numCows) {
    vector<int> sortedStalls = stalls;
    sort(sortedStalls.begin(), sortedStalls.end()); // Sort the stall positions

    int start = 1; // Minimum possible distance
    int end = sortedStalls.back() - sortedStalls.front(); // Maximum possible distance
    int result = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (canPlaceCows(sortedStalls, numCows, mid)) {
            result = mid; // Update the result as we want the largest minimum distance
            start = mid + 1; // Try for a larger distance
        } else {
            end = mid - 1; // Try for a smaller distance
        }
    }

    return result;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; // Example stall positions
    int numCows = 3; // Number of cows to place

    int result = aggressiveCows(stalls, numCows); // Call the function

    cout << "The largest minimum distance between cows is: " << result << endl;

    return 0;
}
