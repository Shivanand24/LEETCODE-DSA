class Solution {
public:
    bool uniformArray(vector<int>& nums1) {  // ✅ changed name
        int odd_count = 0;
        
        for (int x : nums1) {
            if (x % 2 != 0) odd_count++;
        }
        
        bool all_odd_possible  = odd_count >= 1;
        bool all_even_possible = (odd_count == 0) || (odd_count >= 2);
        
        return all_odd_possible || all_even_possible;
    }
};