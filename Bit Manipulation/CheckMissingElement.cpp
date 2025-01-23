#include <iostream>
#include <vector>
using namespace std;

int checkMissingElement(vector<int> nums) {
    int n = nums.size();
    int ans = 0;
    for(int index=0; index<n; index++) {
        ans ^= index;
        ans ^= nums[index];
    }
    return ans ^= n;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10};
    int res = checkMissingElement(nums);
    cout << "Missing Element is: " << res << endl;
    return 0;
}