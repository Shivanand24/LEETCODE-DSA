#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void fun(string& s, int n, int idx, string& temp,
             vector<string>& res,
             unordered_map<char, string>& f) {

        if (idx == n) {
            res.push_back(temp);
            return;
        }

        string choice = f[s[idx]];

        for (int j = 0; j < choice.size(); j++) {

            temp.push_back(choice[j]);

            fun(s, n, idx + 1, temp, res, f);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string s) {

        unordered_map<char, string> f;

        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int n = s.size();
        int idx = 0;

        string temp = "";
        vector<string> res;

        

        fun(s, n, idx, temp, res, f);

        return res;
    }
};