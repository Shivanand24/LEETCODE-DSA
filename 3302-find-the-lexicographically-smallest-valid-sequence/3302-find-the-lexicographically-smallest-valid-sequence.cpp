class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // dp[i] = maximum number of characters from the suffix of word2
        // that can be matched as a subsequence in word1[i...n-1]
        vector<int> dp(n + 1, 0);

        int j = m - 1;

        // Build dp from right to left
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                dp[i]++;
                j--;
            }
        }

        vector<int> ans;

        int i = 0;
        j = 0;

        bool changed = false;

        while (i < n && j < m) {

            // Normal matching character
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else {
                // Try using this position as our ONE allowed mismatch
                //
                // dp[i + 1] tells us how many characters of word2
                // can still be matched after index i.
                if (!changed && dp[i + 1] >= m - j - 1) {
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }

            i++;
        }

        // We couldn't match all characters
        if (j != m) {
            return {};
        }

        return ans;
    }
};