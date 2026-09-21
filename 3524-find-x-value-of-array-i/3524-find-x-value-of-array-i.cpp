class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> ndp(k, 0);

            int x = num % k;

            // Start a new subarray
            ndp[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0)
                    continue;

                int newRemainder = (1LL * r * x) % k;
                ndp[newRemainder] += dp[r];
            }

            // Add subarrays ending at this position
            for (int r = 0; r < k; r++) {
                result[r] += ndp[r];
            }

            dp = ndp;
        }

        return result;
    }
};