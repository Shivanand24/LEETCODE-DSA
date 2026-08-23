class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') rightQ++;
            else rightSum += num[i] - '0';
        }

        // Total ? must be even for Bob to potentially win
        // (if odd, Alice gets last pick and breaks balance)
        if ((leftQ + rightQ) % 2 != 0) return true;

        // Bob's optimal strategy:
        // Pair one left? with one right? → Bob picks 9 for both sides
        // Net change to (leftSum - rightSum) = 9 - 9 = 0, balance maintained
        //
        // But unpaired ?s (when leftQ != rightQ):
        // Extra ?s on left: each contributes +9/2 on average? No —
        // Alice picks maximally (9), Bob counters with 0, net = +4.5 per pair
        // Actually: Alice picks 9 on left (diff +9), Bob picks 9 on left too? No...
        //
        // Correct pairing insight:
        // Each (left?, right?) pair: Alice picks max side, Bob mirrors → net 0
        // Each (left?, left?) pair: Alice picks 9, Bob picks 0 → net +9
        // Each (right?, right?) pair: Alice picks 0, Bob picks 9 → net -9
        //
        // For Bob to win, after all pairs cancel:
        // leftSum - rightSum + (leftQ - rightQ)/2 * 9 == 0
        // => 2*(leftSum - rightSum) + (leftQ - rightQ)*9 == 0

        int diff = leftSum - rightSum;
        // Bob wins if: diff*2 + (leftQ - rightQ)*9 == 0
        // Alice wins otherwise
        return !(2 * diff + (leftQ - rightQ) * 9 == 0);
    }
};