class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int count = 0;  // count evens
        
        for (int x : nums1) {
            if (x % 2 == 0) count++;  // divisible by 2, remainder 0
        }
        
        if (count == (int)nums1.size()) {
            // all even → even - even = even ✓
            return true;
        } else if (count == 0) {
            // all odd → odd stays odd ✓
            return true;
        } else if (count == 1) {
            // 1 even, rest odd → even - odd = odd ✓
            return true;
        } else {
            // 2+ even with odds → odd - odd = even ✓
            return true;
        }
    }
};