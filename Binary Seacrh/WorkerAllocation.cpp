#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the number of workers required for a given maximum workload
int allocatedWorker(const vector<int>& tasks, int maxWorkload) {
    int workers = 1; // Start with one worker
    int currentWorkload = 0;

    for (int task : tasks) {
        if (currentWorkload + task > maxWorkload) {
            workers++; // Assign a new worker
            currentWorkload = task; // Start new worker's workload with this task
        } else {
            currentWorkload += task; // Add task to current worker's workload
        }
    }

    return workers;
}

// Function to allocate workers to tasks
vector<int> allocateWorkers(const vector<int>& tasks, int numWorkers) {
    int totalWorkload = 0;
    int maxTask = 0;

    // Calculate the total workload and find the maximum task
    for (int task : tasks) {
        totalWorkload += task;
        maxTask = max(maxTask, task);
    }

    // Binary search for the minimum maximum workload
    int start = maxTask; // Minimum possible workload is the largest task
    int end = totalWorkload; // Maximum possible workload is the sum of all tasks
    int optimalWorkload = totalWorkload;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int totalWorkers = allocatedWorker(tasks, mid);

        if (totalWorkers <= numWorkers) {
            optimalWorkload = mid; // Try for a smaller maximum workload
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    // Allocate tasks to workers based on the optimal workload
    vector<int> result;
    int currentWorkload = 0;
    for (int task : tasks) {
        if (currentWorkload + task > optimalWorkload) {
            result.push_back(currentWorkload); // Save current worker's workload
            currentWorkload = task; // Start a new workload
        } else {
            currentWorkload += task;
        }
    }
    result.push_back(currentWorkload); // Add the last worker's workload

    return result;
}

int main() {
    vector<int> tasks = {10, 15, 20, 25, 30}; // Example task durations
    int numWorkers = 3; // Number of workers available

    vector<int> allocation = allocateWorkers(tasks, numWorkers); // Call the function

    cout << "Worker allocations:" << endl;
    for (int i = 0; i < allocation.size(); ++i) {
        cout << "Worker " << i + 1 << ": " << allocation[i] << endl;
    }

    return 0;
}
