class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for (int n : nums) target += n;
        target -= x;  // we want the longest subarray summing to this

        // Edge case: entire array must be removed
        if (target == 0) return nums.size();

        int n = nums.size();
        int maxLen = -1;
        int windowSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            windowSum += nums[right];

            // Shrink window from left if sum exceeds target
            while (windowSum > target && left <= right) {
                windowSum -= nums[left++];
            }

            if (windowSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};