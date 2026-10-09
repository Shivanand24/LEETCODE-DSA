class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // We found ')'

                // Need another ')' to make '))'
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    // We have a complete '))'
                    if (open > 0) {
                        open--;
                    }
                    else {
                        // No '(' available, insert '('
                        ans++;
                    }

                    i++; // consume the second ')'
                }
                else {
                    // Only one ')' exists.
                    // Insert another ')'
                    ans++;

                    if (open > 0) {
                        open--;
                    }
                    else {
                        // No '(' available, insert '('
                        ans++;
                    }
                }
            }
        }

        // Every remaining '(' needs '))'
        ans += open * 2;

        return ans;
    }
};