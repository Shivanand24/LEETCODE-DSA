class Solution {
public:

    int m, n;
    vector<vector<vector<int>>> dp;

    bool fun(vector<vector<char>>& grid, int i, int j, int balance) {

        // Balance can never be negative
        if (balance < 0) {
            return false;
        }

        // Reached bottom-right
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Already calculated
        if (dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }

        bool ans = false;

        // Move down
        if (i + 1 < m) {

            int newBalance = balance;

            if (grid[i + 1][j] == '(') {
                newBalance++;
            } else {
                newBalance--;
            }

            ans = ans || fun(grid, i + 1, j, newBalance);
        }

        // Move right
        if (j + 1 < n) {

            int newBalance = balance;

            if (grid[i][j + 1] == '(') {
                newBalance++;
            } else {
                newBalance--;
            }

            ans = ans || fun(grid, i, j + 1, newBalance);
        }

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0) {
            return false;
        }

        // First character must be '('
        if (grid[0][0] == ')') {
            return false;
        }

        // Last character must be ')'
        if (grid[m - 1][n - 1] == '(') {
            return false;
        }

        int maxBalance = m + n;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(maxBalance, -1)
            )
        );

        // Starting cell is '('
        return fun(grid, 0, 0, 1);
    }
};