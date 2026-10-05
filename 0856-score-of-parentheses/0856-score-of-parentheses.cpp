class Solution {
public:
    int scoreOfParentheses(string s) {

        stack<int> st;
        st.push(0);

        for (char c : s) {

            if (c == '(') {
                st.push(0);
            }
            else {
                int val = st.top();
                st.pop();

                if (val == 0) {
                    val = 1;
                }
                else {
                    val = 2 * val;
                }

                st.top() += val;
            }
        }

        return st.top();
    }
};