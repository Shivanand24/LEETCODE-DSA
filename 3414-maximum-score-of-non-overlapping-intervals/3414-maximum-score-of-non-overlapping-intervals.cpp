#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maximumWeight(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        struct Interval {
            long long l, r, w;
            int idx;
        };
        
        std::vector<Interval> ext(n);
        for (int i = 0; i < n; ++i) {
            ext[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort by end time, then start time, then weight descending, then original index ascending
        std::sort(ext.begin(), ext.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            if (a.l != b.l) return a.l < b.l;
            if (a.w != b.w) return a.w > b.w;
            return a.idx < b.idx;
        });

        std::vector<long long> ends(n);
        for (int i = 0; i < n; ++i) {
            ends[i] = ext[i].r;
        }

        // dp[i][k] stores {score, indices} for up to k intervals from the first i sorted intervals
        std::vector<std::vector<std::pair<long long, std::vector<int>>>> dp(
            n + 1, std::vector<std::pair<long long, std::vector<int>>>(5, {0, {}})
        );

        for (int i = 1; i <= n; ++i) {
            auto curr = ext[i - 1];

            // Carry over previous bests without current interval
            for (int k = 0; k < 5; ++k) {
                dp[i][k] = dp[i - 1][k];
            }

            // Find the last non-overlapping interval using binary search
            auto it = std::lower_bound(ends.begin(), ends.end(), curr.l);
            int j = std::distance(ends.begin(), it);

            for (int k = 1; k < 5; ++k) {
                if (k == 1 || dp[j][k - 1].first > 0) {
                    long long prev_score = dp[j][k - 1].first;
                    const auto& prev_indices = dp[j][k - 1].second;

                    long long new_score = prev_score + curr.w;
                    std::vector<int> new_indices = prev_indices;
                    new_indices.push_back(curr.idx);
                    std::sort(new_indices.begin(), new_indices.end());

                    if (new_score > dp[i][k].first || 
                        (new_score == dp[i][k].first && new_indices < dp[i][k].second)) {
                        dp[i][k] = {new_score, new_indices};
                    }
                }
            }
        }

        long long best_score = -1;
        std::vector<int> best_indices;

        for (int k = 0; k < 5; ++k) {
            long long score = dp[n][k].first;
            const auto& indices = dp[n][k].second;
            if (score > best_score) {
                best_score = score;
                best_indices = indices;
            } else if (score == best_score) {
                if (indices < best_indices) {
                    best_indices = indices;
                }
            }
        }

        return best_indices;
    }
};