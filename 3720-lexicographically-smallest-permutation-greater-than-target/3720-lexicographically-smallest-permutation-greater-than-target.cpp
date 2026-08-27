#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cur(26, 0);
        for (char c : s) cur[c - 'a']++;

        int bestI = -1;
        char bestChar = 0;
        vector<int> bestCnt;

        for (int i = 0; i < n; i++) {
            int tc = target[i] - 'a';

            // Try to find the smallest available char strictly greater than target[i]
            for (int c = tc + 1; c < 26; c++) {
                if (cur[c] > 0) {
                    bestI = i;
                    bestChar = 'a' + c;
                    bestCnt = cur;
                    bestCnt[c]--;
                    break;
                }
            }

            // Try to extend the exact-match prefix
            if (cur[tc] > 0) {
                cur[tc]--;
            } else {
                break;
            }
        }

        if (bestI == -1) return "";

        string result = target.substr(0, bestI);
        result += bestChar;
        for (int c = 0; c < 26; c++) {
            result += string(bestCnt[c], 'a' + c);
        }
        return result;
    }
};