#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string lexPalindromicPermutation(std::string s, std::string target) {
        int n = s.length();
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_char = i;
            }
        }

        // A palindrome can have at most one character with an odd frequency
        if (odd_count > 1) {
            return "";
        }

        std::string base_half = "";
        for (int i = 0; i < 26; ++i) {
            base_half.append(count[i] / 2, (char)('a' + i));
        }
        
        char middle = (odd_char != -1) ? (char)('a' + odd_char) : '\0';

        int half_len = n / 2;
        std::string curr(half_len, ' ');
        std::vector<bool> used(base_half.length(), false);
        std::string best = "";

        // Backtracking DFS to find the lexicographically smallest palindrome > target
        auto dfs = [&](auto self, int idx, bool is_greater) -> bool {
            if (idx == half_len) {
                std::string candidate = curr;
                if (middle != '\0') {
                    candidate += middle;
                }
                std::string rev = curr;
                std::reverse(rev.begin(), rev.end());
                candidate += rev;

                if (candidate > target) {
                    best = candidate;
                    return true;
                }
                return false;
            }

            char prev_char = '\0';
            for (size_t i = 0; i < base_half.length(); ++i) {
                if (!used[i]) {
                    char c = base_half[i];
                    if (c == prev_char) continue; // Skip duplicates to avoid redundant work

                    // Pruning: if we aren't strictly greater yet, don't pick a character smaller than target's prefix
                    if (!is_greater && c < target[idx]) {
                        continue;
                    }

                    used[i] = true;
                    curr[idx] = c;
                    prev_char = c;

                    bool next_is_greater = is_greater || (c > target[idx]);
                    if (self(self, idx + 1, next_is_greater)) {
                        return true;
                    }

                    used[i] = false;
                }
            }
            return false;
        };

        dfs(dfs, 0, false);
        return best;
    }
};