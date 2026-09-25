class Solution {
public:

    set<string> parse(string &s, int &i) {

        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {

            set<string> cur;

            if (s[i] == '{') {

                i++;

                cur = parse(s, i);

                i++;
            }
            else if (s[i] == ',') {

                i++;

                // Union happens here
                set<string> next = parse(s, i);

                result.insert(next.begin(), next.end());

                continue;
            }
            else {

                cur.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : result) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            result = temp;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};