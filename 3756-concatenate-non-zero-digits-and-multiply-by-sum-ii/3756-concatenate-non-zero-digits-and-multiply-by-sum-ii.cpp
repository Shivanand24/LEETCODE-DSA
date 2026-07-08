class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos;
        vector<int> dig;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                dig.push_back(s[i] - '0');
            }
        }

        int k = dig.size();

        vector<long long> pow10(k + 1, 1);
        for (int i = 1; i <= k; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefVal(k + 1, 0);
        vector<long long> prefSum(k + 1, 0);

        for (int i = 0; i < k; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + dig[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + dig[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            if (itL == pos.end() || itL == itR) {
                ans.push_back(0);
                continue;
            }

            int a = itL - pos.begin();
            int b = (itR - pos.begin()) - 1;
            int len = b - a + 1;

            long long x =
                (prefVal[b + 1] - prefVal[a] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[b + 1] - prefSum[a];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};