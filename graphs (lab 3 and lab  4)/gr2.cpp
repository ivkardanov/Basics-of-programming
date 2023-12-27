#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

bool containsNearbyAlmostDuplicate(const vector<int>& nums, int indexDiff, int valueDiff) {
    if (nums.size() <= 1) {
        return false;
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < min(static_cast<int>(nums.size()), i + indexDiff + 1); ++j) {
            if (abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    string choice;
    do {
        const vector<int> nums1 = { 1,2,3,1 };
        int indexDiff1 = 3;
        int valueDiff1 = 0;

        const vector<int> nums2 = { 1,5,9,1,5,9 };
        int indexDiff2 = 2;
        int valueDiff2 = 3;

        cout << boolalpha << containsNearbyAlmostDuplicate(nums1, indexDiff1, valueDiff1) << endl; // true
        cout << boolalpha << containsNearbyAlmostDuplicate(nums2, indexDiff2, valueDiff2) << endl; // false

        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");
    return 0;
}

