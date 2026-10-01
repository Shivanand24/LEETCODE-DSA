class Solution {
public:

    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {

        // Base case
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // Try every element from idx to end
        for (int i = idx; i < nums.size(); i++) {

            // Choose
            swap(nums[idx], nums[i]);

            // Explore
            getPerms(nums, idx + 1, ans);

            // Backtrack / Undo
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int idx = 0;

        getPerms(nums, idx, ans);

        return ans;
    }
};