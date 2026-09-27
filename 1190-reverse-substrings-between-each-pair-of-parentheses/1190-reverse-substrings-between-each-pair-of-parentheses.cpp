class Solution {
public:
    string reverseParentheses(string s) {

        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                // Save the string before '('
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {

                // Reverse the current substring
                reverse(curr.begin(), curr.end());

                // Get the string before '('
                string prev = st.top();
                st.pop();

                // Combine them
                curr = prev + curr;
            }
            else {

                // Normal character
                curr += ch;
            }
        }

        return curr;
    }
};