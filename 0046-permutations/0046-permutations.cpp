class Solution {
public:

    void getPerms(vector<int>& nums, int idx, int n ,vector<vector<int>>& ans) {

        // Base case
        if (idx == n) {
            ans.push_back(nums);
            return;
        }

        // Try every element from idx to end
        for (int i = idx; i < nums.size(); i++) {

            // Choose
            swap(nums[idx], nums[i]);

            // Explore
            getPerms(nums , idx + 1, n, ans);

            // Backtrack / Undo
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        int idx = 0;

        int n = nums.size();

        getPerms(nums, idx, n , ans);

        return ans;
    }
};