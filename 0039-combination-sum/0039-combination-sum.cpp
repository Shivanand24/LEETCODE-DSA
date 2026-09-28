class Solution {
public:

    vector<vector<int>> combinationSum(vector<int>& array, int target) {

        vector<int> temp;
        vector<vector<int>> ans;

        int n = array.size();
        int sum = 0;
        int idx = 0;

        fun(array, idx, temp, ans, sum, target, n);

        return ans;
    }

    void fun(vector<int>& array, int idx, vector<int>& temp,
             vector<vector<int>>& ans, int sum, int target, int n) {

        // Base case
        if (idx == n) {

            if (sum == target) {
                ans.push_back(temp);
            }

            return;
        }

        // Don't take current element
        fun(array, idx + 1, temp, ans, sum, target, n);

        // Take current element
        if (sum + array[idx] <= target) {

            temp.push_back(array[idx]);

            sum = sum + array[idx];

            // idx remains same because we can reuse the element
            fun(array, idx, temp, ans, sum, target, n);

            // Backtrack
            temp.pop_back();

            sum = sum - array[idx];
        }
    }
};