class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cntDiv[d] = numbers divisible by d
        vector<long long> cntDiv(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cntDiv[d] += freq[m];
        }

        // exactPairs[d] = pairs whose gcd is exactly d
        vector<long long> exactPairs(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long c = cntDiv[d];
            long long pairs = c * (c - 1) / 2;

            for (int m = d + d; m <= mx; m += d)
                pairs -= exactPairs[m];

            exactPairs[d] = pairs;
        }

        // prefix[g] = number of gcd values <= g
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + exactPairs[i];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};