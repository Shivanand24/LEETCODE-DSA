class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a;
        a.reserve(n);
        for (int i = 0; i < n; i++) a.push_back({nums[i], i});
        sort(a.begin(), a.end());

        vector<int> val(n);
        vector<int> firstPos(n), lastPos(n);

        for (int i = 0; i < n; i++) val[i] = a[i].first;

        // first/last occurrence of each value
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && val[j + 1] == val[i]) j++;
            for (int k = i; k <= j; k++) {
                firstPos[a[k].second] = i;
                lastPos[a[k].second] = j;
            }
            i = j + 1;
        }

        int LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        // right jumps
        vector<vector<int>> upR(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int p = upper_bound(val.begin(), val.end(), val[i] + maxDiff) - val.begin() - 1;
            upR[0][i] = p;
        }
        for (int b = 1; b < LOG; b++)
            for (int i = 0; i < n; i++)
                upR[b][i] = upR[b - 1][upR[b - 1][i]];

        // left jumps
        vector<vector<int>> upL(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int p = lower_bound(val.begin(), val.end(), val[i] - maxDiff) - val.begin();
            upL[0][i] = p;
        }
        for (int b = 1; b < LOG; b++)
            for (int i = 0; i < n; i++)
                upL[b][i] = upL[b - 1][upL[b - 1][i]];

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (nums[u] == nums[v]) {
                ans.push_back(u == v ? 0 : 1);
                continue;
            }

            if (nums[u] < nums[v]) {
                int cur = lastPos[u];
                int target = nums[v];
                int steps = 0;

                for (int b = LOG - 1; b >= 0; b--) {
                    int nxt = upR[b][cur];
                    if (nxt != cur && val[nxt] < target) {
                        cur = nxt;
                        steps += 1 << b;
                    }
                }

                if (val[cur] >= target) {
                    ans.push_back(steps);
                } else if (upR[0][cur] == cur) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(steps + 1);
                }
            } else {
                int cur = firstPos[u];
                int target = nums[v];
                int steps = 0;

                for (int b = LOG - 1; b >= 0; b--) {
                    int nxt = upL[b][cur];
                    if (nxt != cur && val[nxt] > target) {
                        cur = nxt;
                        steps += 1 << b;
                    }
                }

                if (val[cur] <= target) {
                    ans.push_back(steps);
                } else if (upL[0][cur] == cur) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(steps + 1);
                }
            }
        }

        return ans;
    }
};