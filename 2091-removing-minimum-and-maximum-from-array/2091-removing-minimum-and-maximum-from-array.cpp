#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0;
        int max_idx = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        
        int i = std::min(min_idx, max_idx);
        int j = std::max(min_idx, max_idx);
        
        int opt1 = j + 1;                 // Remove both from the front
        int opt2 = n - i;                 // Remove both from the back
        int opt3 = (i + 1) + (n - j);     // Remove one from the front and one from the back
        
        return std::min({opt1, opt2, opt3});
    }
};