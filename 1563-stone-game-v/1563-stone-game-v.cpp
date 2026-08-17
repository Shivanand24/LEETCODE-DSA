class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // prefix sum for range sum queries
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stoneValue[i];
        
        auto rangeSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };
        
        // dp[i][j] = max score from subarray [i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // fill by increasing length
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // try every split: left=[i..k], right=[k+1..j]
                for (int k = i; k < j; k++) {
                    int leftSum  = rangeSum(i, k);
                    int rightSum = rangeSum(k + 1, j);
                    
                    if (leftSum < rightSum) {
                        // Bob throws right, Alice keeps left
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        // Bob throws left, Alice keeps right
                        dp[i][j] = max(dp[i][j], rightSum + dp[k+1][j]);
                    } else {
                        // Equal: Alice chooses whichever gives more score
                        dp[i][j] = max(dp[i][j], 
                                       max(leftSum  + dp[i][k],
                                           rightSum + dp[k+1][j]));
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};