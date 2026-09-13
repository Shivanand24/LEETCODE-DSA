#include <vector>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> pts1, pts2;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) pts1.push_back({r, c});
                if (img2[r][c] == 1) pts2.push_back({r, c});
            }
        }

        // Offset ranges from -(n-1) to (n-1). Shift by n to make indices non-negative.
        std::vector<std::vector<int>> count(2 * n + 1, std::vector<int>(2 * n + 1, 0));
        int max_overlap = 0;

        for (const auto& p1 : pts1) {
            for (const auto& p2 : pts2) {
                int dr = p2.first - p1.first + n;
                int dc = p2.second - p1.second + n;
                count[dr][dc]++;
                max_overlap = std::max(max_overlap, count[dr][dc]);
            }
        }

        return max_overlap;
    }
};