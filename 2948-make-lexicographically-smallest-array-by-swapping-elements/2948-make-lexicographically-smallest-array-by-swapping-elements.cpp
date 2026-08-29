#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit) {
        int n = nums.size();
        std::vector<std::pair<int, int>> indexed_nums(n);
        for (int i = 0; i < n; ++i) {
            indexed_nums[i] = {nums[i], i};
        }
        
        // Sort elements by their values
        std::sort(indexed_nums.begin(), indexed_nums.end());
        
        std::vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // Group elements where the difference between adjacent sorted elements is <= limit
            while (j < n && (j == i || indexed_nums[j].first - indexed_nums[j - 1].first <= limit)) {
                j++;
            }
            
            std::vector<int> indices;
            std::vector<int> values;
            for (int k = i; k < j; ++k) {
                indices.push_back(indexed_nums[k].second);
                values.push_back(indexed_nums[k].first);
            }
            
            // Sort indices so we can assign the smallest values to the original smaller indices
            std::sort(indices.begin(), indices.end());
            
            for (size_t k = 0; k < indices.size(); ++k) {
                result[indices[k]] = values[k];
            }
            
            i = j;
        }
        
        return result;
    }
};