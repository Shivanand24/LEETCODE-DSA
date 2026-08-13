class Solution {
    struct Node {
        int len, pref, suf, ans;
        char lChar, rChar;
    };

    Node combine(const Node& L, const Node& R) {
        Node res;
        res.len   = L.len + R.len;
        res.lChar = L.lChar;
        res.rChar = R.rChar;

        // prefix: all of L, plus R's prefix if L is uniform and chars match
        res.pref = L.pref;
        if (L.pref == L.len && L.rChar == R.lChar)
            res.pref += R.pref;

        // suffix: all of R, plus L's suffix if R is uniform and chars match
        res.suf = R.suf;
        if (R.suf == R.len && R.lChar == L.rChar)
            res.suf += L.suf;

        // answer: best within L, best within R, or bridge across the boundary
        res.ans = max(L.ans, R.ans);
        if (L.rChar == R.lChar)
            res.ans = max(res.ans, L.suf + R.pref);

        return res;
    }

    vector<Node> tree;
    string s;
    int n;

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = {1, 1, 1, 1, c, c};
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, c);
        else            update(2*node+1, mid+1, r, idx, c);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        n = s.size();
        tree.resize(4 * n);

        build(1, 0, n-1);

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int i = 0; i < k; i++) {
            update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].ans;
        }

        return ans;
    }
};