class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int m = nums.size() - 1;
        long long max_unit;
        long long min_unit;
        int t;

        // Loop through each possible index i
        for (i = 0; i <= m; i++) {
            // Find max from 0 to i
            max_unit = nums[0];
            for (j = 0; j <= i; j++) {
                max_unit = max(max_unit, (long long)nums[j]);
            }
            
            // Find min from i to m (end of array)
            min_unit = nums[i];
            for (j = i; j <= m; j++) {
                min_unit = min(min_unit, (long long)nums[j]);
            }

            // Calculate instability score
            t = max_unit - min_unit;

            // Check condition and return the first stable index i
            if (t <= k) {
                return i;
            }
        }
        
        return -1;
    }
};