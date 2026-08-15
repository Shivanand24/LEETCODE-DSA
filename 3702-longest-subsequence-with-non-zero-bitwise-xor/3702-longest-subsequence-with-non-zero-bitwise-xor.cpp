class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXOR = 0;
        for (int x : nums) totalXOR ^= x;

        // Case 1: full array XOR is non-zero
        if (totalXOR != 0) return n;

        // Case 2: XOR is zero — remove one non-zero element
        // Check if any non-zero element exists
        for (int x : nums) {
            if (x != 0) return n - 1;  // remove this element, XOR becomes x != 0
        }

        // Case 3: all elements are 0, XOR always 0
        return 0;
    }
};