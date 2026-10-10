class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        long long total = 0;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxi = max(maxi, diff[i]);
        }

        if (k >= total) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid) {
                    need += x - mid;
                }
            }

            if (need <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int level = low;
        long long need = 0;
        long long ans = 0;

        for (int x : diff) {
            if (x > level) {
                need += x - level;
                x = level;
            }
            ans += 1LL * x * x;
        }

        long long remaining = k - need;

        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] >= level && level > 0) {
                ans -= 2LL * level - 1;
                remaining--;
            }
        }

        return ans;
    }
};