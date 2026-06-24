class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using Matrix = vector<vector<ll>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<ll>(n, 0));

        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp) {
            if (exp & 1) res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        // Base case: length = 2
        vector<ll> base(2 * m, 0);

        for (int x = 0; x < m; x++) {
            // up[2][x]
            base[x] = x;

            // down[2][x]
            base[m + x] = (m - x - 1);
        }

        // Transition matrix
        Matrix T(2 * m, vector<ll>(2 * m, 0));

        for (int x = 0; x < m; x++) {
            // up[x] = sum of down[y] where y < x
            for (int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            // down[x] = sum of up[y] where y > x
            for (int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        // Need (n-2) transitions
        Matrix P = power(T, n - 2);

        vector<ll> ans(2 * m, 0);

        for (int i = 0; i < 2 * m; i++) {
            for (int j = 0; j < 2 * m; j++) {
                ans[i] = (ans[i] + P[i][j] * base[j]) % MOD;
            }
        }

        ll res = 0;
        for (ll x : ans) res = (res + x) % MOD;

        return (int)res;
    }
};