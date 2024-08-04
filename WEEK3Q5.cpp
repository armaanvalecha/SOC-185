#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Combine both arrays
        vector<int> nums = nums1;
        nums.insert(nums.end(), nums2.begin(), nums2.end());

        // Sort the combined array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int medianIndex = n / 2;
        double median;

        // Calculate median
        if (n % 2 == 0) {
            median = (nums[medianIndex] + nums[medianIndex - 1]) / 2.0;
        } else {
            median = nums[medianIndex];
        }

        return median;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.5

    return 0;
}
