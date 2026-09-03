class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = *min_element(nums1.begin(), nums1.end());
        int min_parity = min_val % 2;  // 0=even, 1=odd

        // check if ALL elements can be odd
        bool all_odd = true;
        for (int x : nums1) {
            // x can be odd if:
            // x itself is odd OR x-min is odd
            bool x_odd  = (x % 2 != 0);
            bool sub_odd = ((x - min_val) % 2 != 0) && (x != min_val);
            if (!x_odd && !sub_odd) {
                all_odd = false;
                break;
            }
        }

        // check if ALL elements can be even
        bool all_even = true;
        for (int x : nums1) {
            // x can be even if:
            // x itself is even OR x-min is even
            bool x_even  = (x % 2 == 0);
            bool sub_even = ((x - min_val) % 2 == 0) && (x != min_val);
            if (!x_even && !sub_even) {
                all_even = false;
                break;
            }
        }

        return all_odd || all_even;
    }
};