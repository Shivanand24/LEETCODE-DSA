class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Group reserved seats by row
        unordered_map<int, unordered_set<int>> reserved;
        for (auto& seat : reservedSeats)
            reserved[seat[0]].insert(seat[1]);

        // Check if a block is free in a given row's reserved set
        auto blockFree = [&](unordered_set<int>& seats, vector<int> block) {
            for (int s : block)
                if (seats.count(s)) return false;
            return true;
        };

        vector<int> left  = {2, 3, 4, 5};
        vector<int> mid   = {4, 5, 6, 7};
        vector<int> right = {6, 7, 8, 9};

        int ans = 0;

        // Rows with no reservations: always fit 2 groups
        int reservedRows = reserved.size();
        ans += 2 * (n - reservedRows);

        // Handle rows with reservations individually
        for (auto& [row, seats] : reserved) {
            bool L = blockFree(seats, left);
            bool M = blockFree(seats, mid);
            bool R = blockFree(seats, right);

            if (L && R) {
                ans += 2;           // both sides fit
            } else if (L || M || R) {
                ans += 1;           // at least one block fits
            }
            // else 0 groups in this row
        }

        return ans;
    }
};