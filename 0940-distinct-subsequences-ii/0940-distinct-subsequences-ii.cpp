class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        // dp = count including empty subsequence
        long long dp = 1;
        
        // last[c] = value of dp before we last processed char c
        long long last[26] = {0};
        
        for (char c : s) {
            long long prev = dp;
            dp = (2 * dp % MOD - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = prev;
        }
        
        // subtract 1 for empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};