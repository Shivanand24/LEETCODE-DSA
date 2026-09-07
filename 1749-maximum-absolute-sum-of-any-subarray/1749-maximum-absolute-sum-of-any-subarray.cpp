class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int maxSum = 0;
        int minSum = 0;
        int maxAns = 0;

        for (int i = 0; i < nums.size(); i++) {

            maxSum = max(nums[i], maxSum + nums[i]);
            minSum = min(nums[i], minSum + nums[i]);

            maxAns = max(maxAns, maxSum);
            maxAns = max(maxAns, abs(minSum));
        }

        return maxAns;
    }
};