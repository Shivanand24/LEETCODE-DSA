class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        // Build graph
        for (auto &x : invocations) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
        }

        // Find suspicious methods
        vector<bool> suspicious(n, false);

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // Check if an outside method calls a suspicious method
        for (auto &x : invocations) {
            int u = x[0];
            int v = x[1];

            if (!suspicious[u] && suspicious[v]) {

                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};