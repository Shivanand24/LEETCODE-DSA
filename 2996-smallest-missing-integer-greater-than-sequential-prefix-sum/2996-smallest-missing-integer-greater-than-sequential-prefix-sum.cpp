class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: find longest sequential prefix sum
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) break;
            sum += nums[i];
        }

        // Step 2: collect all nums into a set
        unordered_set<int> seen(nums.begin(), nums.end());

        // Step 3: find smallest missing integer >= sum
        while (seen.count(sum)) sum++;

        return sum;
    }
};