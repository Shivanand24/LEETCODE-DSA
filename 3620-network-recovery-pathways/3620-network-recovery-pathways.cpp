class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> g(n);
        vector<int> indeg(n, 0);
        int mx = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            g[u].push_back({v, c});
            indeg[v]++;
            mx = max(mx, c);
        }

        // Topological sort
        vector<int> topo;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &it : g[u]) {
                int v = it.first;
                if (--indeg[v] == 0) q.push(v);
            }
        }

        auto can = [&](int x) {
            vector<ll> dp(n, INF);
            dp[0] = 0;

            for (int u : topo) {
                if (dp[u] == INF) continue;

                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &it : g[u]) {
                    int v = it.first;
                    int c = it.second;

                    if (c < x) continue;
                    if (v != n - 1 && !online[v]) continue;

                    dp[v] = min(dp[v], dp[u] + (ll)c);
                }
            }

            return dp[n - 1] <= k;
        };

        int l = 0, r = mx, ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (can(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};