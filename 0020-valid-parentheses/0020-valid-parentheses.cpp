class Solution {
public:
    bool isValid(string s) {

        stack<char> a;

        for (int i = 0; i < s.size(); i++) {

            if (a.empty()) {
                a.push(s[i]);
                continue;
            }

            if (a.top() == '(' && s[i] == ')') {
                a.pop();
            }
            else if (a.top() == '[' && s[i] == ']') {
                a.pop();
            }
            else if (a.top() == '{' && s[i] == '}') {
                a.pop();
            }
            else {
                a.push(s[i]);
            }
        }

        return a.empty();
    }
};