class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0=0, c1=0, c2=0;
        for (int s : stones) {
            int r = s % 3;
            if (r == 0) c0++;
            else if (r == 1) c1++;
            else c2++;
        }

        if (c0 % 2 == 0) {
            // c0 even: Alice wins only if BOTH c1 and c2 are non-zero
            return c1 != 0 && c2 != 0;
        } else {
            // c0 odd: Alice wins if |c1 - c2| > 2
            return abs(c1 - c2) > 2;
        }
    }
};