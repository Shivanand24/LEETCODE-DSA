class Solution {
    public boolean sumGame(String num) {
        int n = num.length();
        double ans = 0.0;
        
        // Add expected values for the first half
        for (int i = 0; i < n / 2; ++i) {
            ans += getExpectation(num.charAt(i));
        }
        
        // Subtract expected values for the second half
        for (int i = n / 2; i < n; ++i) {
            ans -= getExpectation(num.charAt(i));
        }
        
        // If the expected difference is not 0, Alice wins
        return ans != 0.0;
    }
    
    private double getExpectation(char c) {
        return c == '?' ? 4.5 : c - '0';
    }
}