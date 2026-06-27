#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2 ? freq[1] : freq[1] - 1));
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (freq[cur] >= 2) {
                // Check next square
                if (cur > 1000000000LL / cur) break;
                long long nxt = cur * cur;

                if (freq.count(nxt)) {
                    len += 2;
                    cur = nxt;
                } else {
                    break;
                }
            }

            // Current element can be center
            if (freq[cur] >= 1) len++;

            ans = max(ans, len);
        }

        return ans;
    }
};